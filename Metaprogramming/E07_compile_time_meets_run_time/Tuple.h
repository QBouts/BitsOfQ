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

//////////////////////////// get ///////////////////////////

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

}  // namespace bits_of_q

#endif  // BOQ_TUPLE_H
