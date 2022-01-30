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


#include "Metaprogramming.h"
#include "TestUtilities.h"
#include "Tuple.h"


namespace bits_of_q {}  // namespace bits_of_q

int main() {
	using namespace bits_of_q;

	auto tup = make_tuple(8, true, 1.5);
	std::cout << get<2>(tup) << '\n';

	const Tuple const_tup{1, false, 4};
	std::cout << get<2>(const_tup) << '\n';


	std::cout << get<2>(Tuple{2, 3, 8}) << '\n';
	get<2>(tup) = 4.2;
	std::cout << get<2>(tup) << '\n';

	CopyCounter c;
	CopyCounter::reset();

	make_tuple(8, c, 1.5);
	CopyStats our_stats = c.stats;

	CopyCounter::reset();
	std::make_tuple(8, c, 1.5);
	CopyStats std_stats = c.stats;

	std::cout << "bits_of_q::make_tuple: " << our_stats << '\n';
	std::cout << "std::make_tuple:       " << std_stats << '\n';

	assert(our_stats == std_stats);


	CopyCounter::reset();
	get<1>(tup);
	our_stats = CopyCounter::stats;

	auto std_tup = std::make_tuple(8, c, 1.5);
	CopyCounter::reset();
	get<1>(std_tup);
	std_stats = CopyCounter::stats;

	std::cout << "bits_of_q::get: " << our_stats << '\n';
	std::cout << "std::get:       " << std_stats << '\n';

	assert(our_stats == std_stats);
}
