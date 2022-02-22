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

#include <array>
#include <exception>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

#include "Metaprogramming.h"

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
template <size_t i>
struct IndexedCopyCounter {
	struct reset_after_construct_t {};
	static constexpr reset_after_construct_t reset_after_construct{};

	inline static CopyStats stats;

	explicit IndexedCopyCounter(reset_after_construct_t) { reset(); }
	IndexedCopyCounter() { stats.n_default_constructs++; }
	IndexedCopyCounter(const IndexedCopyCounter &) { stats.n_copies++; }
	IndexedCopyCounter &operator=(const IndexedCopyCounter &) {
		stats.n_copies++;
		return *this;
	}
	IndexedCopyCounter(IndexedCopyCounter &&) noexcept { stats.n_moves++; };
	IndexedCopyCounter &operator=(IndexedCopyCounter &&) noexcept {
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
	template <size_t i2>
	bool operator==(const IndexedCopyCounter<i2> &other) const {
		return stats == other.stats;
	};
};

namespace detail {
static constexpr size_t default_copycounter_index = 2734987;  // just some random number so you don't easily create an
                                                              // IndexedCopyCounter with the same index
}  // namespace detail
using CopyCounter = IndexedCopyCounter<detail::default_copycounter_index>;

template <size_t index = detail::default_copycounter_index>
IndexedCopyCounter<index> make_copy_counter() {
	return IndexedCopyCounter<index>{IndexedCopyCounter<index>::reset_after_construct};
}

}  // namespace bits_of_q


