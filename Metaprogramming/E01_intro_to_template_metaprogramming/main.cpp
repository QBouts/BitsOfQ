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
#include <type_traits>

template <typename T>
struct is_pointer {
	static constexpr bool value = false;
};

template <typename T>
struct is_pointer<T *> {
	static constexpr bool value = true;
};

template <typename T>
struct strip_pointer {
	using type = T;
};

template <typename T>
struct strip_pointer<T *> {
	using type = T;
};

template <typename T>
void print1(T t) {
	using T_without_pointer = typename strip_pointer<T>::type;
	if constexpr (is_pointer<T>::value && std::is_floating_point<T_without_pointer>::value) {
		std::cout << *t;
	} else {
		std::cout << t;
	}
}

template <typename A, typename B, typename C>
void print3(A a, B b, C c) {
	print1(a);
	std::cout << ", ";
	print1(b);
	std::cout << ", ";
	print1(c);
	std::cout << '\n';
}

int main() {
	print3(1, 2, 3);
	std::string hello = "hello world";
	print3(hello, 2, hello);
	print3(&hello, 2, 3);
	float a = 10;
	double b = 2;
	print3(&hello, &a, &b);
}
