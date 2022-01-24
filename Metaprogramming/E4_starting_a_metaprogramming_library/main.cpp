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
#include <list>
#include <string>
#include <tuple>
#include <vector>

template <bool condition, typename THEN, typename ELSE>
struct if_;

template <typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> {
	using type = THEN;
};

template <typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> {
	using type = ELSE;
};


template <typename...>
struct type_list {};

template <typename LIST>
struct empty : std::false_type {};

template <>
struct empty<type_list<>> : std::true_type {};

static_assert(empty<type_list<>>::value);
static_assert(!empty<type_list<float>>::value);


template <typename LIST>
struct front;

template <typename T0, typename... T1toN>
struct front<type_list<T0, T1toN...>> {
	using type = T0;
};

static_assert(std::is_same_v<front<type_list<int, bool>>::type, int>);


template <typename LIST>
struct pop_front;

template <typename T0, typename... T1toN>
struct pop_front<type_list<T0, T1toN...>> {
	using type = type_list<T1toN...>;
};

static_assert(std::is_same_v<pop_front<type_list<int, bool, float>>::type, type_list<bool, float>>);

template <typename LIST>
using front_t = typename front<LIST>::type;

template <typename LIST>
using pop_front_t = typename pop_front<LIST>::type;

template <typename LIST>
inline constexpr bool empty_v = empty<LIST>::value;

template <typename SEARCH, typename LIST>
struct contains_type : if_<  // IF
                           std::is_same_v<SEARCH, front_t<LIST>>,
                           // THEN
                           std::true_type,
                           // ELSE
                           contains_type<SEARCH, pop_front_t<LIST>>>::type {};

template <typename SEARCH>
struct contains_type<SEARCH, type_list<>> : std::false_type {};

bool contains(const std::string& search, std::list<std::string> l) {
	if (l.empty()) {
		return false;
	}
	if (search == l.front()) {
		return true;
	}
	l.pop_front();
	return contains(search, l);
}

int main() {
	std::list<std::string> list{"int", "bool", "double"};
	std::cout << std::boolalpha;
	std::cout << contains("bool", list) << '\n';
	std::cout << contains("float", list) << '\n';

	type_list<int, bool, double> types;
	std::cout << contains_type<bool, type_list<>>::value << '\n';
	std::cout << contains_type<bool, decltype(types)>::value << '\n';
	std::cout << contains_type<float, decltype(types)>::value << '\n';
}
