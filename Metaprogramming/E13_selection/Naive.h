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

#ifndef BOQ_NAIVE_METAPROGRAMMING_H
#define BOQ_NAIVE_METAPROGRAMMING_H

#include <type_traits>

#include "TypeList.h"

namespace bits_of_q::naive {

////////////////////////////////// REMOVE_IF //////////////////////////////////

// naive, direct implementation
// Note: for simplicity we only support operating on type_list<...>,
// see episode explanation in 4 or Metaprogramming.h header from earlier
// episodes for tips on how to make these kind of metafunctions work for any
// list-like templates.
template <template <typename> class PREDICATE, typename LIST, typename NEW_LIST = type_list<>>
struct remove_if;

template <template <typename> class PREDICATE, typename T0, typename... T1toN, typename NEW_LIST>
struct remove_if<PREDICATE, type_list<T0, T1toN...>, NEW_LIST>
    : if_<PREDICATE<T0>::value,
          typename remove_if<PREDICATE, type_list<T1toN...>, NEW_LIST>::type,
          typename remove_if<PREDICATE, type_list<T1toN...>, push_back_t<NEW_LIST, T0>>::type> {};

template <template <typename> class PREDICATE, typename NEW_LIST>
struct remove_if<PREDICATE, type_list<>, NEW_LIST> {
	using type = NEW_LIST;
};

// _t template alias for convenience
template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;

}  // namespace bits_of_q::naive

#endif