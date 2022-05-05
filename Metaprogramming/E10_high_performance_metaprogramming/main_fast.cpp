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

template <bool condition>
struct if_ {
	template <typename THEN, typename ELSE>
	using f = THEN;
};

template <>
struct if_<false> {
	template <typename THEN, typename ELSE>
	using f = ELSE;
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
	[[maybe_unused]] typename if_<true>::template f<A, A> t0;
	[[maybe_unused]] typename if_<true>::template f<B, A> t1;
	[[maybe_unused]] typename if_<true>::template f<C, A> t2;
	[[maybe_unused]] typename if_<true>::template f<D, A> t3;
	[[maybe_unused]] typename if_<true>::template f<E, A> t4;
	[[maybe_unused]] typename if_<true>::template f<F, A> t5;
	[[maybe_unused]] typename if_<true>::template f<G, A> t6;
	[[maybe_unused]] typename if_<true>::template f<H, A> t7;
	[[maybe_unused]] typename if_<true>::template f<I, A> t8;
	[[maybe_unused]] typename if_<true>::template f<J, A> t9;
	[[maybe_unused]] typename if_<true>::template f<A, B> t10;
	[[maybe_unused]] typename if_<true>::template f<B, B> t11;
	[[maybe_unused]] typename if_<true>::template f<C, B> t12;
	[[maybe_unused]] typename if_<true>::template f<D, B> t13;
	[[maybe_unused]] typename if_<true>::template f<E, B> t14;
	[[maybe_unused]] typename if_<true>::template f<F, B> t15;
	[[maybe_unused]] typename if_<true>::template f<G, B> t16;
	[[maybe_unused]] typename if_<true>::template f<H, B> t17;
	[[maybe_unused]] typename if_<true>::template f<I, B> t18;
	[[maybe_unused]] typename if_<true>::template f<J, B> t19;
	[[maybe_unused]] typename if_<true>::template f<A, C> t20;
	[[maybe_unused]] typename if_<true>::template f<B, C> t21;
	[[maybe_unused]] typename if_<true>::template f<C, C> t22;
	[[maybe_unused]] typename if_<true>::template f<D, C> t23;
	[[maybe_unused]] typename if_<true>::template f<E, C> t24;
	[[maybe_unused]] typename if_<true>::template f<F, C> t25;
	[[maybe_unused]] typename if_<true>::template f<G, C> t26;
	[[maybe_unused]] typename if_<true>::template f<H, C> t27;
	[[maybe_unused]] typename if_<true>::template f<I, C> t28;
	[[maybe_unused]] typename if_<true>::template f<J, C> t29;
	[[maybe_unused]] typename if_<true>::template f<A, D> t30;
	[[maybe_unused]] typename if_<true>::template f<B, D> t31;
	[[maybe_unused]] typename if_<true>::template f<C, D> t32;
	[[maybe_unused]] typename if_<true>::template f<D, D> t33;
	[[maybe_unused]] typename if_<true>::template f<E, D> t34;
	[[maybe_unused]] typename if_<true>::template f<F, D> t35;
	[[maybe_unused]] typename if_<true>::template f<G, D> t36;
	[[maybe_unused]] typename if_<true>::template f<H, D> t37;
	[[maybe_unused]] typename if_<true>::template f<I, D> t38;
	[[maybe_unused]] typename if_<true>::template f<J, D> t39;
	[[maybe_unused]] typename if_<true>::template f<A, E> t40;
	[[maybe_unused]] typename if_<true>::template f<B, E> t41;
	[[maybe_unused]] typename if_<true>::template f<C, E> t42;
	[[maybe_unused]] typename if_<true>::template f<D, E> t43;
	[[maybe_unused]] typename if_<true>::template f<E, E> t44;
	[[maybe_unused]] typename if_<true>::template f<F, E> t45;
	[[maybe_unused]] typename if_<true>::template f<G, E> t46;
	[[maybe_unused]] typename if_<true>::template f<H, E> t47;
	[[maybe_unused]] typename if_<true>::template f<I, E> t48;
	[[maybe_unused]] typename if_<true>::template f<J, E> t49;
	[[maybe_unused]] typename if_<true>::template f<A, F> t50;
	[[maybe_unused]] typename if_<true>::template f<B, F> t51;
	[[maybe_unused]] typename if_<true>::template f<C, F> t52;
	[[maybe_unused]] typename if_<true>::template f<D, F> t53;
	[[maybe_unused]] typename if_<true>::template f<E, F> t54;
	[[maybe_unused]] typename if_<true>::template f<F, F> t55;
	[[maybe_unused]] typename if_<true>::template f<G, F> t56;
	[[maybe_unused]] typename if_<true>::template f<H, F> t57;
	[[maybe_unused]] typename if_<true>::template f<I, F> t58;
	[[maybe_unused]] typename if_<true>::template f<J, F> t59;
	[[maybe_unused]] typename if_<true>::template f<A, G> t60;
	[[maybe_unused]] typename if_<true>::template f<B, G> t61;
	[[maybe_unused]] typename if_<true>::template f<C, G> t62;
	[[maybe_unused]] typename if_<true>::template f<D, G> t63;
	[[maybe_unused]] typename if_<true>::template f<E, G> t64;
	[[maybe_unused]] typename if_<true>::template f<F, G> t65;
	[[maybe_unused]] typename if_<true>::template f<G, G> t66;
	[[maybe_unused]] typename if_<true>::template f<H, G> t67;
	[[maybe_unused]] typename if_<true>::template f<I, G> t68;
	[[maybe_unused]] typename if_<true>::template f<J, G> t69;
	[[maybe_unused]] typename if_<true>::template f<A, H> t70;
	[[maybe_unused]] typename if_<true>::template f<B, H> t71;
	[[maybe_unused]] typename if_<true>::template f<C, H> t72;
	[[maybe_unused]] typename if_<true>::template f<D, H> t73;
	[[maybe_unused]] typename if_<true>::template f<E, H> t74;
	[[maybe_unused]] typename if_<true>::template f<F, H> t75;
	[[maybe_unused]] typename if_<true>::template f<G, H> t76;
	[[maybe_unused]] typename if_<true>::template f<H, H> t77;
	[[maybe_unused]] typename if_<true>::template f<I, H> t78;
	[[maybe_unused]] typename if_<true>::template f<J, H> t79;
	[[maybe_unused]] typename if_<true>::template f<A, I> t80;
	[[maybe_unused]] typename if_<true>::template f<B, I> t81;
	[[maybe_unused]] typename if_<true>::template f<C, I> t82;
	[[maybe_unused]] typename if_<true>::template f<D, I> t83;
	[[maybe_unused]] typename if_<true>::template f<E, I> t84;
	[[maybe_unused]] typename if_<true>::template f<F, I> t85;
	[[maybe_unused]] typename if_<true>::template f<G, I> t86;
	[[maybe_unused]] typename if_<true>::template f<H, I> t87;
	[[maybe_unused]] typename if_<true>::template f<I, I> t88;
	[[maybe_unused]] typename if_<true>::template f<J, I> t89;
	[[maybe_unused]] typename if_<true>::template f<A, J> t90;
	[[maybe_unused]] typename if_<true>::template f<B, J> t91;
	[[maybe_unused]] typename if_<true>::template f<C, J> t92;
	[[maybe_unused]] typename if_<true>::template f<D, J> t93;
	[[maybe_unused]] typename if_<true>::template f<E, J> t94;
	[[maybe_unused]] typename if_<true>::template f<F, J> t95;
	[[maybe_unused]] typename if_<true>::template f<G, J> t96;
	[[maybe_unused]] typename if_<true>::template f<H, J> t97;
	[[maybe_unused]] typename if_<true>::template f<I, J> t98;
	[[maybe_unused]] typename if_<true>::template f<J, J> t99;

