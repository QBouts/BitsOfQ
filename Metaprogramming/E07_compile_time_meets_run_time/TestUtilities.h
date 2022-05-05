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

#ifndef BOQ_TEST_UTILS_H
#define BOQ_TEST_UTILS_H

#include <iostream>

namespace bits_of_q {

struct CopyStats {
	int n_default_constructs = 0;
	int n_copies = 0;
	int n_moves = 0;
	bool operator==(const CopyStats &other) const = default;
};

inline std::ostream &operator<<(std::ostream &os, const CopyStats &stats) {
	os << "{ default_constructs: " << stats.n_default_constructs << ", copies: " << stats.n_copies
	   << ", moves: " << stats.n_moves << " }";
	return os;
}
struct CopyCounter {
	inline static CopyStats stats;

	CopyCounter() { stats.n_default_constructs++; }
	CopyCounter(const CopyCounter &) { stats.n_copies++; }
	CopyCounter &operator=(const CopyCounter &) {
		stats.n_copies++;
		return *this;
	}
	CopyCounter(CopyCounter &&) noexcept { stats.n_moves++; };
	CopyCounter &operator=(CopyCounter &&) noexcept {
		stats.n_moves++;
		return *this;
	}
	static CopyStats reset() {
		CopyStats old_stats = stats;
		stats.n_copies = 0;
		stats.n_moves = 0;
		stats.n_default_constructs = 0;
		return old_stats;
	}
};

}  // namespace bits_of_q

#endif  // BOQ_TEST_UTILS_H
