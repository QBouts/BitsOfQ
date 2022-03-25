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

#ifndef BOQ_METAPROGRAMMING_H
#define BOQ_METAPROGRAMMING_H

#include <cassert>
#include <list>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace bits_of_q {

template <typename T>
struct has_type {
	using type = T;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// IF_ /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <bool condition, typename THEN, typename ELSE>
struct if_;

template <typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> : has_type<THEN> {};

template <typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> : has_type<ELSE> {};

static_assert(std::is_same_v<typename if_<(10 > 5), int, bool>::type, int>);
static_assert(std::is_same_v<typename if_<(10 < 5), int, bool>::type, bool>);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// TYPE LIST MANIPULATION ////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <typename...>
struct type_list {};

/////////////////////////////////// EMTPY /////////////////////////////////////

template <typename LIST>
struct empty : std::false_type {};

template <template <typename...> class LIST>
struct empty<LIST<>> : std::true_type {};

template <typename LIST>
static constexpr bool empty_v = empty<LIST>::value;

static_assert(empty_v<type_list<>>);
static_assert(empty_v<type_list<int, bool>> == false);

/////////////////////////////////// FRONT /////////////////////////////////////

template <typename LIST>
struct front;

template <template <typename...> class LIST, typename T0, typename... T1toN>
struct front<LIST<T0, T1toN...>> : has_type<T0> {};

template <typename LIST>
using front_t = typename front<LIST>::type;

static_assert(std::is_same_v<front_t<type_list<int, bool, float>>, int>);

///////////////////////////////// POP_FRONT ///////////////////////////////////

template <typename LIST>
struct pop_front;

template <template <typename...> class LIST, typename T0, typename... T1toN>
struct pop_front<LIST<T0, T1toN...>> : has_type<LIST<T1toN...>> {};

template <typename LIST>
using pop_front_t = typename pop_front<LIST>::type;

static_assert(std::is_same_v<pop_front_t<type_list<int, bool, float>>, type_list<bool, float>>);

/////////////////////////////////// BACK //////////////////////////////////////

template <typename LIST>
struct back : has_type<typename back<pop_front_t<LIST>>::type> {};

template <template <typename...> class LIST, typename T0>
struct back<LIST<T0>> : has_type<T0> {};

template <typename LIST>
using back_t = typename back<LIST>::type;

static_assert(std::is_same_v<back_t<type_list<int, bool, float>>, float>);
static_assert(std::is_same_v<back_t<type_list<int, bool>>, bool>);

///////////////////////////////// PUSH_BACK ///////////////////////////////////

template <typename LIST, typename T>
struct push_back;

template <template <typename...> class LIST, typename... T0toN, typename T>
struct push_back<LIST<T0toN...>, T> : has_type<LIST<T0toN..., T>> {};

template <typename LIST, typename T>
using push_back_t = typename push_back<LIST, T>::type;

static_assert(std::is_same_v<push_back_t<type_list<>, int>, type_list<int>>);
static_assert(std::is_same_v<push_back_t<type_list<int, bool>, float>, type_list<int, bool, float>>);

////////////////////////////////// POP_BACK ///////////////////////////////////

template <typename FROM_LIST, typename TO_LIST>
struct make_same_container;

template <template <typename...> class LIST,
          typename... ELEMS,
          template <typename...>
          class TO_LIST,
          typename... ELEMS2>
struct make_same_container<LIST<ELEMS...>, TO_LIST<ELEMS2...>> : has_type<TO_LIST<ELEMS...>> {};

template <typename FROM_LIST, typename TO_LIST>
using make_same_container_t = typename make_same_container<FROM_LIST, TO_LIST>::type;

template <typename LIST, typename RET_LIST = make_same_container_t<type_list<>, LIST>>
struct pop_back;

template <template <typename...> class LIST, typename T0, typename RET_LIST>
struct pop_back<LIST<T0>, RET_LIST> : has_type<RET_LIST> {};

template <template <typename...> class LIST, typename T0, typename T1, typename... T2toN, typename RET_LIST>
struct pop_back<LIST<T0, T1, T2toN...>, RET_LIST> : pop_back<LIST<T1, T2toN...>, push_back_t<RET_LIST, T0>> {};

template <typename LIST>
using pop_back_t = typename pop_back<LIST>::type;

static_assert(std::is_same_v<pop_back_t<type_list<int>>, type_list<>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool, float>>, type_list<int, bool>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool>>, type_list<int>>);
static_assert(std::is_same_v<pop_back_t<std::tuple<int, bool>>, std::tuple<int>>);

//////////////////////////////////// AT ///////////////////////////////////////

template <typename LIST, size_t index>
struct at : has_type<typename at<pop_front_t<LIST>, index - 1>::type> {};

template <typename LIST>
struct at<LIST, 0> : has_type<front_t<LIST>> {};

template <typename LIST, size_t index>
using at_t = typename at<LIST, index>::type;

static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 1>, bool>);
static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 2>, float>);

//////////////////////////////////// ANY //////////////////////////////////////

template <template <typename> class PREDICATE, typename LIST>
struct any;

template <template <typename> class PREDICATE, template <typename...> class LIST>
struct any<PREDICATE, LIST<>> : std::false_type {};

template <template <typename> class PREDICATE, typename LIST>
struct any : if_<  // if predicate matches first type
                 PREDICATE<front_t<LIST>>::value,
                 // then
                 std::true_type,
                 // else
                 typename any<PREDICATE, pop_front_t<LIST>>::type>::type {};

template <template <typename> class PREDICATE, typename LIST>
static constexpr bool any_v = any<PREDICATE, LIST>::value;

static_assert(any_v<std::is_integral, type_list<int, double, std::string>>);
static_assert(any_v<std::is_integral, type_list<std::string, double, int>>);
static_assert(!any_v<std::is_integral, type_list<std::string, double, float>>);

/////////////////////////////// CONTAINS_TYPE /////////////////////////////////

template <typename T>
struct same_as_pred {
	template <typename U>
	struct predicate : std::is_same<T, U> {};
};

template <typename SEARCH, typename LIST>
static constexpr bool contains_type_v = any<same_as_pred<SEARCH>::template predicate, LIST>::value;

static_assert(contains_type_v<int, type_list<int, bool, float>>);
static_assert(contains_type_v<float, type_list<int, bool, float>>);
static_assert(contains_type_v<double, type_list<int, bool, float>> == false);

/////////////////////////////////// NOT ///////////////////////////////////////

template <template <typename...> class PRED>
struct not_ {
	template <typename... Ts>
	using type = std::integral_constant<bool, !PRED<Ts...>::value>;
};

///////////////////////////////////////////////////////////////////////////////

template <int FIRST, int LAST, typename LAMBDA>
constexpr void static_for(const LAMBDA &f) {
	if constexpr (FIRST < LAST) {
		f(std::integral_constant<int, FIRST>{});
		static_for<FIRST + 1, LAST>(f);
	}
}
}  // namespace bits_of_q

#endif  // BOQ_METAPROGRAMMING_H
