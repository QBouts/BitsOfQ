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

#ifndef BOQ_COMPOSED_FASTTRACK64_METAPROGRAMMING_H
#define BOQ_COMPOSED_FASTTRACK64_METAPROGRAMMING_H

#include <type_traits>

#include "TypeList.h"

namespace bits_of_q::composed_fast_track64 {
// implementation using composition of transform and join functions
// speeding up join by using fast tracks


//////////////////////////////////// JOIN /////////////////////////////////////

template <typename... LISTS>
struct join;

template <typename... Ts, typename... Us, typename... MORE_LISTS>
struct join<type_list<Ts...>, type_list<Us...>, MORE_LISTS...> : join<type_list<Ts..., Us...>, MORE_LISTS...> {};

template <typename LIST>
struct join<LIST> {
	using type = LIST;
};

template <typename... T0s, typename... T1s, typename... T2s, typename... T3s, typename... MORE_LISTS>
struct join<type_list<T0s...>, type_list<T1s...>, type_list<T2s...>, type_list<T3s...>, MORE_LISTS...>
    : join<type_list<T0s..., T1s..., T2s..., T3s...>, MORE_LISTS...> {};

template <typename... T0s,
          typename... T1s,
          typename... T2s,
          typename... T3s,
          typename... T4s,
          typename... T5s,
          typename... T6s,
          typename... T7s,
          typename... MORE_LISTS>
struct join<type_list<T0s...>,
            type_list<T1s...>,
            type_list<T2s...>,
            type_list<T3s...>,
            type_list<T4s...>,
            type_list<T5s...>,
            type_list<T6s...>,
            type_list<T7s...>,
            MORE_LISTS...>
    : join<type_list<T0s..., T1s..., T2s..., T3s..., T4s..., T5s..., T6s..., T7s...>, MORE_LISTS...> {};

template <typename... T0s,
          typename... T1s,
          typename... T2s,
          typename... T3s,
          typename... T4s,
          typename... T5s,
          typename... T6s,
          typename... T7s,
          typename... T8s,
          typename... T9s,
          typename... T10s,
          typename... T11s,
          typename... T12s,
          typename... T13s,
          typename... T14s,
          typename... T15s,
          typename... MORE_LISTS>
struct join<type_list<T0s...>,
            type_list<T1s...>,
            type_list<T2s...>,
            type_list<T3s...>,
            type_list<T4s...>,
            type_list<T5s...>,
            type_list<T6s...>,
            type_list<T7s...>,
            type_list<T8s...>,
            type_list<T9s...>,
            type_list<T10s...>,
            type_list<T11s...>,
            type_list<T12s...>,
            type_list<T13s...>,
            type_list<T14s...>,
            type_list<T15s...>,
            MORE_LISTS...> : join<type_list<T0s...,
                                            T1s...,
                                            T2s...,
                                            T3s...,
                                            T4s...,
                                            T5s...,
                                            T6s...,
                                            T7s...,
                                            T8s...,
                                            T9s...,
                                            T10s...,
                                            T11s...,
                                            T12s...,
                                            T13s...,
                                            T14s...,
                                            T15s...>,
                                  MORE_LISTS...> {};

template <typename... T0s,
          typename... T1s,
          typename... T2s,
          typename... T3s,
          typename... T4s,
          typename... T5s,
          typename... T6s,
          typename... T7s,
          typename... T8s,
          typename... T9s,
          typename... T10s,
          typename... T11s,
          typename... T12s,
          typename... T13s,
          typename... T14s,
          typename... T15s,
          typename... T16s,
          typename... T17s,
          typename... T18s,
          typename... T19s,
          typename... T20s,
          typename... T21s,
          typename... T22s,
          typename... T23s,
          typename... T24s,
          typename... T25s,
          typename... T26s,
          typename... T27s,
          typename... T28s,
          typename... T29s,
          typename... T30s,
          typename... T31s,
          typename... T32s,
          typename... T33s,
          typename... T34s,
          typename... T35s,
          typename... T36s,
          typename... T37s,
          typename... T38s,
          typename... T39s,
          typename... T40s,
          typename... T41s,
          typename... T42s,
          typename... T43s,
          typename... T44s,
          typename... T45s,
          typename... T46s,
          typename... T47s,
          typename... T48s,
          typename... T49s,
          typename... T50s,
          typename... T51s,
          typename... T52s,
          typename... T53s,
          typename... T54s,
          typename... T55s,
          typename... T56s,
          typename... T57s,
          typename... T58s,
          typename... T59s,
          typename... T60s,
          typename... T61s,
          typename... T62s,
          typename... T63s,
          typename... MORE_LISTS>
struct join<type_list<T0s...>,
            type_list<T1s...>,
            type_list<T2s...>,
            type_list<T3s...>,
            type_list<T4s...>,
            type_list<T5s...>,
            type_list<T6s...>,
            type_list<T7s...>,
            type_list<T8s...>,
            type_list<T9s...>,
            type_list<T10s...>,
            type_list<T11s...>,
            type_list<T12s...>,
            type_list<T13s...>,
            type_list<T14s...>,
            type_list<T15s...>,
            type_list<T16s...>,
            type_list<T17s...>,
            type_list<T18s...>,
            type_list<T19s...>,
            type_list<T20s...>,
            type_list<T21s...>,
            type_list<T22s...>,
            type_list<T23s...>,
            type_list<T24s...>,
            type_list<T25s...>,
            type_list<T26s...>,
            type_list<T27s...>,
            type_list<T28s...>,
            type_list<T29s...>,
            type_list<T30s...>,
            type_list<T31s...>,
            type_list<T32s...>,
            type_list<T33s...>,
            type_list<T34s...>,
            type_list<T35s...>,
            type_list<T36s...>,
            type_list<T37s...>,
            type_list<T38s...>,
            type_list<T39s...>,
            type_list<T40s...>,
            type_list<T41s...>,
            type_list<T42s...>,
            type_list<T43s...>,
            type_list<T44s...>,
            type_list<T45s...>,
            type_list<T46s...>,
            type_list<T47s...>,
            type_list<T48s...>,
            type_list<T49s...>,
            type_list<T50s...>,
            type_list<T51s...>,
            type_list<T52s...>,
            type_list<T53s...>,
            type_list<T54s...>,
            type_list<T55s...>,
            type_list<T56s...>,
            type_list<T57s...>,
            type_list<T58s...>,
            type_list<T59s...>,
            type_list<T60s...>,
            type_list<T61s...>,
            type_list<T62s...>,
            type_list<T63s...>,
            MORE_LISTS...> : join<type_list<T0s...,
                                            T1s...,
                                            T2s...,
                                            T3s...,
                                            T4s...,
                                            T5s...,
                                            T6s...,
                                            T7s...,
                                            T8s...,
                                            T9s...,
                                            T10s...,
                                            T11s...,
                                            T12s...,
                                            T13s...,
                                            T14s...,
                                            T15s...,
                                            T16s...,
                                            T17s...,
                                            T18s...,
                                            T19s...,
                                            T20s...,
                                            T21s...,
                                            T22s...,
                                            T23s...,
                                            T24s...,
                                            T25s...,
                                            T26s...,
                                            T27s...,
                                            T28s...,
                                            T29s...,
                                            T30s...,
                                            T31s...,
                                            T32s...,
                                            T33s...,
                                            T34s...,
                                            T35s...,
                                            T36s...,
                                            T37s...,
                                            T38s...,
                                            T39s...,
                                            T40s...,
                                            T41s...,
                                            T42s...,
                                            T43s...,
                                            T44s...,
                                            T45s...,
                                            T46s...,
                                            T47s...,
                                            T48s...,
                                            T49s...,
                                            T50s...,
                                            T51s...,
                                            T52s...,
                                            T53s...,
                                            T54s...,
                                            T55s...,
                                            T56s...,
                                            T57s...,
                                            T58s...,
                                            T59s...,
                                            T60s...,
                                            T61s...,
                                            T62s...,
                                            T63s...>,
                                  MORE_LISTS...> {};

template <typename... LISTS>
using join_t = typename join<LISTS...>::type;

///////////////////////////////// TRANSFORM ///////////////////////////////////

template <typename LIST, template <typename> class FUNC>
struct transform;

template <typename... Ts, template <typename> class FUNC>
struct transform<type_list<Ts...>, FUNC> {
	using type = type_list<typename FUNC<Ts>::type...>;
};

template <typename LIST, template <typename> class FUNC>
using transform_t = typename transform<LIST, FUNC>::type;

////////////////////////////////// REMOVE_IF //////////////////////////////////

namespace detail {
template <template <typename> class PREDICATE, typename T>
struct wrap_if_not : if_<PREDICATE<T>::value, type_list<>, type_list<T>> {};

template <template <typename> class PREDICATE>
struct wrap_if_not_func {
	template <typename T>
	using func = wrap_if_not<PREDICATE, T>;
};

template <typename LIST_OF_LISTS>
struct join_list_of_lists;
template <typename... Ts>
struct join_list_of_lists<type_list<Ts...>> : join<Ts...> {};

template <typename LIST_OF_LISTS>
using join_list_of_lists_t = typename join_list_of_lists<LIST_OF_LISTS>::type;

static_assert(std::is_same_v<join_list_of_lists_t<type_list<type_list<int, bool>, type_list<>, type_list<float>>>,
                             type_list<int, bool, float>>);
}  // namespace detail

template <template <typename> class PREDICATE, typename LIST>
struct remove_if {
	using type = detail::join_list_of_lists_t<transform_t<LIST, detail::wrap_if_not_func<PREDICATE>::template func>>;
};

template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;

}  // namespace bits_of_q::composed_fast_track64

#endif