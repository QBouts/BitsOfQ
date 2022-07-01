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
#include "Naive.h"
#include "NaiveLazy.h"


using namespace bits_of_q;

template <typename T>
struct same_as_pred {
	template <typename U>
	struct predicate : std::is_same<T, U> {};
};

#ifndef ALGO
#define ALGO 2
#endif

#ifndef INPUT
#define INPUT input128_different
#endif

template <typename T>
void run_test() {
	constexpr int i = ALGO;
	if constexpr (i == 1) {
		[[maybe_unused]] naive::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 2) {
		[[maybe_unused]] naive_lazy::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	/* // implementations of the algorithms below will be demonstrated and explained in the next episodes!
	if constexpr (i == 3) {
	  [[maybe_unused]] composed::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 4) {
	  [[maybe_unused]] composed_fast_track::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 5) {
	  [[maybe_unused]] composed_defaults::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 6) {
	  namespace hp = high_performance;
	  [[maybe_unused]] hp::unpack<hp::remove_if<hp::to_lazy_predicate<std::is_void>>>::template f<INPUT> t{};
	}*/
}
int main() {
	[[maybe_unused]] INPUT dummy{};
	run_test<void>();
	return 0;
}