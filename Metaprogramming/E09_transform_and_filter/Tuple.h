/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2022 Quirijn Bouts
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#ifndef BOQ_TUPLE_H
#define BOQ_TUPLE_H

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

#include "Metaprogramming.h"

namespace bits_of_q {

template <typename... ELEMS>
struct Tuple {
	constexpr Tuple() = default;
};

template <typename ELEM0, typename... ELEMS1toN>
struct Tuple<ELEM0, ELEMS1toN...> : Tuple<ELEMS1toN...> {
	template <typename T, typename... Ts>
	explicit constexpr Tuple(T&& e1, Ts&&... rest)
	    : Tuple<ELEMS1toN...>(std::forward<Ts>(rest)...)
	    , data(std::forward<T>(e1)) {}
	ELEM0 data;
};

// deduction guide to make template argument deduction for constructors work (C++17)
template <typename T, typename... Ts>
Tuple(T e1, Ts... rest) -> Tuple<std::unwrap_ref_decay_t<T>, std::unwrap_ref_decay_t<Ts>...>;

template <typename... ELEMS>
constexpr auto make_tuple(ELEMS&&... elems) {
	return Tuple<std::unwrap_ref_decay_t<ELEMS>...>{std::forward<ELEMS>(elems)...};
}

////////////////////////////////////////////////////////////
///////////////////////////  get  //////////////////////////
////////////////////////////////////////////////////////////

namespace detail {
template <size_t i, typename TUPLE>
struct get_impl : get_impl<i - 1, pop_front_t<TUPLE>> {};

template <typename TUPLE>
struct get_impl<0, TUPLE> {
	template <typename T>
	constexpr static decltype(auto) get(T&& t) {
		constexpr bool is_lvalue = std::is_lvalue_reference_v<T>;
		constexpr bool is_const = std::is_const_v<std::remove_reference_t<T>>;
		using data_t = front_t<TUPLE>;

		if constexpr (is_lvalue && is_const) {
			return static_cast<const data_t&>(static_cast<const TUPLE&>(t).data);
		}
		if constexpr (is_lvalue && !is_const) {
			return static_cast<data_t&>(static_cast<TUPLE&>(t).data);
		}
		if constexpr (!is_lvalue && is_const) {
			return static_cast<const data_t&&>(static_cast<const TUPLE&&>(t).data);
		}
		if constexpr (!is_lvalue && !is_const) {
			return static_cast<data_t&&>(static_cast<TUPLE&&>(t).data);
		}
	}
};
}  // namespace detail

template <size_t i, typename TUPLE>
constexpr decltype(auto) get(TUPLE&& tuple) {
	return detail::get_impl<i, std::remove_cvref_t<TUPLE>>::get(std::forward<TUPLE>(tuple));
}

////////////////////////////////////////////////////////////
///////////////////////  tuple_size  ///////////////////////
////////////////////////////////////////////////////////////

template <typename TUPLE>
struct tuple_size;
template <typename... ELEMS>
struct tuple_size<Tuple<ELEMS...>> : std::integral_constant<size_t, sizeof...(ELEMS)> {};

template <typename TUPLE>
static constexpr size_t tuple_size_v = tuple_size<TUPLE>::value;

////////////////////////////////////////////////////////////
////////////////////  forward_as_tuple  ////////////////////
////////////////////////////////////////////////////////////

template <typename... Ts>
constexpr auto forward_as_tuple(Ts&&... ts) noexcept {
	return Tuple<Ts&&...>{std::forward<Ts>(ts)...};
}

////////////////////////////////////////////////////////////
///////////////////////  tuple_cat  ////////////////////////
////////////////////////////////////////////////////////////

namespace detail {

template <typename INDEX_SEQ>
struct make_tuple_from_fwd_tuple;

template <size_t... indices>
struct make_tuple_from_fwd_tuple<std::index_sequence<indices...>> {
	template <typename FWD_TUPLE>
	static constexpr auto f(FWD_TUPLE&& fwd) {
		return Tuple{get<indices>(std::forward<FWD_TUPLE>(fwd))...};
	}
};

template <typename FWD_INDEX_SEQ, typename TUPLE_INDEX_SEQ>
struct concat_with_fwd_tuple;

template <size_t... fwd_indices, size_t... indices>
struct concat_with_fwd_tuple<std::index_sequence<fwd_indices...>, std::index_sequence<indices...>> {
	template <typename FWD_TUPLE, typename TUPLE>
	static constexpr auto f(FWD_TUPLE&& fwd, TUPLE&& t) {
		return forward_as_tuple(get<fwd_indices>(std::forward<FWD_TUPLE>(fwd))..., get<indices>(std::forward<TUPLE>(t))...);
	}
};

struct tuple_cat_impl {
	template <typename FWD_TUPLE, typename TUPLE, typename... TUPLES>
	static constexpr auto f(FWD_TUPLE&& fwd, TUPLE&& t, TUPLES&&... ts) {
		return f(concat_with_fwd_tuple<
		             std::make_index_sequence<tuple_size_v<std::remove_cvref_t<FWD_TUPLE>>>,
		             std::make_index_sequence<tuple_size_v<std::remove_cvref_t<TUPLE>>>>::f(std::forward<FWD_TUPLE>(fwd),
		                                                                                    std::forward<TUPLE>(t)),
		         std::forward<TUPLES>(ts)...);
	}

