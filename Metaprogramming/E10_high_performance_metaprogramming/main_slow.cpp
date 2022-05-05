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


namespace bits_of_q {
template <bool condition, typename THEN, typename ELSE>
struct if_;

template <typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> {
	using type = THEN;
};

template <typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> {
	using type = ELSE;
};

}  // namespace bits_of_q

struct A {};
struct B {};
struct C {};
struct D {};
struct E {};
struct F {};
struct G {};
struct H {};
struct I {};
struct J {};

int main() {
	using namespace bits_of_q;
	[[maybe_unused]] typename if_<true, A, A>::type t0;
	[[maybe_unused]] typename if_<true, B, A>::type t1;
	[[maybe_unused]] typename if_<true, C, A>::type t2;
	[[maybe_unused]] typename if_<true, D, A>::type t3;
	[[maybe_unused]] typename if_<true, E, A>::type t4;
	[[maybe_unused]] typename if_<true, F, A>::type t5;
	[[maybe_unused]] typename if_<true, G, A>::type t6;
	[[maybe_unused]] typename if_<true, H, A>::type t7;
	[[maybe_unused]] typename if_<true, I, A>::type t8;
	[[maybe_unused]] typename if_<true, J, A>::type t9;
	[[maybe_unused]] typename if_<true, A, B>::type t10;
	[[maybe_unused]] typename if_<true, B, B>::type t11;
	[[maybe_unused]] typename if_<true, C, B>::type t12;
	[[maybe_unused]] typename if_<true, D, B>::type t13;
	[[maybe_unused]] typename if_<true, E, B>::type t14;
	[[maybe_unused]] typename if_<true, F, B>::type t15;
	[[maybe_unused]] typename if_<true, G, B>::type t16;
	[[maybe_unused]] typename if_<true, H, B>::type t17;
	[[maybe_unused]] typename if_<true, I, B>::type t18;
	[[maybe_unused]] typename if_<true, J, B>::type t19;
	[[maybe_unused]] typename if_<true, A, C>::type t20;
	[[maybe_unused]] typename if_<true, B, C>::type t21;
	[[maybe_unused]] typename if_<true, C, C>::type t22;
	[[maybe_unused]] typename if_<true, D, C>::type t23;
	[[maybe_unused]] typename if_<true, E, C>::type t24;
	[[maybe_unused]] typename if_<true, F, C>::type t25;
	[[maybe_unused]] typename if_<true, G, C>::type t26;
	[[maybe_unused]] typename if_<true, H, C>::type t27;
	[[maybe_unused]] typename if_<true, I, C>::type t28;
	[[maybe_unused]] typename if_<true, J, C>::type t29;
	[[maybe_unused]] typename if_<true, A, D>::type t30;
	[[maybe_unused]] typename if_<true, B, D>::type t31;
	[[maybe_unused]] typename if_<true, C, D>::type t32;
	[[maybe_unused]] typename if_<true, D, D>::type t33;
	[[maybe_unused]] typename if_<true, E, D>::type t34;
	[[maybe_unused]] typename if_<true, F, D>::type t35;
	[[maybe_unused]] typename if_<true, G, D>::type t36;
	[[maybe_unused]] typename if_<true, H, D>::type t37;
	[[maybe_unused]] typename if_<true, I, D>::type t38;
	[[maybe_unused]] typename if_<true, J, D>::type t39;
	[[maybe_unused]] typename if_<true, A, E>::type t40;
	[[maybe_unused]] typename if_<true, B, E>::type t41;
	[[maybe_unused]] typename if_<true, C, E>::type t42;
	[[maybe_unused]] typename if_<true, D, E>::type t43;
	[[maybe_unused]] typename if_<true, E, E>::type t44;
	[[maybe_unused]] typename if_<true, F, E>::type t45;
	[[maybe_unused]] typename if_<true, G, E>::type t46;
	[[maybe_unused]] typename if_<true, H, E>::type t47;
	[[maybe_unused]] typename if_<true, I, E>::type t48;
	[[maybe_unused]] typename if_<true, J, E>::type t49;
	[[maybe_unused]] typename if_<true, A, F>::type t50;
	[[maybe_unused]] typename if_<true, B, F>::type t51;
	[[maybe_unused]] typename if_<true, C, F>::type t52;
	[[maybe_unused]] typename if_<true, D, F>::type t53;
	[[maybe_unused]] typename if_<true, E, F>::type t54;
	[[maybe_unused]] typename if_<true, F, F>::type t55;
	[[maybe_unused]] typename if_<true, G, F>::type t56;
	[[maybe_unused]] typename if_<true, H, F>::type t57;
	[[maybe_unused]] typename if_<true, I, F>::type t58;
	[[maybe_unused]] typename if_<true, J, F>::type t59;
	[[maybe_unused]] typename if_<true, A, G>::type t60;
	[[maybe_unused]] typename if_<true, B, G>::type t61;
	[[maybe_unused]] typename if_<true, C, G>::type t62;
	[[maybe_unused]] typename if_<true, D, G>::type t63;
	[[maybe_unused]] typename if_<true, E, G>::type t64;
	[[maybe_unused]] typename if_<true, F, G>::type t65;
	[[maybe_unused]] typename if_<true, G, G>::type t66;
	[[maybe_unused]] typename if_<true, H, G>::type t67;
	[[maybe_unused]] typename if_<true, I, G>::type t68;
	[[maybe_unused]] typename if_<true, J, G>::type t69;
	[[maybe_unused]] typename if_<true, A, H>::type t70;
	[[maybe_unused]] typename if_<true, B, H>::type t71;
	[[maybe_unused]] typename if_<true, C, H>::type t72;
	[[maybe_unused]] typename if_<true, D, H>::type t73;
	[[maybe_unused]] typename if_<true, E, H>::type t74;
	[[maybe_unused]] typename if_<true, F, H>::type t75;
	[[maybe_unused]] typename if_<true, G, H>::type t76;
	[[maybe_unused]] typename if_<true, H, H>::type t77;
	[[maybe_unused]] typename if_<true, I, H>::type t78;
	[[maybe_unused]] typename if_<true, J, H>::type t79;
	[[maybe_unused]] typename if_<true, A, I>::type t80;
	[[maybe_unused]] typename if_<true, B, I>::type t81;
	[[maybe_unused]] typename if_<true, C, I>::type t82;
	[[maybe_unused]] typename if_<true, D, I>::type t83;
	[[maybe_unused]] typename if_<true, E, I>::type t84;
	[[maybe_unused]] typename if_<true, F, I>::type t85;
	[[maybe_unused]] typename if_<true, G, I>::type t86;
	[[maybe_unused]] typename if_<true, H, I>::type t87;
	[[maybe_unused]] typename if_<true, I, I>::type t88;
	[[maybe_unused]] typename if_<true, J, I>::type t89;
	[[maybe_unused]] typename if_<true, A, J>::type t90;
	[[maybe_unused]] typename if_<true, B, J>::type t91;
	[[maybe_unused]] typename if_<true, C, J>::type t92;
	[[maybe_unused]] typename if_<true, D, J>::type t93;
	[[maybe_unused]] typename if_<true, E, J>::type t94;
	[[maybe_unused]] typename if_<true, F, J>::type t95;
	[[maybe_unused]] typename if_<true, G, J>::type t96;
	[[maybe_unused]] typename if_<true, H, J>::type t97;
	[[maybe_unused]] typename if_<true, I, J>::type t98;
	[[maybe_unused]] typename if_<true, J, J>::type t99;

	[[maybe_unused]] typename if_<false, A, A>::type f0;
	[[maybe_unused]] typename if_<false, B, A>::type f1;
	[[maybe_unused]] typename if_<false, C, A>::type f2;
	[[maybe_unused]] typename if_<false, D, A>::type f3;
	[[maybe_unused]] typename if_<false, E, A>::type f4;
	[[maybe_unused]] typename if_<false, F, A>::type f5;
	[[maybe_unused]] typename if_<false, G, A>::type f6;
	[[maybe_unused]] typename if_<false, H, A>::type f7;
	[[maybe_unused]] typename if_<false, I, A>::type f8;
	[[maybe_unused]] typename if_<false, J, A>::type f9;
	[[maybe_unused]] typename if_<false, A, B>::type f10;
	[[maybe_unused]] typename if_<false, B, B>::type f11;
	[[maybe_unused]] typename if_<false, C, B>::type f12;
	[[maybe_unused]] typename if_<false, D, B>::type f13;
	[[maybe_unused]] typename if_<false, E, B>::type f14;
	[[maybe_unused]] typename if_<false, F, B>::type f15;
	[[maybe_unused]] typename if_<false, G, B>::type f16;
	[[maybe_unused]] typename if_<false, H, B>::type f17;
	[[maybe_unused]] typename if_<false, I, B>::type f18;
	[[maybe_unused]] typename if_<false, J, B>::type f19;
	[[maybe_unused]] typename if_<false, A, C>::type f20;
	[[maybe_unused]] typename if_<false, B, C>::type f21;
	[[maybe_unused]] typename if_<false, C, C>::type f22;
	[[maybe_unused]] typename if_<false, D, C>::type f23;
	[[maybe_unused]] typename if_<false, E, C>::type f24;
	[[maybe_unused]] typename if_<false, F, C>::type f25;
	[[maybe_unused]] typename if_<false, G, C>::type f26;
	[[maybe_unused]] typename if_<false, H, C>::type f27;
	[[maybe_unused]] typename if_<false, I, C>::type f28;
	[[maybe_unused]] typename if_<false, J, C>::type f29;
	[[maybe_unused]] typename if_<false, A, D>::type f30;
	[[maybe_unused]] typename if_<false, B, D>::type f31;
	[[maybe_unused]] typename if_<false, C, D>::type f32;
	[[maybe_unused]] typename if_<false, D, D>::type f33;
	[[maybe_unused]] typename if_<false, E, D>::type f34;
	[[maybe_unused]] typename if_<false, F, D>::type f35;
	[[maybe_unused]] typename if_<false, G, D>::type f36;
	[[maybe_unused]] typename if_<false, H, D>::type f37;
	[[maybe_unused]] typename if_<false, I, D>::type f38;
	[[maybe_unused]] typename if_<false, J, D>::type f39;
	[[maybe_unused]] typename if_<false, A, E>::type f40;
	[[maybe_unused]] typename if_<false, B, E>::type f41;
	[[maybe_unused]] typename if_<false, C, E>::type f42;
	[[maybe_unused]] typename if_<false, D, E>::type f43;
	[[maybe_unused]] typename if_<false, E, E>::type f44;
	[[maybe_unused]] typename if_<false, F, E>::type f45;
	[[maybe_unused]] typename if_<false, G, E>::type f46;
	[[maybe_unused]] typename if_<false, H, E>::type f47;
	[[maybe_unused]] typename if_<false, I, E>::type f48;
	[[maybe_unused]] typename if_<false, J, E>::type f49;
	[[maybe_unused]] typename if_<false, A, F>::type f50;
	[[maybe_unused]] typename if_<false, B, F>::type f51;
	[[maybe_unused]] typename if_<false, C, F>::type f52;
	[[maybe_unused]] typename if_<false, D, F>::type f53;
	[[maybe_unused]] typename if_<false, E, F>::type f54;
	[[maybe_unused]] typename if_<false, F, F>::type f55;
	[[maybe_unused]] typename if_<false, G, F>::type f56;
	[[maybe_unused]] typename if_<false, H, F>::type f57;
	[[maybe_unused]] typename if_<false, I, F>::type f58;
	[[maybe_unused]] typename if_<false, J, F>::type f59;
	[[maybe_unused]] typename if_<false, A, G>::type f60;
	[[maybe_unused]] typename if_<false, B, G>::type f61;
	[[maybe_unused]] typename if_<false, C, G>::type f62;
	[[maybe_unused]] typename if_<false, D, G>::type f63;
	[[maybe_unused]] typename if_<false, E, G>::type f64;
	[[maybe_unused]] typename if_<false, F, G>::type f65;
	[[maybe_unused]] typename if_<false, G, G>::type f66;
	[[maybe_unused]] typename if_<false, H, G>::type f67;
	[[maybe_unused]] typename if_<false, I, G>::type f68;
	[[maybe_unused]] typename if_<false, J, G>::type f69;
	[[maybe_unused]] typename if_<false, A, H>::type f70;
	[[maybe_unused]] typename if_<false, B, H>::type f71;
	[[maybe_unused]] typename if_<false, C, H>::type f72;
	[[maybe_unused]] typename if_<false, D, H>::type f73;
	[[maybe_unused]] typename if_<false, E, H>::type f74;
	[[maybe_unused]] typename if_<false, F, H>::type f75;
	[[maybe_unused]] typename if_<false, G, H>::type f76;
	[[maybe_unused]] typename if_<false, H, H>::type f77;
	[[maybe_unused]] typename if_<false, I, H>::type f78;
	[[maybe_unused]] typename if_<false, J, H>::type f79;
	[[maybe_unused]] typename if_<false, A, I>::type f80;
	[[maybe_unused]] typename if_<false, B, I>::type f81;
	[[maybe_unused]] typename if_<false, C, I>::type f82;
	[[maybe_unused]] typename if_<false, D, I>::type f83;
	[[maybe_unused]] typename if_<false, E, I>::type f84;
	[[maybe_unused]] typename if_<false, F, I>::type f85;
	[[maybe_unused]] typename if_<false, G, I>::type f86;
	[[maybe_unused]] typename if_<false, H, I>::type f87;
	[[maybe_unused]] typename if_<false, I, I>::type f88;
	[[maybe_unused]] typename if_<false, J, I>::type f89;
	[[maybe_unused]] typename if_<false, A, J>::type f90;
	[[maybe_unused]] typename if_<false, B, J>::type f91;
	[[maybe_unused]] typename if_<false, C, J>::type f92;
	[[maybe_unused]] typename if_<false, D, J>::type f93;
	[[maybe_unused]] typename if_<false, E, J>::type f94;
	[[maybe_unused]] typename if_<false, F, J>::type f95;
	[[maybe_unused]] typename if_<false, G, J>::type f96;
	[[maybe_unused]] typename if_<false, H, J>::type f97;
	[[maybe_unused]] typename if_<false, I, J>::type f98;
	[[maybe_unused]] typename if_<false, J, J>::type f99;
	return 0;
}
