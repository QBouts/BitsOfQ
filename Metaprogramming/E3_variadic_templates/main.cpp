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

#include <iostream>
#include <tuple>
#include <type_traits>

void printn() {
	std::cout << '\n';
}

template <typename LAST>
void printn(LAST &&t) {
	std::cout << std::forward<LAST>(t) << '\n';
}

template <typename T0, typename... T1toN>
void printn(T0 &&t, T1toN &&...rest) {
	std::cout << std::forward<T0>(t) << ", ";
	printn(std::forward<T1toN>(rest)...);  // printn(std::forward<T1>(rest1), std::forward<T2>(rest2), ...)
}

template <typename TUPLE, std::size_t... indices>
void print_tuple_impl(TUPLE &&t, std::index_sequence<indices...>) {
	printn(std::get<indices>(std::forward<TUPLE>(t))...);  // printn(std::get<0>(t), std::get<1>(t), std::get<2>(t)...);
}

template <typename TUPLE>
void print_tuple(TUPLE &&t) {
	print_tuple_impl(std::forward<TUPLE>(t),
	                 std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
}


int main() {
	std::cout << std::boolalpha;
	printn(9, "hello", 1.5, true);
	printn();
	printn("hello", "world");

	const auto tuple = std::make_tuple(9, "hello", 1.5, true);
	print_tuple(tuple);
}
