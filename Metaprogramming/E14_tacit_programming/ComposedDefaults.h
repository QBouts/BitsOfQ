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

#ifndef BOQ_COMPOSED_DEFAULTS_METAPROGRAMMING_H
#define BOQ_COMPOSED_DEFAULTS_METAPROGRAMMING_H

#include <type_traits>

#include "TypeList.h"

namespace bits_of_q::composed_defaults {
// implementation using composition of transform and join functions
// speeding up join by using default arguments

//////////////////////////////////// JOIN /////////////////////////////////////

namespace detail {
template <typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>,
          typename = type_list<>>
struct join16;

template <typename... T0s,
          typename... T1s,
          typename... T2s,
          typename... T3s,
          typename... T4s,
          typename... T5s,
          typename... T6s,
          typename... T7s,
          typename... T8s,
          typename... T9s,
          typename... T10s,
          typename... T11s,
          typename... T12s,
          typename... T13s,
          typename... T14s,
          typename... T15s>
struct join16<type_list<T0s...>,
              type_list<T1s...>,
              type_list<T2s...>,
              type_list<T3s...>,
              type_list<T4s...>,
              type_list<T5s...>,
              type_list<T6s...>,
              type_list<T7s...>,
              type_list<T8s...>,
              type_list<T9s...>,
              type_list<T10s...>,
              type_list<T11s...>,
              type_list<T12s...>,
              type_list<T13s...>,
              type_list<T14s...>,
              type_list<T15s...>> {
	using type = type_list<T0s...,
	                       T1s...,
	                       T2s...,
	                       T3s...,
	                       T4s...,
	                       T5s...,
	                       T6s...,
	                       T7s...,
	                       T8s...,
	                       T9s...,
	                       T10s...,
	                       T11s...,
	                       T12s...,
	                       T13s...,
	                       T14s...,
	                       T15s...>;
};
}  // namespace detail

template <typename L0 = type_list<>,
          typename L1 = type_list<>,
          typename L2 = type_list<>,
          typename L3 = type_list<>,
          typename L4 = type_list<>,
          typename L5 = type_list<>,
          typename L6 = type_list<>,
          typename L7 = type_list<>,
          typename L8 = type_list<>,
          typename L9 = type_list<>,
          typename L10 = type_list<>,
          typename L11 = type_list<>,
          typename L12 = type_list<>,
          typename L13 = type_list<>,
          typename L14 = type_list<>,
          typename L15 = type_list<>,
          typename... MORE_LISTS>
struct join {
	using type =
	    typename join<typename detail::join16<L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15>::type,
	                  MORE_LISTS...>::type;
};

template <typename LIST>
struct join<LIST> {
	using type = LIST;
};
template <typename... LISTS>
using join_t = typename join<LISTS...>::type;

// test concatenation of two lists
static_assert(
    std::is_same_v<join_t<type_list<int, bool>, type_list<float, double>>, type_list<int, bool, float, double>>);
// test concatenation involving empty list
static_assert(std::is_same_v<join_t<type_list<>, type_list<int, bool>>, type_list<int, bool>>);
// test concatenation of three lists
static_assert(std::is_same_v<join_t<type_list<int, float>, type_list<int, bool>, type_list<float, double>>,
                             type_list<int, float, int, bool, float, double>>);

///////////////////////////////// TRANSFORM ///////////////////////////////////

template <typename LIST, template <typename> class FUNC>
struct transform;

template <template <typename...> class LIST, typename... Ts, template <typename> class FUNC>
struct transform<LIST<Ts...>, FUNC> {
	using type = LIST<typename FUNC<Ts>::type...>;
};

template <typename LIST, template <typename> class FUNC>
using transform_t = typename transform<LIST, FUNC>::type;

namespace detail {
template <typename T>
struct to_void {
	using type = void;
};
}  // namespace detail

static_assert(std::is_same_v<transform_t<type_list<int, bool, float>, detail::to_void>, type_list<void, void, void>>);


////////////////////////////////// REMOVE_IF //////////////////////////////////

namespace detail {
template <template <typename> class PREDICATE, typename T>
struct wrap_if_not : if_<PREDICATE<T>::value, type_list<>, type_list<T>> {};

template <template <typename> class PREDICATE>
struct wrap_if_not_func {
	template <typename T>
	using func = wrap_if_not<PREDICATE, T>;
};

template <typename LIST_OF_LISTS>
struct join_list_of_lists;
template <template <typename...> class LIST, typename... Ts>
struct join_list_of_lists<LIST<Ts...>> : join<Ts...> {};

template <typename LIST_OF_LISTS>
using join_list_of_lists_t = typename join_list_of_lists<LIST_OF_LISTS>::type;

static_assert(std::is_same_v<join_list_of_lists_t<type_list<type_list<int, bool>, type_list<>, type_list<float>>>,
                             type_list<int, bool, float>>);
}  // namespace detail

template <template <typename> class PREDICATE, typename LIST>
struct remove_if {
	using type = detail::join_list_of_lists_t<transform_t<LIST, detail::wrap_if_not_func<PREDICATE>::template func>>;
};

template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;

}  // namespace bits_of_q::composed_defaults

#endif