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
#include <list>
#include <string>
#include <tuple>
#include <vector>

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

template <>
struct empty<type_list<>> : std::true_type {};

template <typename LIST>
static constexpr bool empty_v = empty<LIST>::value;

static_assert(empty_v<type_list<>>);
static_assert(empty_v<type_list<int, bool>> == false);

/////////////////////////////////// FRONT /////////////////////////////////////

template <typename LIST>
struct front;

template <typename T0, typename... T1toN>
struct front<type_list<T0, T1toN...>> : has_type<T0> {};

template <typename LIST>
using front_t = typename front<LIST>::type;

static_assert(std::is_same_v<front_t<type_list<int, bool, float>>, int>);

///////////////////////////////// POP_FRONT ///////////////////////////////////

template <typename LIST>
struct pop_front;

template <typename T0, typename... T1toN>
struct pop_front<type_list<T0, T1toN...>> : has_type<type_list<T1toN...>> {};

template <typename LIST>
using pop_front_t = typename pop_front<LIST>::type;

static_assert(std::is_same_v<pop_front_t<type_list<int, bool, float>>, type_list<bool, float>>);

//////////////////////////////////// BACK /////////////////////////////////////

template <typename LIST>
struct back : has_type<typename back<pop_front_t<LIST>>::type> {};

template <typename T0>
struct back<type_list<T0>> : has_type<T0> {};

template <typename LIST>
using back_t = typename back<LIST>::type;

static_assert(std::is_same_v<back_t<type_list<int, bool, float>>, float>);
static_assert(std::is_same_v<back_t<type_list<int, bool, bool>>, bool>);

///////////////////////////////// PUSH_BACK ///////////////////////////////////

template <typename LIST, typename T>
struct push_back;

template <typename... T0toN, typename T>
struct push_back<type_list<T0toN...>, T> : has_type<type_list<T0toN..., T>> {};

template <typename LIST, typename T>
using push_back_t = typename push_back<LIST, T>::type;

static_assert(std::is_same_v<push_back_t<type_list<>, int>, type_list<int>>);
static_assert(std::is_same_v<push_back_t<type_list<int, bool>, float>, type_list<int, bool, float>>);

////////////////////////////////// POP_BACK ///////////////////////////////////

template <typename LIST, typename RET_LIST = type_list<>>
struct pop_back;

template <typename T0, typename RET_LIST>
struct pop_back<type_list<T0>, RET_LIST> : has_type<RET_LIST> {};

template <typename T0, typename T1, typename... T2toN, typename RET_LIST>
struct pop_back<type_list<T0, T1, T2toN...>, RET_LIST> : pop_back<type_list<T1, T2toN...>, push_back_t<RET_LIST, T0>> {
};

template <typename LIST>
using pop_back_t = typename pop_back<LIST>::type;

static_assert(std::is_same_v<pop_back_t<type_list<int>>, type_list<>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool, float>>, type_list<int, bool>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool>>, type_list<int>>);

///////////////////////////////////// AT //////////////////////////////////////

template <typename LIST, size_t index>
struct at : has_type<typename at<pop_front_t<LIST>, index - 1>::type> {};

template <typename LIST>
struct at<LIST, 0> : has_type<front_t<LIST>> {};

template <typename LIST, size_t index>
using at_t = typename at<LIST, index>::type;

static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 1>, bool>);
static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 2>, float>);

/////////////////////////////// CONTAINS_TYPE /////////////////////////////////

template <typename SEARCH, typename LIST>
struct contains_type : if_<  // IF
                           std::is_same_v<SEARCH, front_t<LIST>>,
                           // THEN
                           std::true_type,
                           // ELSE
                           contains_type<SEARCH, pop_front_t<LIST>>>::type {};

template <typename SEARCH>
struct contains_type<SEARCH, type_list<>> : std::false_type {};

template <typename SEARCH, typename LIST>
static constexpr bool contains_type_v = contains_type<SEARCH, LIST>::value;

static_assert(contains_type_v<int, type_list<int, bool, float>>);
static_assert(contains_type_v<float, type_list<int, bool, float>>);
static_assert(contains_type_v<double, type_list<int, bool, float>> == false);

///////////////////////////////////////////////////////////////////////////////

int main() {}
