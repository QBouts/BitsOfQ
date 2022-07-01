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

#ifndef BOQ_TESTS_METAPROGRAMMING_H
#define BOQ_TESTS_METAPROGRAMMING_H

#include <tuple>
#include <type_traits>

#include "TypeList.h"

// different implementations
#include "Naive.h"
#include "NaiveLazy.h"

#define remove_if_tests                                                                                             \
	static_assert(std::is_same_v<remove_if_t<std::is_floating_point, type_list<int, bool, float, double, char>>,      \
	                             type_list<int, bool, char>>);                                                        \
                                                                                                                    \
	static_assert(                                                                                                    \
	    std::is_same_v<remove_if_t<std::is_floating_point, type_list<int, bool, char>>, type_list<int, bool, char>>); \
                                                                                                                    \
	static_assert(std::is_same_v<remove_if_t<std::is_floating_point, type_list<float, double, float>>, type_list<>>)

/*
// homework exercise: update the different implementations to allow them to operate on any list-like type, such as the
// std::tuple and make the following static_assert pass.
static_assert(std::is_same_v<remove_if_t<std::is_floating_point, std::tuple<int, bool, float, double, char>>,       \
                               std::tuple<int, bool, char>>);                                                       \
*/


namespace detail {
template <typename T>
struct to_void {
	using type = void;
};
}  // namespace detail

namespace bits_of_q::naive {
remove_if_tests;
}  // namespace bits_of_q::naive

namespace bits_of_q::naive_lazy {
remove_if_tests;
}  // namespace bits_of_q::naive_lazy

// more implementations will follow in the next episodes!
#endif