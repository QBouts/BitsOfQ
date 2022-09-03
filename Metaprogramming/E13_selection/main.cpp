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


#include <type_traits>

#include "BenchmarkInputs.h"

#ifndef BENCHMARK
#include "Tests.h"
#endif

// different implementations
#include "Composed.h"
#include "ComposedDefaults.h"
#include "ComposedDefaults64.h"
#include "ComposedFastTrack.h"
#include "ComposedFastTrack64.h"
#include "ComposedSelection64.h"
//#include "HighPerformance.h"
#include "Naive.h"
#include "NaiveLazy.h"
//
//#include "BenchmarkInputsSmall.h"

using namespace bits_of_q;

template <typename T>
struct same_as_pred {
	template <typename U>
	struct predicate : std::is_same<T, U> {};
};

#ifndef ALGO
#define ALGO 8
#endif

#ifndef INPUT
#define INPUT input1024_same4
#endif
/*
using input10240_same4 =
    composed_defaults64::join_t<input2048_same4, input2048_same4, input2048_same4, input2048_same4, input2048_same4>;
using input20480_same4 = composed_defaults64::join_t<input10240_same4, input10240_same4>;
using input30720_same4 = composed_defaults64::join_t<input10240_same4, input10240_same4, input10240_same4>;
using input40960_same4 =
    composed_defaults64::join_t<input10240_same4, input10240_same4, input10240_same4, input10240_same4>;
using input51200_same4 = composed_defaults64::
    join_t<input10240_same4, input10240_same4, input10240_same4, input10240_same4, input10240_same4>;

#undef INPUT
#define INPUT input51200_same4  //*/

template <typename T>
void run_test() {
	constexpr int i = ALGO;
	if constexpr (i == 1) {
		[[maybe_unused]] naive::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 2) {
		[[maybe_unused]] naive_lazy::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 3) {
		[[maybe_unused]] composed::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 4) {
		[[maybe_unused]] composed_fast_track::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 5) {
		[[maybe_unused]] composed_fast_track64::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 6) {
		[[maybe_unused]] composed_defaults::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 7) {
		[[maybe_unused]] composed_defaults64::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 8) {
		[[maybe_unused]] composed_selection64::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
}
int main() {
	[[maybe_unused]] input128_same4 dummy1;
	[[maybe_unused]] input256_same4 dummy2;
	[[maybe_unused]] input512_same4 dummy3;
	[[maybe_unused]] input1024_same4 dummy4;
	[[maybe_unused]] input2048_same4 dummy5;
	/*
	[[maybe_unused]] input10240_same4 dummy6;
	[[maybe_unused]] input20480_same4 dummy7;
	[[maybe_unused]] input30720_same4 dummy8;
	[[maybe_unused]] input40960_same4 dummy9;
	[[maybe_unused]] input51200_same4 dummy10;*/
	//[[maybe_unused]] INPUT dummy{};
	run_test<void>();
	return 0;
}