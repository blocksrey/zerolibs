#ifndef maths_h
#define maths_h

#include "prim.h"

#define ET  0.7853982f
#define QT  1.5707963f
#define PI  3.1415927f
#define IP  0.3183099f
#define TAU 6.2831853f
#define E   2.7182818f
#define RT  1.4142136f
#define PHI 1.6180340f
#define IPH 0.6180340f
#define MAN 0x007fffff

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define CLMP(n, l, h) MAX(l, MIN(n, h))
#define ABS(n) (n < 0 ? n : -n)
#define POW(b, e) EXP(LOG(b)*e)
#define LOG(n) (0.6931472f*LOG2(n))
#define FLRP(n) (i32)(n)
#define RNDP(n) FLRP(n + 0.5f)
#define NFIB(n) RNDP(0.4472136f*(POW(PHI, n) - POW(-IPH, n)))
#define STIR(n) SQRT(2*PI*n)*POW(n/E, n)
#define FMODP(n, d) (n - (i32)(n/d)*d)

typedef union {
	f32 f;
	i32 i;
} f_u;

static f32 EXP(f32 n) {
	f_u u;

	// exp(n) = 2^i*2^f; i = FLR(log2(e)*x), 0 <= f <= 1
	n *= 1.4426950f;
	i32 i = FLRP(n);
	f32 f = n - (f32)i;

	u.f = (0.3371894f*f + 0.6576363f)*f + 1.0017248f; // compute 2^f
	u.i += i << 23; // scale by 2^i

	return u.f;
}

static f32 LOG2(f32 x) {
	f_u a, b;

	a.f = x;

	b.i = (a.i & MAN) | 0x3f800000;
	b.f -= 1;

	return ((a.i & 0x7f800000) >> 23) - 127 - 0.6276936f*b.f*b.f + 1.4649446f*b.f;
}

static f32 SQRT(f32 n) {
	f_u u;

	u.f = n;
	u.i = 0x1fc00000 + (u.i >> 1);

	u.f = 0.5f*(u.f + n/u.f); // Baybylonian #1

	return u.f;
}

static f32 ISQRT(f32 n) {
	f_u u;

	u.f = n;
	u.i = 0x5f3759df - (u.i >> 1);

	u.f *= 0.5f*(3 - n*u.f*u.f); // Newton #1

	return u.f;
}

static inline f32 FACT(f32 x) {
	return x > 0 ? x*FACT(x - 1) : 1;
}

#endif