/// This namespace contains small testing framework developed for this series to keep the number of dependencies low.
/// For any serious project, please use a well-established testing framework such as GoogleTest or Catch.
namespace bits_of_q::testing {
struct AssertFailed : std::runtime_error {
	explicit AssertFailed(std::string_view file, size_t line_nr, std::string_view expression)
	    : std::runtime_error("assert failed")
	    , file(file)
	    , line_nr(line_nr)
	    , expression(expression) {}
	std::string_view file;
	size_t line_nr;
	std::string_view expression;
};

#define ASSERT(expr)                                                     \
	if (!(expr)) {                                                         \
		throw ::bits_of_q::testing::AssertFailed{__FILE__, __LINE__, #expr}; \
	}


class Tester {
	/// Unix terminal color codes
	/// Use fmt::format's color manipulation or if your compiler already supports it std::format for an easy
	/// cross-platform alternative.
	static constexpr std::string_view color_reset = "\033[0m";
	static constexpr std::string_view color_red = "\033[31m";
	static constexpr std::string_view color_green = "\033[32m";

public:
	/// Executes the function outputting a banner at the start and end as well as printing information on exceptions
	/// thrown by the function.
	template <typename FUNC>
	static void test(std::string_view test_name, FUNC &&function) {
		print_test_start(test_name);
		try {
			function();
		} catch (...) {
			output_exception_info();
			print_test_end(test_name, false);
			return;
		}
		print_test_end(test_name, true);
	}

private:
	static void print_test_start(std::string_view test_name) {
		std::cerr << color_green << "[ RUN      ] " << color_reset << test_name << "\n";
	}
	static void print_test_end(std::string_view test_name, bool passed) {
		if (passed) {
			std::cerr << color_green << "[       OK ] " << color_reset << test_name << "\n";
		} else {
			std::cerr << color_red << "[  FAILED  ] " << color_reset << test_name << "\n";
		}
	}

	static void output_exception_info() {
		try {
			throw;
		} catch (const AssertFailed &e) {
			std::cerr << "Exception was thrown at " << e.file << ":" << e.line_nr << " :\n";
			std::cerr << "ASSERT( " << e.expression << " ) evaluated to false\n";
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		} catch (...) {
			std::cerr << "Unknown exception thrown\n";
		}
	}
};

enum class Configuration { non_const_lvalue = 0, const_lvalue, non_const_rvalue, const_rvalue };
static constexpr std::array<std::string_view, 4> g_config_string = {"&", "const &", "&&", "const &&"};
constexpr std::string_view config_to_string(Configuration c) {
	return g_config_string[static_cast<size_t>(c)];
}
template <Configuration... configs>
class Builder;

template <size_t n_args>
class TesterWithBuilder {
public:
	/// Executes functions with a builder for different configurations(see above) as input.
	/// Example:
	/// if n_args == 2, the test function will execute the input function 4*4=16 times with the following builders
	/// func(Builder<non_const_lvalue, non_const_lvalue)
	/// func(Builder<const_lvalue, non_const_lvalue)
	/// func(Builder<non_const_rvalue, non_const_lvalue)
	/// func(Builder<const_rvalue, non_const_lvalue)
	/// func(Builder<non_const_lvalue, const_lvalue)
	/// func(Builder<const_lvalue, const_lvalue)
	/// func(Builder<non_const_rvalue, const_lvalue)
	/// func(Builder<const_lvalue, const_lvalue)
	/// func(Builder<non_const_lvalue, non_const_rvalue)
	/// ... etc, for all 4^2 = 16 input configurations
	template <typename FUNC>
	static void test(std::string_view test_name, FUNC &&function) {
		auto test_func = [&]() {
			static constexpr size_t n_configurations = constexpr_pow(4U, n_args);
			int failed_configs = 0;
			static_for<0, n_configurations>([&](auto i) {
				try {
					execute_for_config<i.value>(std::make_index_sequence<n_args>{}, function);
				} catch (...) {
					output_exception_info<i.value>();
					failed_configs++;
				}
			});
			if (failed_configs > 0) {
				throw std::runtime_error("Test failed for " + std::to_string(failed_configs) + " configurations");
			};
		};
		Tester::test(test_name, std::move(test_func));
	}

private:
	template <typename T>
	static constexpr T constexpr_pow(T num, unsigned int pow) {
		return (pow >= sizeof(unsigned int) * 8) ? 0 : pow == 0 ? 1 : num * constexpr_pow(num, pow - 1);
	}

	template <size_t config, size_t... arg_indices, typename FUNC>
	static void execute_for_config(std::index_sequence<arg_indices...>, FUNC &&function) {
		function(Builder<compute_arg_config<config, arg_indices>()...>{});
	}

	template <size_t config, size_t arg_index>
	static constexpr Configuration compute_arg_config() {
		constexpr size_t n_configurations_per_arg = 4;
		constexpr auto arg_config = static_cast<Configuration>(
		    size_t(config / constexpr_pow(n_configurations_per_arg, arg_index)) % n_configurations_per_arg);
		return arg_config;
	}

	template <size_t config>
	static void output_exception_info() {
		try {
			throw;
		} catch (const AssertFailed &e) {
			std::cerr << "Exception was thrown at " << e.file << ":" << e.line_nr << " :\n";
			std::cerr << "ASSERT( " << e.expression
			          << " ) evaluated to false with config: " << get_config_str<config>(std::make_index_sequence<n_args>{})
			          << '\n';
		} catch (const std::exception &e) {
			std::cerr << "Exception thrown: " << e.what() << '\n';
		} catch (...) {
			std::cerr << "Unknown exception thrown\n";
		}
	}
	template <size_t config, size_t... arg_indices>
	static std::string get_config_str(std::index_sequence<arg_indices...>) {
		return "| " + ((std::string{config_to_string(compute_arg_config<config, arg_indices>())} + " | ") + ...);
	};
};

template <Configuration... configs>
class Builder {
public:
	template <typename ARG>
		requires(sizeof...(configs) == 1)
	decltype(auto) build(ARG &&arg) { return store_and_cast<configs...>(std::forward<ARG>(arg)); }

	template <typename... ARGS>
		requires(sizeof...(configs) > 1 && sizeof...(configs) == sizeof...(ARGS))
	decltype(auto) build(ARGS &&...args) {
		return std::tuple<decltype(store_and_cast<configs>(std::forward<ARGS>(args)))...>{
		    store_and_cast<configs>(std::forward<ARGS>(args))...};
	}

private:
	std::vector<std::unique_ptr<void, void (*)(void *)>> m_values;

	template <Configuration config, typename T>
	decltype(auto) store_and_cast(T &&t) {
		auto *copy = new std::remove_cvref_t<T>{std::forward<T>(t)};
		void (*destructor)(void *) = [](void *ptr) { delete static_cast<std::remove_cvref_t<T> *>(ptr); };
		m_values.emplace_back(copy, destructor);
		return cast_value<config>(*copy);
	}

	template <Configuration config, typename T>
	decltype(auto) cast_value(T &value) {
		if constexpr (config == Configuration::non_const_lvalue) {
			return static_cast<std::remove_cv_t<T> &>(value);
		}
		if constexpr (config == Configuration::const_lvalue) {
			return static_cast<const std::remove_cv_t<T> &>(value);
		}
		if constexpr (config == Configuration::non_const_rvalue) {
			return static_cast<std::remove_cv_t<T> &&>(value);
		}
		if constexpr (config == Configuration::const_rvalue) {
			return static_cast<const std::remove_cv_t<T> &&>(value);
		}
	}
};


}  // namespace bits_of_q::testing

#endif  // BOQ_TEST_UTILS_H