	template <typename FWD_TUPLE>
	static constexpr auto f(FWD_TUPLE&& ret) {
		return make_tuple_from_fwd_tuple<std::make_index_sequence<tuple_size_v<FWD_TUPLE>>>::f(
		    std::forward<FWD_TUPLE>(ret));
	}
};

}  // namespace detail

template <typename... TUPLES>
constexpr auto tuple_cat(TUPLES&&... tuples) {
	return detail::tuple_cat_impl::f(std::forward<TUPLES>(tuples)...);
}

////////////////////////////////////////////////////////////
///////////////////////  transform  ////////////////////////
////////////////////////////////////////////////////////////

namespace detail {
template <typename TUP, typename FUNC, size_t... indices>
constexpr auto transform_impl(TUP&& tup, const FUNC& f, std::index_sequence<indices...>) {
	return Tuple{f(get<indices>(std::forward<TUP>(tup)))...};
}
}  // namespace detail

template <typename TUP, typename FUNC>
constexpr auto transform(TUP&& tup, const FUNC& f) {
	return detail::transform_impl(std::forward<TUP>(tup),
	                              f,
	                              std::make_index_sequence<tuple_size_v<std::remove_cvref_t<TUP>>>{});
}

////////////////////////////////////////////////////////////
/////////////////////////  filter  /////////////////////////
////////////////////////////////////////////////////////////

namespace detail {
template <typename TUP, size_t... indices>
constexpr auto cat_tuple_content(TUP&& t, std::index_sequence<indices...>) {
	return tuple_cat(get<indices>(std::forward<TUP>(t))...);
}
}  // namespace detail

template <template <typename...> class PREDICATE, typename TUP>
constexpr auto filter(TUP&& tup) {
	auto wrap_if_pred_matches = [&]<typename ELEM>(ELEM&& e) {
		if constexpr (PREDICATE<std::remove_cvref_t<ELEM>>::value) {
			return forward_as_tuple(std::forward<ELEM>(e));
		} else {
			return Tuple<>{};
		}
	};
	auto wrapped_tup = transform(std::forward<TUP>(tup), wrap_if_pred_matches);
	// example: Tuple<Tuple<int&>, Tuple<>, Tuple<unsigned&>, Tuple<>>
	return detail::cat_tuple_content(std::move(wrapped_tup),
	                                 std::make_index_sequence<tuple_size_v<std::remove_cvref_t<TUP>>>{});
	// example: Tuple<int, unsigned>
}

}  // namespace bits_of_q

#endif  // BOQ_TUPLE_H
