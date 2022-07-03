#ifndef RND_H
#define RND_H

#include "maths.h"
#include "trig.h"
#include "v2f.h"
#include "v3f.h"
#include "v4f.h"

static u64 s1, s2, s3, b;

f32 RND() {
	/* Generates numbers between 0 and 1. */
	b  = (((s1 << 13) ^ s1) >> 19);
	s1 = (((s1 & 4294967294) << 12) ^ b);
	b  = (((s2 <<  2) ^ s2) >> 25);
	s2 = (((s2 & 4294967288) <<  4) ^ b);
	b  = (((s3 <<  3) ^ s3) >> 11);
	s3 = (((s3 & 4294967280) << 17) ^ b);
	return (f32)((s1 ^ s2 ^ s3) * 2.3283064365e-10);
}

#define uniform() RND()
#define uniform2() v2fnew(RND(), RND())
#define uniform3() v3fnew(RND(), RND(), RND())
#define uniform4() v4fnew(RND(), RND(), RND(), RND())

v2f gaussian2() {
	f32 m = SQRT(-2*LOG(1 - RND()));
	f32 a = TAU*RND();
	return v2fnew(
		m*COSP(a),
		m*SINP(a)
	);
}

v4f gaussian4() {
	f32 m0 = SQRT(2*LOG(1 - RND()));
	f32 m1 = SQRT(2*LOG(1 - RND()));
	f32 a0 = TAU*RND();
	f32 a1 = TAU*RND();
	return v4fnew(
		m0*COSP(a0),
		m0*SINP(a0),
		m1*COSP(a1),
		m1*SINP(a1)
	);
}

#define RNDunit() RND() < 0.5f ? -1 : 1

v2f RNDunit2() {
	f32 a = TAU*RND();
	return v2fnew(
		COSP(a),
		SINP(a)
	);
}

v3f RNDunit3() {
	f32 x = 2*RND() - 1;
	f32 i = SQRT(1 - x*x);
	f32 a = TAU*RND();
	return v3fnew(
		x,
		i*COSP(a),
		i*SINP(a)
	);
}

v4f RNDunit4() {
	f32 l0 = LOG(1 - RND());
	f32 l1 = LOG(1 - RND());
	f32 m0 = SQRT(l0/(l0 + l1));
	f32 m1 = SQRT(l1/(l0 + l1));
	f32 a0 = TAU*RND();
	f32 a1 = TAU*RND();
	return v4fnew(
		m0*COSP(a0),
		m0*SINP(a0),
		m1*COSP(a1),
		m1*SINP(a1)
	);
}

#define triangular() (RND() + RND() - 1)
#define triangular2() v2fnew(RND() + RND() - 1, RND() + RND() - 1)
#define triangular3() v3fnew(RND() + RND() - 1, RND() + RND() - 1, RND() + RND() - 1)
#define triangular4() v4fnew(RND() + RND() - 1, RND() + RND() - 1, RND() + RND() - 1, RND() + RND() - 1)

#define triangular4x2() v4fnew(2*(RND() + RND() - 1), 2*(RND() + RND() - 1), 2*(RND() + RND() - 1), 2*(RND() + RND() - 1))

#endif
