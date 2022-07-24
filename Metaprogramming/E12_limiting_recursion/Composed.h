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

#ifndef BOQ_COMPOSED_METAPROGRAMMING_H
#define BOQ_COMPOSED_METAPROGRAMMING_H

#include <type_traits>

#include "TypeList.h"

namespace bits_of_q::composed {
// implementation using composition of transform and join functions

//////////////////////////////////// JOIN /////////////////////////////////////

template <typename... LISTS>
struct join;

template <typename... Ts, typename... Us, typename... MORE_LISTS>
struct join<type_list<Ts...>, type_list<Us...>, MORE_LISTS...> : join<type_list<Ts..., Us...>, MORE_LISTS...> {};

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

template <typename... Ts, template <typename> class FUNC>
struct transform<type_list<Ts...>, FUNC> {
	using type = type_list<typename FUNC<Ts>::type...>;
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
template <typename... Ts>
struct join_list_of_lists<type_list<Ts...>> : join<Ts...> {};

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

}  // namespace bits_of_q::composed

#endif