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


#include <boost/type_index.hpp>

#include "Metaprogramming.h"
#include "TestUtilities.h"
#include "Tuple.h"

using boost::typeindex::type_id_with_cvr;

constexpr size_t boq_tuple = 1;
constexpr size_t std_tuple = 2;
namespace boq = bits_of_q;
using boq::testing::Tester;
using boq::testing::TesterWithBuilder;

int main() {
	using namespace bits_of_q;

	Tester::test("constructor", []() {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		boq::Tuple t1{9, c1, 1.4};
		std::tuple t2{9, c2, 1.4};

		ASSERT(c1 == c2);
	});

	Tester::test("make_tuple", []() {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		make_tuple(8, c1, 1.1);
		std::make_tuple(8, c2, 1.1);

		ASSERT(c1 == c2);
	});


	TesterWithBuilder<1>::test("get", [](auto &&builder) {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		auto &&tuple1 = builder.build(boq::Tuple{42, c1, true});
		auto &&tuple2 = builder.build(std::tuple{42, c2, true});

		auto v1 = get<1>(std::forward<decltype(tuple1)>(tuple1));
		auto v2 = get<1>(std::forward<decltype(tuple2)>(tuple2));
		auto v3 = get<0>(std::forward<decltype(tuple1)>(tuple1));
		auto v4 = get<0>(std::forward<decltype(tuple2)>(tuple2));

		ASSERT(v1 == v2);
		ASSERT(v3 == v4);
	});

	TesterWithBuilder<2>::test("tuple_cat with 2 args", [](auto &&builder) {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		auto &&[boq_tuple1, boq_tuple2] = builder.build(boq::Tuple{42, c1, true}, boq::Tuple{false, c1, 1.2});
		auto &&[std_tuple1, std_tuple2] = builder.build(std::tuple{42, c2, true}, std::tuple{false, c2, 1.2});

		auto boq_t1_2 =
		    tuple_cat(std::forward<decltype(boq_tuple1)>(boq_tuple1), std::forward<decltype(boq_tuple2)>(boq_tuple2));
		auto std_t1_2 =
		    tuple_cat(std::forward<decltype(std_tuple1)>(std_tuple1), std::forward<decltype(std_tuple2)>(std_tuple2));

		static_for<0, tuple_size_v<decltype(boq_t1_2)>>(
		    [&](auto i) { ASSERT(get<i.value>(boq_t1_2) == get<i.value>(std_t1_2)); });
	});

	TesterWithBuilder<3>::test("tuple_cat", [](auto &&builder) {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		auto &&[boq_tuple1, boq_tuple2, boq_tuple3] =
		    builder.build(boq::Tuple{42, c1, true}, boq::Tuple{false, c1, 1.2}, boq::Tuple{7, 'c'});
		auto &&[std_tuple1, std_tuple2, std_tuple3] =
		    builder.build(std::tuple{42, c2, true}, std::tuple{false, c2, 1.2}, std::tuple{7, 'c'});

		auto boq_t1_2_3 = tuple_cat(std::forward<decltype(boq_tuple1)>(boq_tuple1),
		                            std::forward<decltype(boq_tuple2)>(boq_tuple2),
		                            std::forward<decltype(boq_tuple3)>(boq_tuple3));
		auto std_t1_2_3 = tuple_cat(std::forward<decltype(std_tuple1)>(std_tuple1),
		                            std::forward<decltype(std_tuple2)>(std_tuple2),
		                            std::forward<decltype(std_tuple3)>(std_tuple3));


		static_for<0, tuple_size_v<decltype(boq_t1_2_3)>>(
		    [&](auto i) { ASSERT(get<i.value>(boq_t1_2_3) == get<i.value>(std_t1_2_3)); });
	});


	static_assert(tuple_size_v<Tuple<int, bool>> == 2);
	static_assert(tuple_size_v<Tuple<int, bool, float, double>> == 4);
}