	[[maybe_unused]] typename if_<false>::template f<A, A> f0;
	[[maybe_unused]] typename if_<false>::template f<B, A> f1;
	[[maybe_unused]] typename if_<false>::template f<C, A> f2;
	[[maybe_unused]] typename if_<false>::template f<D, A> f3;
	[[maybe_unused]] typename if_<false>::template f<E, A> f4;
	[[maybe_unused]] typename if_<false>::template f<F, A> f5;
	[[maybe_unused]] typename if_<false>::template f<G, A> f6;
	[[maybe_unused]] typename if_<false>::template f<H, A> f7;
	[[maybe_unused]] typename if_<false>::template f<I, A> f8;
	[[maybe_unused]] typename if_<false>::template f<J, A> f9;
	[[maybe_unused]] typename if_<false>::template f<A, B> f10;
	[[maybe_unused]] typename if_<false>::template f<B, B> f11;
	[[maybe_unused]] typename if_<false>::template f<C, B> f12;
	[[maybe_unused]] typename if_<false>::template f<D, B> f13;
	[[maybe_unused]] typename if_<false>::template f<E, B> f14;
	[[maybe_unused]] typename if_<false>::template f<F, B> f15;
	[[maybe_unused]] typename if_<false>::template f<G, B> f16;
	[[maybe_unused]] typename if_<false>::template f<H, B> f17;
	[[maybe_unused]] typename if_<false>::template f<I, B> f18;
	[[maybe_unused]] typename if_<false>::template f<J, B> f19;
	[[maybe_unused]] typename if_<false>::template f<A, C> f20;
	[[maybe_unused]] typename if_<false>::template f<B, C> f21;
	[[maybe_unused]] typename if_<false>::template f<C, C> f22;
	[[maybe_unused]] typename if_<false>::template f<D, C> f23;
	[[maybe_unused]] typename if_<false>::template f<E, C> f24;
	[[maybe_unused]] typename if_<false>::template f<F, C> f25;
	[[maybe_unused]] typename if_<false>::template f<G, C> f26;
	[[maybe_unused]] typename if_<false>::template f<H, C> f27;
	[[maybe_unused]] typename if_<false>::template f<I, C> f28;
	[[maybe_unused]] typename if_<false>::template f<J, C> f29;
	[[maybe_unused]] typename if_<false>::template f<A, D> f30;
	[[maybe_unused]] typename if_<false>::template f<B, D> f31;
	[[maybe_unused]] typename if_<false>::template f<C, D> f32;
	[[maybe_unused]] typename if_<false>::template f<D, D> f33;
	[[maybe_unused]] typename if_<false>::template f<E, D> f34;
	[[maybe_unused]] typename if_<false>::template f<F, D> f35;
	[[maybe_unused]] typename if_<false>::template f<G, D> f36;
	[[maybe_unused]] typename if_<false>::template f<H, D> f37;
	[[maybe_unused]] typename if_<false>::template f<I, D> f38;
	[[maybe_unused]] typename if_<false>::template f<J, D> f39;
	[[maybe_unused]] typename if_<false>::template f<A, E> f40;
	[[maybe_unused]] typename if_<false>::template f<B, E> f41;
	[[maybe_unused]] typename if_<false>::template f<C, E> f42;
	[[maybe_unused]] typename if_<false>::template f<D, E> f43;
	[[maybe_unused]] typename if_<false>::template f<E, E> f44;
	[[maybe_unused]] typename if_<false>::template f<F, E> f45;
	[[maybe_unused]] typename if_<false>::template f<G, E> f46;
	[[maybe_unused]] typename if_<false>::template f<H, E> f47;
	[[maybe_unused]] typename if_<false>::template f<I, E> f48;
	[[maybe_unused]] typename if_<false>::template f<J, E> f49;
	[[maybe_unused]] typename if_<false>::template f<A, F> f50;
	[[maybe_unused]] typename if_<false>::template f<B, F> f51;
	[[maybe_unused]] typename if_<false>::template f<C, F> f52;
	[[maybe_unused]] typename if_<false>::template f<D, F> f53;
	[[maybe_unused]] typename if_<false>::template f<E, F> f54;
	[[maybe_unused]] typename if_<false>::template f<F, F> f55;
	[[maybe_unused]] typename if_<false>::template f<G, F> f56;
	[[maybe_unused]] typename if_<false>::template f<H, F> f57;
	[[maybe_unused]] typename if_<false>::template f<I, F> f58;
	[[maybe_unused]] typename if_<false>::template f<J, F> f59;
	[[maybe_unused]] typename if_<false>::template f<A, G> f60;
	[[maybe_unused]] typename if_<false>::template f<B, G> f61;
	[[maybe_unused]] typename if_<false>::template f<C, G> f62;
	[[maybe_unused]] typename if_<false>::template f<D, G> f63;
	[[maybe_unused]] typename if_<false>::template f<E, G> f64;
	[[maybe_unused]] typename if_<false>::template f<F, G> f65;
	[[maybe_unused]] typename if_<false>::template f<G, G> f66;
	[[maybe_unused]] typename if_<false>::template f<H, G> f67;
	[[maybe_unused]] typename if_<false>::template f<I, G> f68;
	[[maybe_unused]] typename if_<false>::template f<J, G> f69;
	[[maybe_unused]] typename if_<false>::template f<A, H> f70;
	[[maybe_unused]] typename if_<false>::template f<B, H> f71;
	[[maybe_unused]] typename if_<false>::template f<C, H> f72;
	[[maybe_unused]] typename if_<false>::template f<D, H> f73;
	[[maybe_unused]] typename if_<false>::template f<E, H> f74;
	[[maybe_unused]] typename if_<false>::template f<F, H> f75;
	[[maybe_unused]] typename if_<false>::template f<G, H> f76;
	[[maybe_unused]] typename if_<false>::template f<H, H> f77;
	[[maybe_unused]] typename if_<false>::template f<I, H> f78;
	[[maybe_unused]] typename if_<false>::template f<J, H> f79;
	[[maybe_unused]] typename if_<false>::template f<A, I> f80;
	[[maybe_unused]] typename if_<false>::template f<B, I> f81;
	[[maybe_unused]] typename if_<false>::template f<C, I> f82;
	[[maybe_unused]] typename if_<false>::template f<D, I> f83;
	[[maybe_unused]] typename if_<false>::template f<E, I> f84;
	[[maybe_unused]] typename if_<false>::template f<F, I> f85;
	[[maybe_unused]] typename if_<false>::template f<G, I> f86;
	[[maybe_unused]] typename if_<false>::template f<H, I> f87;
	[[maybe_unused]] typename if_<false>::template f<I, I> f88;
	[[maybe_unused]] typename if_<false>::template f<J, I> f89;
	[[maybe_unused]] typename if_<false>::template f<A, J> f90;
	[[maybe_unused]] typename if_<false>::template f<B, J> f91;
	[[maybe_unused]] typename if_<false>::template f<C, J> f92;
	[[maybe_unused]] typename if_<false>::template f<D, J> f93;
	[[maybe_unused]] typename if_<false>::template f<E, J> f94;
	[[maybe_unused]] typename if_<false>::template f<F, J> f95;
	[[maybe_unused]] typename if_<false>::template f<G, J> f96;
	[[maybe_unused]] typename if_<false>::template f<H, J> f97;
	[[maybe_unused]] typename if_<false>::template f<I, J> f98;
	[[maybe_unused]] typename if_<false>::template f<J, J> f99;
	return 0;
}
