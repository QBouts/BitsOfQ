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
#include <utility>

#include "Metaprogramming.h"
#include "TestUtilities.h"
#include "Tuple.h"

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

		ASSERT_EQ(c1, c2);
	});

	Tester::test("make_tuple", []() {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		[[maybe_unused]] auto &&dummy1 = make_tuple(8, c1, 1.1);
		[[maybe_unused]] auto &&dummy2 = std::make_tuple(8, c2, 1.1);


		ASSERT_EQ(c1, c2);
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

		ASSERT_EQ(v1, v2);
		ASSERT_EQ(v3, v4);
	});

	TesterWithBuilder<2>::test("tuple_cat with 2 args", [](auto &&builder) {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		auto &&[boq_tuple1, boq_tuple2] = builder.build(boq::Tuple{42, c1, true}, boq::Tuple{false, c1, 1.2});
		auto &&[std_tuple1, std_tuple2] = builder.build(std::tuple{42, c2, true}, std::tuple{false, c2, 1.2});

		auto boq_t1_2 =
		    boq::tuple_cat(std::forward<decltype(boq_tuple1)>(boq_tuple1), std::forward<decltype(boq_tuple2)>(boq_tuple2));
		auto std_t1_2 =
		    std::tuple_cat(std::forward<decltype(std_tuple1)>(std_tuple1), std::forward<decltype(std_tuple2)>(std_tuple2));

		static_for<0, tuple_size_v<decltype(boq_t1_2)>>(
		    [&](auto i) { ASSERT_EQ(get<i.value>(boq_t1_2), get<i.value>(std_t1_2)); });
	});

	TesterWithBuilder<2>::test("tuple_cat", [](auto &&builder) {
		auto c1 = make_copy_counter<boq_tuple>();
		auto c2 = make_copy_counter<std_tuple>();

		// varying value category of first and last tuple by constructing them with the builder
		auto &&[boq_tuple1, boq_tuple3] = builder.build(boq::Tuple{42, c1, true}, boq::Tuple{7, 'c'});
		boq::Tuple boq_tuple2{false, c1, 1.2};
		auto &&[std_tuple1, std_tuple3] = builder.build(std::tuple{42, c2, true}, std::tuple{7, 'c'});
		std::tuple std_tuple2{false, c2, 1.2};

		auto boq_t1_2_3 = boq::tuple_cat(std::forward<decltype(boq_tuple1)>(boq_tuple1),
		                                 std::forward<decltype(boq_tuple2)>(boq_tuple2),
		                                 std::forward<decltype(boq_tuple3)>(boq_tuple3));
		auto std_t1_2_3 = std::tuple_cat(std::forward<decltype(std_tuple1)>(std_tuple1),
		                                 std::forward<decltype(std_tuple2)>(std_tuple2),
		                                 std::forward<decltype(std_tuple3)>(std_tuple3));


		static_for<0, tuple_size_v<decltype(boq_t1_2_3)>>(
		    [&](auto i) { ASSERT_EQ(get<i.value>(boq_t1_2_3), get<i.value>(std_t1_2_3)); });
	});


	static_assert(tuple_size_v<Tuple<int, bool>> == 2);
	static_assert(tuple_size_v<Tuple<int, bool, float, double>> == 4);


	TesterWithBuilder<1>::test("tuple_transform", [](auto &&builder) {
		auto c = make_copy_counter<boq_tuple>();

		auto &&tup = builder.build(Tuple{42, c, 12U});
		c.reset();

		auto tup2 = transform(std::forward<decltype(tup)>(tup), []<typename T>(T &&t) {
			constexpr bool is_integral = std::is_integral_v<std::remove_cvref_t<T>>;
			if constexpr (is_integral) {
				return int(t) + 2;
			} else {
				return t.stats;
			}
		});
		// Tuple<int, CopyCounter, unsigned int> => Tuple<int, CopyStats, int>
		// Tuple{42, c, 12U} => Tuple{44, c.stats, 14}

		static_assert(std::is_same_v<std::remove_cvref_t<decltype(tup2)>, Tuple<int, CopyStats, int>>);
		ASSERT_EQ(get<0>(tup2), 44);
		ASSERT_EQ(get<1>(tup2), (CopyStats{0, 0, 0}));
		ASSERT_EQ(get<2>(tup2), 14);
	});

	TesterWithBuilder<1>::test("tuple_filter", [](auto &&builder) {
		auto c = make_copy_counter<boq_tuple>();

		auto &&tup = builder.build(Tuple{42, 2.3F, c, 3.4, 12U});
		c.reset();

		auto tup2 = filter<std::is_integral>(std::forward<decltype(tup)>(tup));

		static_assert(std::is_same_v<std::remove_cvref_t<decltype(tup2)>, Tuple<int, unsigned int>>);
		ASSERT_EQ(get<0>(tup2), 42);
		ASSERT_EQ(get<1>(tup2), 12);
		ASSERT_EQ(c.stats, (CopyStats{0, 0, 0}));
	});

	TesterWithBuilder<1>::test("tuple_filter2", [](auto &&builder) {
		auto c = make_copy_counter<boq_tuple>();
		static constexpr size_t ref_tuple = 3;
		auto c2 = make_copy_counter<ref_tuple>();

		auto &&tup = builder.build(Tuple{42, 2.3F, c, 3.4, 12U});
		auto &&ref_tup = builder.build(Tuple{42, 2.3F, c2, 3.4, 12U});

		auto tup2 = filter<boq::not_<std::is_integral>::type>(std::forward<decltype(tup)>(tup));
		auto ref_tup2 = std::forward<decltype(ref_tup)>(ref_tup);

		static_assert(
		    std::is_same_v<std::remove_cvref_t<decltype(tup2)>, Tuple<float, IndexedCopyCounter<boq_tuple>, double>>);
		ASSERT_EQ(get<0>(tup2), 2.3F);
		ASSERT_EQ(get<1>(tup2), get<2>(ref_tup2));
		ASSERT_EQ(get<2>(tup2), 3.4);
	});


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                                                                                                              //
	//  Homework exercise: Update filter to make it work correctly with references! (solution available on github). //
	//  It is recommended to make the tests below pass one by one, they will guide you through the needed changes.  //
	//                                                                                                              //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Homework step 1: Update filter so the predicate is executed with the correct type.
	// In the current implementation we use the transform function to pass the elements to a lambda. This has the inherent
	// problem that the lambda is unable to distinguish whether the element type is a value or a lvalue reference.
	//
	// Hint: add a tuple_element_t alias using the at function from Metaprogramming.h. Instead of using transform, create
	// a similar function that executes the predicate on the tuple_element_t at each index instead of using the decltype
	// of the passed element.
	Tester::test("tuple_filter_pred_passed_correct_types", []() {
		int i = 10;
		Tuple<int, int &, int> tup{4, i, 11};

		auto tup2 = filter<boq::not_<std::is_reference>::type>(std::forward<decltype(tup)>(tup));
		// static_assert(std::is_same_v<decltype(tup2), Tuple<int, int>>);
		ASSERT((std::is_same_v<decltype(tup2), Tuple<int, int>>));
	});

	// Homework: step 2. Create a tuple_cat_result_t metafunction in the detail namespace to help to determine the
	// expected output type of a tuple_cat operation on two tuples
	// Hint: This is similar to the push_back operation from Metaprogramming.h, only difference is that we "push_back" the
	// elements of the second tuple, not the whole tuple
	Tester::test("tuple_cat_result_2_inputs", []() {
		// static_assert(std::is_same_v<detail::tuple_cat_result_t<Tuple<int, int &, int>, Tuple<int &&>>,
		//                            Tuple<int, int &, int, int &&>>);
	});

	// Homework: step 3. Update tuple_cat_result_t metafunction to handle more than 2 inputs
	// Hint: Recursion should do the trick
	Tester::test("tuple_cat_result", []() {
		// static_assert(
		//    std::is_same_v<detail::tuple_cat_result_t<Tuple<double &, double>, Tuple<int, int &, int>, Tuple<int &&>>,
		//                   Tuple<double &, double, int, int &, int, int &&>>);
	});


	// Homework: step 4. Make tuple_cat work with references.
	// The test below tests the concatenation of tuples with lvalue and rvalue references. Current implementation
	// ignores these references and will create an output tuple with normal integers.
	// std::tuple_cat is included for reference so you can compare the expected outcome.
	// Hint: use the tuple_cat_result_t metafunction to ensure the return type of make_tuple_from_fwd_tuple is correct
	// Note: some filter tests may start failing after updating tuple_cat to correctly handle references. This is expected
	// as the current filter implementation implicitly assumes that tuple_cat strips references from the element type.
	// You may want to temporarily comment out the failing filter tests. We will re-enable them in step 5
	Tester::test("tuple_cat_with_refs", []() {
		int i = 10;
		int j = 11;
		Tuple<int, int &, int> tup{4, i, 11};
		Tuple<int &&> tup2{std::move(j)};
		int j2 = 11;
		std::tuple<int, int &, int> stup{4, i, 11};
		std::tuple<int &&> stup2{std::move(j2)};


		auto t1_2 = tuple_cat(std::move(tup), std::move(tup2));
		auto st1_2 = std::tuple_cat(std::move(stup), std::move(stup2));

		// static_assert(std::is_same_v<decltype(t1_2), Tuple<int, int &, int, int &&>>);
		// static_assert(std::is_same_v<decltype(st1_2), std::tuple<int, int &, int, int &&>>);
		ASSERT((std::is_same_v<decltype(t1_2), Tuple<int, int &, int, int &&>>));
		ASSERT((std::is_same_v<decltype(st1_2), std::tuple<int, int &, int, int &&>>));
	});

	// Homework step5:
	// In order to make filter work correctly with reference type elements, introduce a tuple_result_t metafunction in the
	// detail namespace earlier changes to execute predicate on correct type.
	// Hint: you can use a similar approach as in the current filter implementation when building the result type:
	// Wrapping element types that pass the filter into a tuple type and inserting empty tuples for those that don't (use
	// if_ from Metaprogramming.h). Then pass that type to the tuple_cat_result_t metafunction created in step 2.
	Tester::test("filter_result", []() {
		// static_assert(
		//     std::is_same_v<detail::filter_result_t<Tuple<int, double, unsigned>, std::is_integral>, Tuple<int,
		//     unsigned>>);
		// static_assert(
		//     std::is_same_v<detail::filter_result_t<Tuple<int, int &, int &&>, std::is_reference>, Tuple<int &, int &&>>);
	});

	// Homework step6: Make filter compatible with refences using the now reference-compatible tuple_cat function and
	// the filter_result_t metafunction from step 5.
	// Hint: Update detail::tuple_cat_content to directly use tuple_cat_impl with the correct result tuple type.
	// Note: if you commented out some of the filter tests in step 4, make sure to re-enable them. They should now pass.
	Tester::test("tuple_filter_with_refs", []() {
		int i = 10;
		Tuple<int, int &, int> tup{4, i, 11};

		auto tup2 = filter<boq::not_<std::is_reference>::type>(std::forward<decltype(tup)>(tup));
		// static_assert(std::is_same_v<decltype(tup2), Tuple<int, int>>);
		ASSERT((std::is_same_v<decltype(tup2), Tuple<int, int>>));


		auto tup3 = filter<std::is_reference>(std::forward<decltype(tup)>(tup));
		// static_assert(std::is_same_v<decltype(tup3), Tuple<int &>>);
		ASSERT((std::is_same_v<decltype(tup3), Tuple<int &>>));
	});

	return 0;
}