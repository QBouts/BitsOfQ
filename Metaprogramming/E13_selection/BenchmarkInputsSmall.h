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

//#include "ComposedDefaults64.h"
#include "ComposedDefaults1024.h"
//#include "ComposedSelection64.h"
#include "ComposedSelection1024.h"
#include "TypeList.h"

namespace bits_of_q::small_input_benchmark {

template <int>
struct dummy {};

template <typename T>
struct same_as_pred {
	template <typename U>
	struct predicate : std::is_same<T, U> {};
};

#ifndef ALGO
#define ALGO 8
#endif

#if ALGO == 7

template <typename LIST>
// using remove_if_algo = composed_defaults64::remove_if<same_as_pred<dummy<0>>::template predicate, LIST>;
using remove_if_algo = composed_defaults1024::remove_if<same_as_pred<dummy<0>>::template predicate, LIST>;

#elif ALGO == 8
template <typename LIST>
// using remove_if_algo = composed_selection64::remove_if<same_as_pred<dummy<0>>::template predicate, LIST>;
using remove_if_algo = composed_selection1024::remove_if<same_as_pred<dummy<0>>::template predicate, LIST>;

#endif

using l0 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<0>>>;
using l1 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<1>>>;
using l2 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<2>>>;
using l3 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<3>>>;
using l4 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<4>>>;
using l5 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<5>>>;
using l6 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<6>>>;
using l7 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<7>>>;
using l8 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<8>>>;
using l9 = remove_if_algo<type_list<dummy<0>, dummy<0>, dummy<9>>>;

using l10 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<0>>>;
using l11 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<1>>>;
using l12 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<2>>>;
using l13 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<3>>>;
using l14 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<4>>>;
using l15 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<5>>>;
using l16 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<6>>>;
using l17 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<7>>>;
using l18 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<8>>>;
using l19 = remove_if_algo<type_list<dummy<0>, dummy<1>, dummy<9>>>;

using l20 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<0>>>;
using l21 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<1>>>;
using l22 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<2>>>;
using l23 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<3>>>;
using l24 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<4>>>;
using l25 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<5>>>;
using l26 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<6>>>;
using l27 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<7>>>;
using l28 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<8>>>;
using l29 = remove_if_algo<type_list<dummy<0>, dummy<2>, dummy<9>>>;

using l30 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<0>>>;
using l31 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<1>>>;
using l32 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<2>>>;
using l33 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<3>>>;
using l34 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<4>>>;
using l35 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<5>>>;
using l36 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<6>>>;
using l37 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<7>>>;
using l38 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<8>>>;
using l39 = remove_if_algo<type_list<dummy<0>, dummy<3>, dummy<9>>>;

using l40 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<0>>>;
using l41 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<1>>>;
using l42 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<2>>>;
using l43 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<3>>>;
using l44 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<4>>>;
using l45 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<5>>>;
using l46 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<6>>>;
using l47 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<7>>>;
using l48 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<8>>>;
using l49 = remove_if_algo<type_list<dummy<0>, dummy<4>, dummy<9>>>;

using l50 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<0>>>;
using l51 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<1>>>;
using l52 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<2>>>;
using l53 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<3>>>;
using l54 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<4>>>;
using l55 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<5>>>;
using l56 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<6>>>;
using l57 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<7>>>;
using l58 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<8>>>;
using l59 = remove_if_algo<type_list<dummy<0>, dummy<5>, dummy<9>>>;

using l60 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<0>>>;
using l61 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<1>>>;
using l62 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<2>>>;
using l63 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<3>>>;
using l64 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<4>>>;
using l65 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<5>>>;
using l66 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<6>>>;
using l67 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<7>>>;
using l68 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<8>>>;
using l69 = remove_if_algo<type_list<dummy<0>, dummy<6>, dummy<9>>>;

using l70 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<0>>>;
using l71 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<1>>>;
using l72 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<2>>>;
using l73 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<3>>>;
using l74 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<4>>>;
using l75 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<5>>>;
using l76 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<6>>>;
using l77 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<7>>>;
using l78 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<8>>>;
using l79 = remove_if_algo<type_list<dummy<0>, dummy<7>, dummy<9>>>;

using l80 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<0>>>;
using l81 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<1>>>;
using l82 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<2>>>;
using l83 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<3>>>;
using l84 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<4>>>;
using l85 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<5>>>;
using l86 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<6>>>;
using l87 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<7>>>;
using l88 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<8>>>;
using l89 = remove_if_algo<type_list<dummy<0>, dummy<8>, dummy<9>>>;

using l90 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<0>>>;
using l91 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<1>>>;
using l92 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<2>>>;
using l93 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<3>>>;
using l94 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<4>>>;
using l95 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<5>>>;
using l96 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<6>>>;
using l97 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<7>>>;
using l98 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<8>>>;
using l99 = remove_if_algo<type_list<dummy<0>, dummy<9>, dummy<9>>>;

using l100 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<0>>>;
using l101 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<1>>>;
using l102 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<2>>>;
using l103 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<3>>>;
using l104 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<4>>>;
using l105 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<5>>>;
using l106 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<6>>>;
using l107 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<7>>>;
using l108 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<8>>>;
using l109 = remove_if_algo<type_list<dummy<1>, dummy<0>, dummy<9>>>;

using l110 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<0>>>;
using l111 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<1>>>;
using l112 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<2>>>;
using l113 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<3>>>;
using l114 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<4>>>;
using l115 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<5>>>;
using l116 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<6>>>;
using l117 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<7>>>;
using l118 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<8>>>;
using l119 = remove_if_algo<type_list<dummy<1>, dummy<1>, dummy<9>>>;

using l120 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<0>>>;
using l121 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<1>>>;
using l122 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<2>>>;
using l123 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<3>>>;
using l124 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<4>>>;
using l125 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<5>>>;
using l126 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<6>>>;
using l127 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<7>>>;
using l128 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<8>>>;
using l129 = remove_if_algo<type_list<dummy<1>, dummy<2>, dummy<9>>>;

using l130 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<0>>>;
using l131 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<1>>>;
using l132 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<2>>>;
using l133 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<3>>>;
using l134 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<4>>>;
using l135 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<5>>>;
using l136 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<6>>>;
using l137 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<7>>>;
using l138 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<8>>>;
using l139 = remove_if_algo<type_list<dummy<1>, dummy<3>, dummy<9>>>;

using l140 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<0>>>;
using l141 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<1>>>;
using l142 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<2>>>;
using l143 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<3>>>;
using l144 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<4>>>;
using l145 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<5>>>;
using l146 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<6>>>;
using l147 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<7>>>;
using l148 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<8>>>;
using l149 = remove_if_algo<type_list<dummy<1>, dummy<4>, dummy<9>>>;

using l150 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<0>>>;
using l151 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<1>>>;
using l152 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<2>>>;
using l153 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<3>>>;
using l154 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<4>>>;
using l155 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<5>>>;
using l156 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<6>>>;
using l157 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<7>>>;
using l158 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<8>>>;
using l159 = remove_if_algo<type_list<dummy<1>, dummy<5>, dummy<9>>>;

using l160 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<0>>>;
using l161 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<1>>>;
using l162 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<2>>>;
using l163 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<3>>>;
using l164 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<4>>>;
using l165 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<5>>>;
using l166 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<6>>>;
using l167 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<7>>>;
using l168 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<8>>>;
using l169 = remove_if_algo<type_list<dummy<1>, dummy<6>, dummy<9>>>;

using l170 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<0>>>;
using l171 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<1>>>;
using l172 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<2>>>;
using l173 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<3>>>;
using l174 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<4>>>;
using l175 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<5>>>;
using l176 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<6>>>;
using l177 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<7>>>;
using l178 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<8>>>;
using l179 = remove_if_algo<type_list<dummy<1>, dummy<7>, dummy<9>>>;

using l180 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<0>>>;
using l181 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<1>>>;
using l182 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<2>>>;
using l183 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<3>>>;
using l184 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<4>>>;
using l185 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<5>>>;
using l186 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<6>>>;
using l187 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<7>>>;
using l188 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<8>>>;
using l189 = remove_if_algo<type_list<dummy<1>, dummy<8>, dummy<9>>>;

using l190 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<0>>>;
using l191 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<1>>>;
using l192 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<2>>>;
using l193 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<3>>>;
using l194 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<4>>>;
using l195 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<5>>>;
using l196 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<6>>>;
using l197 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<7>>>;
using l198 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<8>>>;
using l199 = remove_if_algo<type_list<dummy<1>, dummy<9>, dummy<9>>>;

using l200 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<0>>>;
using l201 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<1>>>;
using l202 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<2>>>;
using l203 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<3>>>;
using l204 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<4>>>;
using l205 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<5>>>;
using l206 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<6>>>;
using l207 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<7>>>;
using l208 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<8>>>;
using l209 = remove_if_algo<type_list<dummy<2>, dummy<0>, dummy<9>>>;

using l210 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<0>>>;
using l211 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<1>>>;
using l212 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<2>>>;
using l213 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<3>>>;
using l214 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<4>>>;
using l215 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<5>>>;
using l216 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<6>>>;
using l217 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<7>>>;
using l218 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<8>>>;
using l219 = remove_if_algo<type_list<dummy<2>, dummy<1>, dummy<9>>>;

using l220 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<0>>>;
using l221 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<1>>>;
using l222 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<2>>>;
using l223 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<3>>>;
using l224 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<4>>>;
using l225 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<5>>>;
using l226 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<6>>>;
using l227 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<7>>>;
using l228 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<8>>>;
using l229 = remove_if_algo<type_list<dummy<2>, dummy<2>, dummy<9>>>;

using l230 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<0>>>;
using l231 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<1>>>;
using l232 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<2>>>;
using l233 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<3>>>;
using l234 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<4>>>;
using l235 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<5>>>;
using l236 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<6>>>;
using l237 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<7>>>;
using l238 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<8>>>;
using l239 = remove_if_algo<type_list<dummy<2>, dummy<3>, dummy<9>>>;

using l240 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<0>>>;
using l241 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<1>>>;
using l242 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<2>>>;
using l243 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<3>>>;
using l244 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<4>>>;
using l245 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<5>>>;
using l246 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<6>>>;
using l247 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<7>>>;
using l248 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<8>>>;
using l249 = remove_if_algo<type_list<dummy<2>, dummy<4>, dummy<9>>>;

using l250 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<0>>>;
using l251 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<1>>>;
using l252 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<2>>>;
using l253 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<3>>>;
using l254 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<4>>>;
using l255 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<5>>>;
using l256 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<6>>>;
using l257 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<7>>>;
using l258 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<8>>>;
using l259 = remove_if_algo<type_list<dummy<2>, dummy<5>, dummy<9>>>;

using l260 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<0>>>;
using l261 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<1>>>;
using l262 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<2>>>;
using l263 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<3>>>;
using l264 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<4>>>;
using l265 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<5>>>;
using l266 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<6>>>;
using l267 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<7>>>;
using l268 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<8>>>;
using l269 = remove_if_algo<type_list<dummy<2>, dummy<6>, dummy<9>>>;

using l270 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<0>>>;
using l271 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<1>>>;
using l272 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<2>>>;
using l273 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<3>>>;
using l274 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<4>>>;
using l275 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<5>>>;
using l276 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<6>>>;
using l277 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<7>>>;
using l278 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<8>>>;
using l279 = remove_if_algo<type_list<dummy<2>, dummy<7>, dummy<9>>>;

using l280 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<0>>>;
using l281 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<1>>>;
using l282 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<2>>>;
using l283 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<3>>>;
using l284 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<4>>>;
using l285 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<5>>>;
using l286 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<6>>>;
using l287 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<7>>>;
using l288 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<8>>>;
using l289 = remove_if_algo<type_list<dummy<2>, dummy<8>, dummy<9>>>;

using l290 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<0>>>;
using l291 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<1>>>;
using l292 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<2>>>;
using l293 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<3>>>;
using l294 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<4>>>;
using l295 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<5>>>;
using l296 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<6>>>;
using l297 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<7>>>;
using l298 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<8>>>;
using l299 = remove_if_algo<type_list<dummy<2>, dummy<9>, dummy<9>>>;

using l300 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<0>>>;
using l301 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<1>>>;
using l302 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<2>>>;
using l303 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<3>>>;
using l304 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<4>>>;
using l305 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<5>>>;
using l306 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<6>>>;
using l307 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<7>>>;
using l308 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<8>>>;
using l309 = remove_if_algo<type_list<dummy<3>, dummy<0>, dummy<9>>>;

using l310 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<0>>>;
using l311 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<1>>>;
using l312 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<2>>>;
using l313 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<3>>>;
using l314 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<4>>>;
using l315 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<5>>>;
using l316 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<6>>>;
using l317 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<7>>>;
using l318 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<8>>>;
using l319 = remove_if_algo<type_list<dummy<3>, dummy<1>, dummy<9>>>;

using l320 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<0>>>;
using l321 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<1>>>;
using l322 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<2>>>;
using l323 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<3>>>;
using l324 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<4>>>;
using l325 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<5>>>;
using l326 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<6>>>;
using l327 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<7>>>;
using l328 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<8>>>;
using l329 = remove_if_algo<type_list<dummy<3>, dummy<2>, dummy<9>>>;

using l330 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<0>>>;
using l331 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<1>>>;
using l332 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<2>>>;
using l333 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<3>>>;
using l334 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<4>>>;
using l335 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<5>>>;
using l336 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<6>>>;
using l337 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<7>>>;
using l338 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<8>>>;
using l339 = remove_if_algo<type_list<dummy<3>, dummy<3>, dummy<9>>>;

using l340 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<0>>>;
using l341 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<1>>>;
using l342 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<2>>>;
using l343 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<3>>>;
using l344 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<4>>>;
using l345 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<5>>>;
using l346 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<6>>>;
using l347 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<7>>>;
using l348 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<8>>>;
using l349 = remove_if_algo<type_list<dummy<3>, dummy<4>, dummy<9>>>;

using l350 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<0>>>;
using l351 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<1>>>;
using l352 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<2>>>;
using l353 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<3>>>;
using l354 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<4>>>;
using l355 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<5>>>;
using l356 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<6>>>;
using l357 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<7>>>;
using l358 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<8>>>;
using l359 = remove_if_algo<type_list<dummy<3>, dummy<5>, dummy<9>>>;

using l360 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<0>>>;
using l361 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<1>>>;
using l362 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<2>>>;
using l363 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<3>>>;
using l364 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<4>>>;
using l365 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<5>>>;
using l366 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<6>>>;
using l367 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<7>>>;
using l368 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<8>>>;
using l369 = remove_if_algo<type_list<dummy<3>, dummy<6>, dummy<9>>>;

using l370 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<0>>>;
using l371 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<1>>>;
using l372 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<2>>>;
using l373 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<3>>>;
using l374 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<4>>>;
using l375 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<5>>>;
using l376 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<6>>>;
using l377 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<7>>>;
using l378 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<8>>>;
using l379 = remove_if_algo<type_list<dummy<3>, dummy<7>, dummy<9>>>;

using l380 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<0>>>;
using l381 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<1>>>;
using l382 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<2>>>;
using l383 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<3>>>;
using l384 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<4>>>;
using l385 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<5>>>;
using l386 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<6>>>;
using l387 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<7>>>;
using l388 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<8>>>;
using l389 = remove_if_algo<type_list<dummy<3>, dummy<8>, dummy<9>>>;

using l390 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<0>>>;
using l391 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<1>>>;
using l392 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<2>>>;
using l393 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<3>>>;
using l394 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<4>>>;
using l395 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<5>>>;
using l396 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<6>>>;
using l397 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<7>>>;
using l398 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<8>>>;
using l399 = remove_if_algo<type_list<dummy<3>, dummy<9>, dummy<9>>>;

using l400 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<0>>>;
using l401 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<1>>>;
using l402 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<2>>>;
using l403 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<3>>>;
using l404 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<4>>>;
using l405 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<5>>>;
using l406 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<6>>>;
using l407 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<7>>>;
using l408 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<8>>>;
using l409 = remove_if_algo<type_list<dummy<4>, dummy<0>, dummy<9>>>;

using l410 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<0>>>;
using l411 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<1>>>;
using l412 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<2>>>;
using l413 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<3>>>;
using l414 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<4>>>;
using l415 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<5>>>;
using l416 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<6>>>;
using l417 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<7>>>;
using l418 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<8>>>;
using l419 = remove_if_algo<type_list<dummy<4>, dummy<1>, dummy<9>>>;

using l420 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<0>>>;
using l421 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<1>>>;
using l422 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<2>>>;
using l423 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<3>>>;
using l424 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<4>>>;
using l425 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<5>>>;
using l426 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<6>>>;
using l427 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<7>>>;
using l428 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<8>>>;
using l429 = remove_if_algo<type_list<dummy<4>, dummy<2>, dummy<9>>>;

using l430 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<0>>>;
using l431 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<1>>>;
using l432 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<2>>>;
using l433 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<3>>>;
using l434 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<4>>>;
using l435 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<5>>>;
using l436 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<6>>>;
using l437 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<7>>>;
using l438 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<8>>>;
using l439 = remove_if_algo<type_list<dummy<4>, dummy<3>, dummy<9>>>;

using l440 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<0>>>;
using l441 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<1>>>;
using l442 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<2>>>;
using l443 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<3>>>;
using l444 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<4>>>;
using l445 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<5>>>;
using l446 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<6>>>;
using l447 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<7>>>;
using l448 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<8>>>;
using l449 = remove_if_algo<type_list<dummy<4>, dummy<4>, dummy<9>>>;

using l450 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<0>>>;
using l451 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<1>>>;
using l452 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<2>>>;
using l453 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<3>>>;
using l454 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<4>>>;
using l455 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<5>>>;
using l456 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<6>>>;
using l457 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<7>>>;
using l458 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<8>>>;
using l459 = remove_if_algo<type_list<dummy<4>, dummy<5>, dummy<9>>>;

using l460 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<0>>>;
using l461 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<1>>>;
using l462 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<2>>>;
using l463 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<3>>>;
using l464 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<4>>>;
using l465 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<5>>>;
using l466 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<6>>>;
using l467 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<7>>>;
using l468 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<8>>>;
using l469 = remove_if_algo<type_list<dummy<4>, dummy<6>, dummy<9>>>;

using l470 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<0>>>;
using l471 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<1>>>;
using l472 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<2>>>;
using l473 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<3>>>;
using l474 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<4>>>;
using l475 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<5>>>;
using l476 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<6>>>;
using l477 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<7>>>;
using l478 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<8>>>;
using l479 = remove_if_algo<type_list<dummy<4>, dummy<7>, dummy<9>>>;

using l480 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<0>>>;
using l481 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<1>>>;
using l482 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<2>>>;
using l483 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<3>>>;
using l484 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<4>>>;
using l485 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<5>>>;
using l486 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<6>>>;
using l487 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<7>>>;
using l488 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<8>>>;
using l489 = remove_if_algo<type_list<dummy<4>, dummy<8>, dummy<9>>>;

using l490 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<0>>>;
using l491 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<1>>>;
using l492 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<2>>>;
using l493 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<3>>>;
using l494 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<4>>>;
using l495 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<5>>>;
using l496 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<6>>>;
using l497 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<7>>>;
using l498 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<8>>>;
using l499 = remove_if_algo<type_list<dummy<4>, dummy<9>, dummy<9>>>;

using l500 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<0>>>;
using l501 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<1>>>;
using l502 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<2>>>;
using l503 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<3>>>;
using l504 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<4>>>;
using l505 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<5>>>;
using l506 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<6>>>;
using l507 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<7>>>;
using l508 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<8>>>;
using l509 = remove_if_algo<type_list<dummy<5>, dummy<0>, dummy<9>>>;

using l510 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<0>>>;
using l511 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<1>>>;
using l512 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<2>>>;
using l513 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<3>>>;
using l514 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<4>>>;
using l515 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<5>>>;
using l516 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<6>>>;
using l517 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<7>>>;
using l518 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<8>>>;
using l519 = remove_if_algo<type_list<dummy<5>, dummy<1>, dummy<9>>>;

using l520 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<0>>>;
using l521 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<1>>>;
using l522 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<2>>>;
using l523 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<3>>>;
using l524 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<4>>>;
using l525 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<5>>>;
using l526 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<6>>>;
using l527 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<7>>>;
using l528 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<8>>>;
using l529 = remove_if_algo<type_list<dummy<5>, dummy<2>, dummy<9>>>;

using l530 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<0>>>;
using l531 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<1>>>;
using l532 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<2>>>;
using l533 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<3>>>;
using l534 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<4>>>;
using l535 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<5>>>;
using l536 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<6>>>;
using l537 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<7>>>;
using l538 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<8>>>;
using l539 = remove_if_algo<type_list<dummy<5>, dummy<3>, dummy<9>>>;

using l540 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<0>>>;
using l541 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<1>>>;
using l542 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<2>>>;
using l543 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<3>>>;
using l544 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<4>>>;
using l545 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<5>>>;
using l546 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<6>>>;
using l547 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<7>>>;
using l548 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<8>>>;
using l549 = remove_if_algo<type_list<dummy<5>, dummy<4>, dummy<9>>>;

using l550 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<0>>>;
using l551 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<1>>>;
using l552 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<2>>>;
using l553 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<3>>>;
using l554 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<4>>>;
using l555 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<5>>>;
using l556 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<6>>>;
using l557 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<7>>>;
using l558 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<8>>>;
using l559 = remove_if_algo<type_list<dummy<5>, dummy<5>, dummy<9>>>;

using l560 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<0>>>;
using l561 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<1>>>;
using l562 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<2>>>;
using l563 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<3>>>;
using l564 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<4>>>;
using l565 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<5>>>;
using l566 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<6>>>;
using l567 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<7>>>;
using l568 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<8>>>;
using l569 = remove_if_algo<type_list<dummy<5>, dummy<6>, dummy<9>>>;

using l570 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<0>>>;
using l571 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<1>>>;
using l572 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<2>>>;
using l573 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<3>>>;
using l574 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<4>>>;
using l575 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<5>>>;
using l576 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<6>>>;
using l577 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<7>>>;
using l578 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<8>>>;
using l579 = remove_if_algo<type_list<dummy<5>, dummy<7>, dummy<9>>>;

using l580 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<0>>>;
using l581 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<1>>>;
using l582 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<2>>>;
using l583 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<3>>>;
using l584 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<4>>>;
using l585 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<5>>>;
using l586 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<6>>>;
using l587 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<7>>>;
using l588 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<8>>>;
using l589 = remove_if_algo<type_list<dummy<5>, dummy<8>, dummy<9>>>;

using l590 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<0>>>;
using l591 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<1>>>;
using l592 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<2>>>;
using l593 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<3>>>;
using l594 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<4>>>;
using l595 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<5>>>;
using l596 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<6>>>;
using l597 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<7>>>;
using l598 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<8>>>;
using l599 = remove_if_algo<type_list<dummy<5>, dummy<9>, dummy<9>>>;

using l600 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<0>>>;
using l601 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<1>>>;
using l602 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<2>>>;
using l603 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<3>>>;
using l604 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<4>>>;
using l605 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<5>>>;
using l606 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<6>>>;
using l607 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<7>>>;
using l608 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<8>>>;
using l609 = remove_if_algo<type_list<dummy<6>, dummy<0>, dummy<9>>>;

using l610 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<0>>>;
using l611 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<1>>>;
using l612 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<2>>>;
using l613 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<3>>>;
using l614 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<4>>>;
using l615 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<5>>>;
using l616 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<6>>>;
using l617 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<7>>>;
using l618 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<8>>>;
using l619 = remove_if_algo<type_list<dummy<6>, dummy<1>, dummy<9>>>;

using l620 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<0>>>;
using l621 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<1>>>;
using l622 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<2>>>;
using l623 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<3>>>;
using l624 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<4>>>;
using l625 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<5>>>;
using l626 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<6>>>;
using l627 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<7>>>;
using l628 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<8>>>;
using l629 = remove_if_algo<type_list<dummy<6>, dummy<2>, dummy<9>>>;

using l630 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<0>>>;
using l631 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<1>>>;
using l632 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<2>>>;
using l633 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<3>>>;
using l634 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<4>>>;
using l635 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<5>>>;
using l636 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<6>>>;
using l637 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<7>>>;
using l638 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<8>>>;
using l639 = remove_if_algo<type_list<dummy<6>, dummy<3>, dummy<9>>>;

using l640 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<0>>>;
using l641 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<1>>>;
using l642 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<2>>>;
using l643 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<3>>>;
using l644 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<4>>>;
using l645 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<5>>>;
using l646 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<6>>>;
using l647 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<7>>>;
using l648 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<8>>>;
using l649 = remove_if_algo<type_list<dummy<6>, dummy<4>, dummy<9>>>;

using l650 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<0>>>;
using l651 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<1>>>;
using l652 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<2>>>;
using l653 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<3>>>;
using l654 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<4>>>;
using l655 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<5>>>;
using l656 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<6>>>;
using l657 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<7>>>;
using l658 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<8>>>;
using l659 = remove_if_algo<type_list<dummy<6>, dummy<5>, dummy<9>>>;

using l660 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<0>>>;
using l661 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<1>>>;
using l662 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<2>>>;
using l663 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<3>>>;
using l664 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<4>>>;
using l665 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<5>>>;
using l666 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<6>>>;
using l667 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<7>>>;
using l668 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<8>>>;
using l669 = remove_if_algo<type_list<dummy<6>, dummy<6>, dummy<9>>>;

using l670 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<0>>>;
using l671 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<1>>>;
using l672 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<2>>>;
using l673 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<3>>>;
using l674 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<4>>>;
using l675 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<5>>>;
using l676 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<6>>>;
using l677 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<7>>>;
using l678 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<8>>>;
using l679 = remove_if_algo<type_list<dummy<6>, dummy<7>, dummy<9>>>;

using l680 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<0>>>;
using l681 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<1>>>;
using l682 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<2>>>;
using l683 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<3>>>;
using l684 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<4>>>;
using l685 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<5>>>;
using l686 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<6>>>;
using l687 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<7>>>;
using l688 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<8>>>;
using l689 = remove_if_algo<type_list<dummy<6>, dummy<8>, dummy<9>>>;

using l690 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<0>>>;
using l691 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<1>>>;
using l692 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<2>>>;
using l693 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<3>>>;
using l694 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<4>>>;
using l695 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<5>>>;
using l696 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<6>>>;
using l697 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<7>>>;
using l698 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<8>>>;
using l699 = remove_if_algo<type_list<dummy<6>, dummy<9>, dummy<9>>>;

using l700 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<0>>>;
using l701 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<1>>>;
using l702 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<2>>>;
using l703 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<3>>>;
using l704 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<4>>>;
using l705 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<5>>>;
using l706 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<6>>>;
using l707 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<7>>>;
using l708 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<8>>>;
using l709 = remove_if_algo<type_list<dummy<7>, dummy<0>, dummy<9>>>;

using l710 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<0>>>;
using l711 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<1>>>;
using l712 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<2>>>;
using l713 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<3>>>;
using l714 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<4>>>;
using l715 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<5>>>;
using l716 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<6>>>;
using l717 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<7>>>;
using l718 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<8>>>;
using l719 = remove_if_algo<type_list<dummy<7>, dummy<1>, dummy<9>>>;

using l720 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<0>>>;
using l721 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<1>>>;
using l722 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<2>>>;
using l723 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<3>>>;
using l724 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<4>>>;
using l725 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<5>>>;
using l726 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<6>>>;
using l727 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<7>>>;
using l728 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<8>>>;
using l729 = remove_if_algo<type_list<dummy<7>, dummy<2>, dummy<9>>>;

using l730 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<0>>>;
using l731 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<1>>>;
using l732 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<2>>>;
using l733 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<3>>>;
using l734 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<4>>>;
using l735 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<5>>>;
using l736 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<6>>>;
using l737 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<7>>>;
using l738 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<8>>>;
using l739 = remove_if_algo<type_list<dummy<7>, dummy<3>, dummy<9>>>;

using l740 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<0>>>;
using l741 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<1>>>;
using l742 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<2>>>;
using l743 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<3>>>;
using l744 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<4>>>;
using l745 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<5>>>;
using l746 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<6>>>;
using l747 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<7>>>;
using l748 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<8>>>;
using l749 = remove_if_algo<type_list<dummy<7>, dummy<4>, dummy<9>>>;

using l750 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<0>>>;
using l751 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<1>>>;
using l752 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<2>>>;
using l753 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<3>>>;
using l754 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<4>>>;
using l755 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<5>>>;
using l756 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<6>>>;
using l757 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<7>>>;
using l758 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<8>>>;
using l759 = remove_if_algo<type_list<dummy<7>, dummy<5>, dummy<9>>>;

using l760 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<0>>>;
using l761 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<1>>>;
using l762 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<2>>>;
using l763 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<3>>>;
using l764 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<4>>>;
using l765 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<5>>>;
using l766 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<6>>>;
using l767 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<7>>>;
using l768 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<8>>>;
using l769 = remove_if_algo<type_list<dummy<7>, dummy<6>, dummy<9>>>;

using l770 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<0>>>;
using l771 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<1>>>;
using l772 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<2>>>;
using l773 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<3>>>;
using l774 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<4>>>;
using l775 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<5>>>;
using l776 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<6>>>;
using l777 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<7>>>;
using l778 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<8>>>;
using l779 = remove_if_algo<type_list<dummy<7>, dummy<7>, dummy<9>>>;

using l780 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<0>>>;
using l781 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<1>>>;
using l782 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<2>>>;
using l783 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<3>>>;
using l784 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<4>>>;
using l785 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<5>>>;
using l786 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<6>>>;
using l787 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<7>>>;
using l788 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<8>>>;
using l789 = remove_if_algo<type_list<dummy<7>, dummy<8>, dummy<9>>>;

using l790 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<0>>>;
using l791 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<1>>>;
using l792 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<2>>>;
using l793 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<3>>>;
using l794 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<4>>>;
using l795 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<5>>>;
using l796 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<6>>>;
using l797 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<7>>>;
using l798 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<8>>>;
using l799 = remove_if_algo<type_list<dummy<7>, dummy<9>, dummy<9>>>;

using l800 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<0>>>;
using l801 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<1>>>;
using l802 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<2>>>;
using l803 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<3>>>;
using l804 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<4>>>;
using l805 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<5>>>;
using l806 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<6>>>;
using l807 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<7>>>;
using l808 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<8>>>;
using l809 = remove_if_algo<type_list<dummy<8>, dummy<0>, dummy<9>>>;

using l810 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<0>>>;
using l811 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<1>>>;
using l812 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<2>>>;
using l813 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<3>>>;
using l814 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<4>>>;
using l815 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<5>>>;
using l816 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<6>>>;
using l817 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<7>>>;
using l818 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<8>>>;
using l819 = remove_if_algo<type_list<dummy<8>, dummy<1>, dummy<9>>>;

using l820 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<0>>>;
using l821 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<1>>>;
using l822 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<2>>>;
using l823 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<3>>>;
using l824 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<4>>>;
using l825 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<5>>>;
using l826 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<6>>>;
using l827 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<7>>>;
using l828 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<8>>>;
using l829 = remove_if_algo<type_list<dummy<8>, dummy<2>, dummy<9>>>;

using l830 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<0>>>;
using l831 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<1>>>;
using l832 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<2>>>;
using l833 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<3>>>;
using l834 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<4>>>;
using l835 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<5>>>;
using l836 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<6>>>;
using l837 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<7>>>;
using l838 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<8>>>;
using l839 = remove_if_algo<type_list<dummy<8>, dummy<3>, dummy<9>>>;

using l840 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<0>>>;
using l841 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<1>>>;
using l842 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<2>>>;
using l843 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<3>>>;
using l844 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<4>>>;
using l845 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<5>>>;
using l846 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<6>>>;
using l847 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<7>>>;
using l848 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<8>>>;
using l849 = remove_if_algo<type_list<dummy<8>, dummy<4>, dummy<9>>>;

using l850 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<0>>>;
using l851 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<1>>>;
using l852 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<2>>>;
using l853 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<3>>>;
using l854 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<4>>>;
using l855 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<5>>>;
using l856 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<6>>>;
using l857 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<7>>>;
using l858 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<8>>>;
using l859 = remove_if_algo<type_list<dummy<8>, dummy<5>, dummy<9>>>;

using l860 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<0>>>;
using l861 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<1>>>;
using l862 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<2>>>;
using l863 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<3>>>;
using l864 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<4>>>;
using l865 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<5>>>;
using l866 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<6>>>;
using l867 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<7>>>;
using l868 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<8>>>;
using l869 = remove_if_algo<type_list<dummy<8>, dummy<6>, dummy<9>>>;

using l870 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<0>>>;
using l871 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<1>>>;
using l872 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<2>>>;
using l873 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<3>>>;
using l874 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<4>>>;
using l875 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<5>>>;
using l876 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<6>>>;
using l877 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<7>>>;
using l878 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<8>>>;
using l879 = remove_if_algo<type_list<dummy<8>, dummy<7>, dummy<9>>>;

using l880 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<0>>>;
using l881 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<1>>>;
using l882 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<2>>>;
using l883 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<3>>>;
using l884 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<4>>>;
using l885 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<5>>>;
using l886 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<6>>>;
using l887 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<7>>>;
using l888 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<8>>>;
using l889 = remove_if_algo<type_list<dummy<8>, dummy<8>, dummy<9>>>;

using l890 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<0>>>;
using l891 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<1>>>;
using l892 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<2>>>;
using l893 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<3>>>;
using l894 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<4>>>;
using l895 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<5>>>;
using l896 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<6>>>;
using l897 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<7>>>;
using l898 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<8>>>;
using l899 = remove_if_algo<type_list<dummy<8>, dummy<9>, dummy<9>>>;

using l900 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<0>>>;
using l901 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<1>>>;
using l902 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<2>>>;
using l903 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<3>>>;
using l904 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<4>>>;
using l905 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<5>>>;
using l906 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<6>>>;
using l907 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<7>>>;
using l908 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<8>>>;
using l909 = remove_if_algo<type_list<dummy<9>, dummy<0>, dummy<9>>>;

using l910 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<0>>>;
using l911 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<1>>>;
using l912 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<2>>>;
using l913 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<3>>>;
using l914 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<4>>>;
using l915 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<5>>>;
using l916 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<6>>>;
using l917 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<7>>>;
using l918 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<8>>>;
using l919 = remove_if_algo<type_list<dummy<9>, dummy<1>, dummy<9>>>;

using l920 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<0>>>;
using l921 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<1>>>;
using l922 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<2>>>;
using l923 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<3>>>;
using l924 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<4>>>;
using l925 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<5>>>;
using l926 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<6>>>;
using l927 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<7>>>;
using l928 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<8>>>;
using l929 = remove_if_algo<type_list<dummy<9>, dummy<2>, dummy<9>>>;

using l930 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<0>>>;
using l931 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<1>>>;
using l932 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<2>>>;
using l933 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<3>>>;
using l934 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<4>>>;
using l935 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<5>>>;
using l936 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<6>>>;
using l937 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<7>>>;
using l938 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<8>>>;
using l939 = remove_if_algo<type_list<dummy<9>, dummy<3>, dummy<9>>>;

using l940 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<0>>>;
using l941 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<1>>>;
using l942 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<2>>>;
using l943 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<3>>>;
using l944 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<4>>>;
using l945 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<5>>>;
using l946 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<6>>>;
using l947 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<7>>>;
using l948 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<8>>>;
using l949 = remove_if_algo<type_list<dummy<9>, dummy<4>, dummy<9>>>;

using l950 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<0>>>;
using l951 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<1>>>;
using l952 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<2>>>;
using l953 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<3>>>;
using l954 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<4>>>;
using l955 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<5>>>;
using l956 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<6>>>;
using l957 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<7>>>;
using l958 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<8>>>;
using l959 = remove_if_algo<type_list<dummy<9>, dummy<5>, dummy<9>>>;

using l960 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<0>>>;
using l961 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<1>>>;
using l962 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<2>>>;
using l963 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<3>>>;
using l964 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<4>>>;
using l965 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<5>>>;
using l966 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<6>>>;
using l967 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<7>>>;
using l968 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<8>>>;
using l969 = remove_if_algo<type_list<dummy<9>, dummy<6>, dummy<9>>>;

using l970 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<0>>>;
using l971 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<1>>>;
using l972 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<2>>>;
using l973 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<3>>>;
using l974 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<4>>>;
using l975 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<5>>>;
using l976 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<6>>>;
using l977 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<7>>>;
using l978 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<8>>>;
using l979 = remove_if_algo<type_list<dummy<9>, dummy<7>, dummy<9>>>;

using l980 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<0>>>;
using l981 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<1>>>;
using l982 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<2>>>;
using l983 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<3>>>;
using l984 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<4>>>;
using l985 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<5>>>;
using l986 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<6>>>;
using l987 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<7>>>;
using l988 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<8>>>;
using l989 = remove_if_algo<type_list<dummy<9>, dummy<8>, dummy<9>>>;

using l990 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<0>>>;
using l991 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<1>>>;
using l992 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<2>>>;
using l993 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<3>>>;
using l994 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<4>>>;
using l995 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<5>>>;
using l996 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<6>>>;
using l997 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<7>>>;
using l998 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<8>>>;
using l999 = remove_if_algo<type_list<dummy<9>, dummy<9>, dummy<9>>>;

// force instantiations

l0 my_l0;
l1 my_l1;
l2 my_l2;
l3 my_l3;
l4 my_l4;
l5 my_l5;
l6 my_l6;
l7 my_l7;
l8 my_l8;
l9 my_l9;

l10 my_l10;
l11 my_l11;
l12 my_l12;
l13 my_l13;
l14 my_l14;
l15 my_l15;
l16 my_l16;
l17 my_l17;
l18 my_l18;
l19 my_l19;

l20 my_l20;
l21 my_l21;
l22 my_l22;
l23 my_l23;
l24 my_l24;
l25 my_l25;
l26 my_l26;
l27 my_l27;
l28 my_l28;
l29 my_l29;

l30 my_l30;
l31 my_l31;
l32 my_l32;
l33 my_l33;
l34 my_l34;
l35 my_l35;
l36 my_l36;
l37 my_l37;
l38 my_l38;
l39 my_l39;

l40 my_l40;
l41 my_l41;
l42 my_l42;
l43 my_l43;
l44 my_l44;
l45 my_l45;
l46 my_l46;
l47 my_l47;
l48 my_l48;
l49 my_l49;

l50 my_l50;
l51 my_l51;
l52 my_l52;
l53 my_l53;
l54 my_l54;
l55 my_l55;
l56 my_l56;
l57 my_l57;
l58 my_l58;
l59 my_l59;

l60 my_l60;
l61 my_l61;
l62 my_l62;
l63 my_l63;
l64 my_l64;
l65 my_l65;
l66 my_l66;
l67 my_l67;
l68 my_l68;
l69 my_l69;

l70 my_l70;
l71 my_l71;
l72 my_l72;
l73 my_l73;
l74 my_l74;
l75 my_l75;
l76 my_l76;
l77 my_l77;
l78 my_l78;
l79 my_l79;

l80 my_l80;
l81 my_l81;
l82 my_l82;
l83 my_l83;
l84 my_l84;
l85 my_l85;
l86 my_l86;
l87 my_l87;
l88 my_l88;
l89 my_l89;

l90 my_l90;
l91 my_l91;
l92 my_l92;
l93 my_l93;
l94 my_l94;
l95 my_l95;
l96 my_l96;
l97 my_l97;
l98 my_l98;
l99 my_l99;

l100 my_l100;
l101 my_l101;
l102 my_l102;
l103 my_l103;
l104 my_l104;
l105 my_l105;
l106 my_l106;
l107 my_l107;
l108 my_l108;
l109 my_l109;

l110 my_l110;
l111 my_l111;
l112 my_l112;
l113 my_l113;
l114 my_l114;
l115 my_l115;
l116 my_l116;
l117 my_l117;
l118 my_l118;
l119 my_l119;

l120 my_l120;
l121 my_l121;
l122 my_l122;
l123 my_l123;
l124 my_l124;
l125 my_l125;
l126 my_l126;
l127 my_l127;
l128 my_l128;
l129 my_l129;

l130 my_l130;
l131 my_l131;
l132 my_l132;
l133 my_l133;
l134 my_l134;
l135 my_l135;
l136 my_l136;
l137 my_l137;
l138 my_l138;
l139 my_l139;

l140 my_l140;
l141 my_l141;
l142 my_l142;
l143 my_l143;
l144 my_l144;
l145 my_l145;
l146 my_l146;
l147 my_l147;
l148 my_l148;
l149 my_l149;

l150 my_l150;
l151 my_l151;
l152 my_l152;
l153 my_l153;
l154 my_l154;
l155 my_l155;
l156 my_l156;
l157 my_l157;
l158 my_l158;
l159 my_l159;

l160 my_l160;
l161 my_l161;
l162 my_l162;
l163 my_l163;
l164 my_l164;
l165 my_l165;
l166 my_l166;
l167 my_l167;
l168 my_l168;
l169 my_l169;

l170 my_l170;
l171 my_l171;
l172 my_l172;
l173 my_l173;
l174 my_l174;
l175 my_l175;
l176 my_l176;
l177 my_l177;
l178 my_l178;
l179 my_l179;

l180 my_l180;
l181 my_l181;
l182 my_l182;
l183 my_l183;
l184 my_l184;
l185 my_l185;
l186 my_l186;
l187 my_l187;
l188 my_l188;
l189 my_l189;

l190 my_l190;
l191 my_l191;
l192 my_l192;
l193 my_l193;
l194 my_l194;
l195 my_l195;
l196 my_l196;
l197 my_l197;
l198 my_l198;
l199 my_l199;

l200 my_l200;
l201 my_l201;
l202 my_l202;
l203 my_l203;
l204 my_l204;
l205 my_l205;
l206 my_l206;
l207 my_l207;
l208 my_l208;
l209 my_l209;

l210 my_l210;
l211 my_l211;
l212 my_l212;
l213 my_l213;
l214 my_l214;
l215 my_l215;
l216 my_l216;
l217 my_l217;
l218 my_l218;
l219 my_l219;

l220 my_l220;
l221 my_l221;
l222 my_l222;
l223 my_l223;
l224 my_l224;
l225 my_l225;
l226 my_l226;
l227 my_l227;
l228 my_l228;
l229 my_l229;

l230 my_l230;
l231 my_l231;
l232 my_l232;
l233 my_l233;
l234 my_l234;
l235 my_l235;
l236 my_l236;
l237 my_l237;
l238 my_l238;
l239 my_l239;

l240 my_l240;
l241 my_l241;
l242 my_l242;
l243 my_l243;
l244 my_l244;
l245 my_l245;
l246 my_l246;
l247 my_l247;
l248 my_l248;
l249 my_l249;

l250 my_l250;
l251 my_l251;
l252 my_l252;
l253 my_l253;
l254 my_l254;
l255 my_l255;
l256 my_l256;
l257 my_l257;
l258 my_l258;
l259 my_l259;

l260 my_l260;
l261 my_l261;
l262 my_l262;
l263 my_l263;
l264 my_l264;
l265 my_l265;
l266 my_l266;
l267 my_l267;
l268 my_l268;
l269 my_l269;

l270 my_l270;
l271 my_l271;
l272 my_l272;
l273 my_l273;
l274 my_l274;
l275 my_l275;
l276 my_l276;
l277 my_l277;
l278 my_l278;
l279 my_l279;

l280 my_l280;
l281 my_l281;
l282 my_l282;
l283 my_l283;
l284 my_l284;
l285 my_l285;
l286 my_l286;
l287 my_l287;
l288 my_l288;
l289 my_l289;

l290 my_l290;
l291 my_l291;
l292 my_l292;
l293 my_l293;
l294 my_l294;
l295 my_l295;
l296 my_l296;
l297 my_l297;
l298 my_l298;
l299 my_l299;

l300 my_l300;
l301 my_l301;
l302 my_l302;
l303 my_l303;
l304 my_l304;
l305 my_l305;
l306 my_l306;
l307 my_l307;
l308 my_l308;
l309 my_l309;

l310 my_l310;
l311 my_l311;
l312 my_l312;
l313 my_l313;
l314 my_l314;
l315 my_l315;
l316 my_l316;
l317 my_l317;
l318 my_l318;
l319 my_l319;

l320 my_l320;
l321 my_l321;
l322 my_l322;
l323 my_l323;
l324 my_l324;
l325 my_l325;
l326 my_l326;
l327 my_l327;
l328 my_l328;
l329 my_l329;

l330 my_l330;
l331 my_l331;
l332 my_l332;
l333 my_l333;
l334 my_l334;
l335 my_l335;
l336 my_l336;
l337 my_l337;
l338 my_l338;
l339 my_l339;

l340 my_l340;
l341 my_l341;
l342 my_l342;
l343 my_l343;
l344 my_l344;
l345 my_l345;
l346 my_l346;
l347 my_l347;
l348 my_l348;
l349 my_l349;

l350 my_l350;
l351 my_l351;
l352 my_l352;
l353 my_l353;
l354 my_l354;
l355 my_l355;
l356 my_l356;
l357 my_l357;
l358 my_l358;
l359 my_l359;

l360 my_l360;
l361 my_l361;
l362 my_l362;
l363 my_l363;
l364 my_l364;
l365 my_l365;
l366 my_l366;
l367 my_l367;
l368 my_l368;
l369 my_l369;

l370 my_l370;
l371 my_l371;
l372 my_l372;
l373 my_l373;
l374 my_l374;
l375 my_l375;
l376 my_l376;
l377 my_l377;
l378 my_l378;
l379 my_l379;

l380 my_l380;
l381 my_l381;
l382 my_l382;
l383 my_l383;
l384 my_l384;
l385 my_l385;
l386 my_l386;
l387 my_l387;
l388 my_l388;
l389 my_l389;

l390 my_l390;
l391 my_l391;
l392 my_l392;
l393 my_l393;
l394 my_l394;
l395 my_l395;
l396 my_l396;
l397 my_l397;
l398 my_l398;
l399 my_l399;

l400 my_l400;
l401 my_l401;
l402 my_l402;
l403 my_l403;
l404 my_l404;
l405 my_l405;
l406 my_l406;
l407 my_l407;
l408 my_l408;
l409 my_l409;

l410 my_l410;
l411 my_l411;
l412 my_l412;
l413 my_l413;
l414 my_l414;
l415 my_l415;
l416 my_l416;
l417 my_l417;
l418 my_l418;
l419 my_l419;

l420 my_l420;
l421 my_l421;
l422 my_l422;
l423 my_l423;
l424 my_l424;
l425 my_l425;
l426 my_l426;
l427 my_l427;
l428 my_l428;
l429 my_l429;

l430 my_l430;
l431 my_l431;
l432 my_l432;
l433 my_l433;
l434 my_l434;
l435 my_l435;
l436 my_l436;
l437 my_l437;
l438 my_l438;
l439 my_l439;

l440 my_l440;
l441 my_l441;
l442 my_l442;
l443 my_l443;
l444 my_l444;
l445 my_l445;
l446 my_l446;
l447 my_l447;
l448 my_l448;
l449 my_l449;

l450 my_l450;
l451 my_l451;
l452 my_l452;
l453 my_l453;
l454 my_l454;
l455 my_l455;
l456 my_l456;
l457 my_l457;
l458 my_l458;
l459 my_l459;

l460 my_l460;
l461 my_l461;
l462 my_l462;
l463 my_l463;
l464 my_l464;
l465 my_l465;
l466 my_l466;
l467 my_l467;
l468 my_l468;
l469 my_l469;

l470 my_l470;
l471 my_l471;
l472 my_l472;
l473 my_l473;
l474 my_l474;
l475 my_l475;
l476 my_l476;
l477 my_l477;
l478 my_l478;
l479 my_l479;

l480 my_l480;
l481 my_l481;
l482 my_l482;
l483 my_l483;
l484 my_l484;
l485 my_l485;
l486 my_l486;
l487 my_l487;
l488 my_l488;
l489 my_l489;

l490 my_l490;
l491 my_l491;
l492 my_l492;
l493 my_l493;
l494 my_l494;
l495 my_l495;
l496 my_l496;
l497 my_l497;
l498 my_l498;
l499 my_l499;

l500 my_l500;
l501 my_l501;
l502 my_l502;
l503 my_l503;
l504 my_l504;
l505 my_l505;
l506 my_l506;
l507 my_l507;
l508 my_l508;
l509 my_l509;

l510 my_l510;
l511 my_l511;
l512 my_l512;
l513 my_l513;
l514 my_l514;
l515 my_l515;
l516 my_l516;
l517 my_l517;
l518 my_l518;
l519 my_l519;

l520 my_l520;
l521 my_l521;
l522 my_l522;
l523 my_l523;
l524 my_l524;
l525 my_l525;
l526 my_l526;
l527 my_l527;
l528 my_l528;
l529 my_l529;

l530 my_l530;
l531 my_l531;
l532 my_l532;
l533 my_l533;
l534 my_l534;
l535 my_l535;
l536 my_l536;
l537 my_l537;
l538 my_l538;
l539 my_l539;

l540 my_l540;
l541 my_l541;
l542 my_l542;
l543 my_l543;
l544 my_l544;
l545 my_l545;
l546 my_l546;
l547 my_l547;
l548 my_l548;
l549 my_l549;

l550 my_l550;
l551 my_l551;
l552 my_l552;
l553 my_l553;
l554 my_l554;
l555 my_l555;
l556 my_l556;
l557 my_l557;
l558 my_l558;
l559 my_l559;

l560 my_l560;
l561 my_l561;
l562 my_l562;
l563 my_l563;
l564 my_l564;
l565 my_l565;
l566 my_l566;
l567 my_l567;
l568 my_l568;
l569 my_l569;

l570 my_l570;
l571 my_l571;
l572 my_l572;
l573 my_l573;
l574 my_l574;
l575 my_l575;
l576 my_l576;
l577 my_l577;
l578 my_l578;
l579 my_l579;

l580 my_l580;
l581 my_l581;
l582 my_l582;
l583 my_l583;
l584 my_l584;
l585 my_l585;
l586 my_l586;
l587 my_l587;
l588 my_l588;
l589 my_l589;

l590 my_l590;
l591 my_l591;
l592 my_l592;
l593 my_l593;
l594 my_l594;
l595 my_l595;
l596 my_l596;
l597 my_l597;
l598 my_l598;
l599 my_l599;

l600 my_l600;
l601 my_l601;
l602 my_l602;
l603 my_l603;
l604 my_l604;
l605 my_l605;
l606 my_l606;
l607 my_l607;
l608 my_l608;
l609 my_l609;

l610 my_l610;
l611 my_l611;
l612 my_l612;
l613 my_l613;
l614 my_l614;
l615 my_l615;
l616 my_l616;
l617 my_l617;
l618 my_l618;
l619 my_l619;

l620 my_l620;
l621 my_l621;
l622 my_l622;
l623 my_l623;
l624 my_l624;
l625 my_l625;
l626 my_l626;
l627 my_l627;
l628 my_l628;
l629 my_l629;

l630 my_l630;
l631 my_l631;
l632 my_l632;
l633 my_l633;
l634 my_l634;
l635 my_l635;
l636 my_l636;
l637 my_l637;
l638 my_l638;
l639 my_l639;

l640 my_l640;
l641 my_l641;
l642 my_l642;
l643 my_l643;
l644 my_l644;
l645 my_l645;
l646 my_l646;
l647 my_l647;
l648 my_l648;
l649 my_l649;

l650 my_l650;
l651 my_l651;
l652 my_l652;
l653 my_l653;
l654 my_l654;
l655 my_l655;
l656 my_l656;
l657 my_l657;
l658 my_l658;
l659 my_l659;

l660 my_l660;
l661 my_l661;
l662 my_l662;
l663 my_l663;
l664 my_l664;
l665 my_l665;
l666 my_l666;
l667 my_l667;
l668 my_l668;
l669 my_l669;

l670 my_l670;
l671 my_l671;
l672 my_l672;
l673 my_l673;
l674 my_l674;
l675 my_l675;
l676 my_l676;
l677 my_l677;
l678 my_l678;
l679 my_l679;

l680 my_l680;
l681 my_l681;
l682 my_l682;
l683 my_l683;
l684 my_l684;
l685 my_l685;
l686 my_l686;
l687 my_l687;
l688 my_l688;
l689 my_l689;

l690 my_l690;
l691 my_l691;
l692 my_l692;
l693 my_l693;
l694 my_l694;
l695 my_l695;
l696 my_l696;
l697 my_l697;
l698 my_l698;
l699 my_l699;

l700 my_l700;
l701 my_l701;
l702 my_l702;
l703 my_l703;
l704 my_l704;
l705 my_l705;
l706 my_l706;
l707 my_l707;
l708 my_l708;
l709 my_l709;

l710 my_l710;
l711 my_l711;
l712 my_l712;
l713 my_l713;
l714 my_l714;
l715 my_l715;
l716 my_l716;
l717 my_l717;
l718 my_l718;
l719 my_l719;

l720 my_l720;
l721 my_l721;
l722 my_l722;
l723 my_l723;
l724 my_l724;
l725 my_l725;
l726 my_l726;
l727 my_l727;
l728 my_l728;
l729 my_l729;

l730 my_l730;
l731 my_l731;
l732 my_l732;
l733 my_l733;
l734 my_l734;
l735 my_l735;
l736 my_l736;
l737 my_l737;
l738 my_l738;
l739 my_l739;

l740 my_l740;
l741 my_l741;
l742 my_l742;
l743 my_l743;
l744 my_l744;
l745 my_l745;
l746 my_l746;
l747 my_l747;
l748 my_l748;
l749 my_l749;

l750 my_l750;
l751 my_l751;
l752 my_l752;
l753 my_l753;
l754 my_l754;
l755 my_l755;
l756 my_l756;
l757 my_l757;
l758 my_l758;
l759 my_l759;

l760 my_l760;
l761 my_l761;
l762 my_l762;
l763 my_l763;
l764 my_l764;
l765 my_l765;
l766 my_l766;
l767 my_l767;
l768 my_l768;
l769 my_l769;

l770 my_l770;
l771 my_l771;
l772 my_l772;
l773 my_l773;
l774 my_l774;
l775 my_l775;
l776 my_l776;
l777 my_l777;
l778 my_l778;
l779 my_l779;

l780 my_l780;
l781 my_l781;
l782 my_l782;
l783 my_l783;
l784 my_l784;
l785 my_l785;
l786 my_l786;
l787 my_l787;
l788 my_l788;
l789 my_l789;

l790 my_l790;
l791 my_l791;
l792 my_l792;
l793 my_l793;
l794 my_l794;
l795 my_l795;
l796 my_l796;
l797 my_l797;
l798 my_l798;
l799 my_l799;

l800 my_l800;
l801 my_l801;
l802 my_l802;
l803 my_l803;
l804 my_l804;
l805 my_l805;
l806 my_l806;
l807 my_l807;
l808 my_l808;
l809 my_l809;

l810 my_l810;
l811 my_l811;
l812 my_l812;
l813 my_l813;
l814 my_l814;
l815 my_l815;
l816 my_l816;
l817 my_l817;
l818 my_l818;
l819 my_l819;

l820 my_l820;
l821 my_l821;
l822 my_l822;
l823 my_l823;
l824 my_l824;
l825 my_l825;
l826 my_l826;
l827 my_l827;
l828 my_l828;
l829 my_l829;

l830 my_l830;
l831 my_l831;
l832 my_l832;
l833 my_l833;
l834 my_l834;
l835 my_l835;
l836 my_l836;
l837 my_l837;
l838 my_l838;
l839 my_l839;

l840 my_l840;
l841 my_l841;
l842 my_l842;
l843 my_l843;
l844 my_l844;
l845 my_l845;
l846 my_l846;
l847 my_l847;
l848 my_l848;
l849 my_l849;

l850 my_l850;
l851 my_l851;
l852 my_l852;
l853 my_l853;
l854 my_l854;
l855 my_l855;
l856 my_l856;
l857 my_l857;
l858 my_l858;
l859 my_l859;

l860 my_l860;
l861 my_l861;
l862 my_l862;
l863 my_l863;
l864 my_l864;
l865 my_l865;
l866 my_l866;
l867 my_l867;
l868 my_l868;
l869 my_l869;

l870 my_l870;
l871 my_l871;
l872 my_l872;
l873 my_l873;
l874 my_l874;
l875 my_l875;
l876 my_l876;
l877 my_l877;
l878 my_l878;
l879 my_l879;

l880 my_l880;
l881 my_l881;
l882 my_l882;
l883 my_l883;
l884 my_l884;
l885 my_l885;
l886 my_l886;
l887 my_l887;
l888 my_l888;
l889 my_l889;

l890 my_l890;
l891 my_l891;
l892 my_l892;
l893 my_l893;
l894 my_l894;
l895 my_l895;
l896 my_l896;
l897 my_l897;
l898 my_l898;
l899 my_l899;

l900 my_l900;
l901 my_l901;
l902 my_l902;
l903 my_l903;
l904 my_l904;
l905 my_l905;
l906 my_l906;
l907 my_l907;
l908 my_l908;
l909 my_l909;

l910 my_l910;
l911 my_l911;
l912 my_l912;
l913 my_l913;
l914 my_l914;
l915 my_l915;
l916 my_l916;
l917 my_l917;
l918 my_l918;
l919 my_l919;

l920 my_l920;
l921 my_l921;
l922 my_l922;
l923 my_l923;
l924 my_l924;
l925 my_l925;
l926 my_l926;
l927 my_l927;
l928 my_l928;
l929 my_l929;

l930 my_l930;
l931 my_l931;
l932 my_l932;
l933 my_l933;
l934 my_l934;
l935 my_l935;
l936 my_l936;
l937 my_l937;
l938 my_l938;
l939 my_l939;

l940 my_l940;
l941 my_l941;
l942 my_l942;
l943 my_l943;
l944 my_l944;
l945 my_l945;
l946 my_l946;
l947 my_l947;
l948 my_l948;
l949 my_l949;

l950 my_l950;
l951 my_l951;
l952 my_l952;
l953 my_l953;
l954 my_l954;
l955 my_l955;
l956 my_l956;
l957 my_l957;
l958 my_l958;
l959 my_l959;

l960 my_l960;
l961 my_l961;
l962 my_l962;
l963 my_l963;
l964 my_l964;
l965 my_l965;
l966 my_l966;
l967 my_l967;
l968 my_l968;
l969 my_l969;

l970 my_l970;
l971 my_l971;
l972 my_l972;
l973 my_l973;
l974 my_l974;
l975 my_l975;
l976 my_l976;
l977 my_l977;
l978 my_l978;
l979 my_l979;

l980 my_l980;
l981 my_l981;
l982 my_l982;
l983 my_l983;
l984 my_l984;
l985 my_l985;
l986 my_l986;
l987 my_l987;
l988 my_l988;
l989 my_l989;

l990 my_l990;
l991 my_l991;
l992 my_l992;
l993 my_l993;
l994 my_l994;
l995 my_l995;
l996 my_l996;
l997 my_l997;
l998 my_l998;
l999 my_l999;


}  // namespace bits_of_q::small_input_benchmark