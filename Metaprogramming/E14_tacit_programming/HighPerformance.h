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

#ifndef BOQ_HIGH_PERFORMANCE_METAPROGRAMMING_H
#define BOQ_HIGH_PERFORMANCE_METAPROGRAMMING_H

#include <type_traits>

#include "Join.h"

namespace bits_of_q::high_performance {

template <bool condition>
struct if_ {
	template <typename A, typename B>
	using f = A;
};
template <>
struct if_<false> {
	template <typename A, typename B>
	using f = B;
};

namespace detail {
// used in remove_if
template <typename PREDICATE, typename CONTINUATION = identity>
struct wrap_if_not {
	template <typename T>
	using f = typename CONTINUATION::template f<
	    typename if_<!PREDICATE::template value<T>>::template f<type_list<T>, type_list<>>>;
};

// unpacking
template <typename CONTINUATION, typename LIST>
struct unpack_impl;

template <typename CONTINUATION, template <typename...> class LIST, typename... ELEMS>
struct unpack_impl<CONTINUATION, LIST<ELEMS...>> {
	using type = typename CONTINUATION::template f<ELEMS...>;
};

}  // namespace detail

/// unpacks a LIST-like type (basically any template using typename parameters) passing its elements to the given
/// continuation
template <typename CONTINUATION>
struct unpack {
	template <typename LIST>
	using f = typename detail::unpack_impl<CONTINUATION, LIST>::type;
};


/// Convert an eager predicate to a lazy predicate.
template <template <typename...> class PREDICATE>
struct to_lazy_predicate {
	template <typename... Ts>
	static constexpr bool value = PREDICATE<Ts...>::value;
};

///////////////////////////////////// JOIN ////////////////////////////////////

// See Join.h

/////////////////////////////////// TRANSFORM /////////////////////////////////

/// Apply the given FUNCTION to each element of the parameter pack.
/// FUNCTION should be a continuation.
template <typename FUNCTION, typename CONTINUATION = listify>
struct transform {
	template <typename... Ts>
	using f = typename CONTINUATION::template f<typename FUNCTION::template f<Ts>...>;
};

////////////////////////////////// REMOVE_IF //////////////////////////////////

// high performance implementation, using composition of existing (in this version still naive) library functions. we'll
// upgrade the building blocks one by one in the next episodes.

/// Removes any types for which PREDICATE evaluates to true from the parameter pack. Passing the resulting parameter
/// pack to the continuation
template <typename PREDICATE, typename CONTINUATION = listify>
struct remove_if {
	template <typename... Ts>
	using f = typename transform<detail::wrap_if_not<PREDICATE>, join<CONTINUATION>>::template f<Ts...>;
};

}  // namespace bits_of_q::high_performance

#endif  // BOQ_HIGH_PERFORMANCE_METAPROGRAMMING_H