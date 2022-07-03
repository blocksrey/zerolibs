#ifndef TRIG_H
#define TRIG_H

#include "maths.h"

#define TAN(x) (SIN(x)/COS(x))
#define SINP(t) COSP(t - QT)
#define SIN(t) COS(t - QT)

static f32 COSP(f32 t) {
	t *= IP;
	i32 i = RNDP(t);
	f32 f = t - (f32)i;
	return (1 + i%2*~1)*(1 + (3.6527833f*f*f - 4.9070450f)*f*f);
}

static f32 ATAN2(f32 c, f32 s) {
	f32 o = 0;

	if (s < 0) {
		c = -c;
		s = -s;
		o -= PI;
	}

	if (c < 0) {
		f32 t = c;
		c = s;
		s = -t;
		o += QT;
	}

	if (c < s) {
		f32 t = c;
		c += s;
		s -= t;
		o += ET;
	}

	f32 d = 2/(c*c + s*s);
	f32 x = d*c*c - 1;
	f32 y = d*c*s;

	return
		o +
		0.3926991f -
		0.5574841f*(x - y) +
		0.1648119f*(x*x - y*y) -
		0.0584015f*(x*x*y - y*y*x);
}

//inverse
//[-1, 1]
static f32 ACOS(f32 x) {
	return
		1.5707963f -
		1.0469419f*x +
		0.1610680f*x*x*x -
		0.5315243f*x*x*x*x*x;
}

//[-1, 1]
static f32 ASIN(f32 x) {
	return
		1.0469419f*x -
		0.1610680f*x*x*x +
		0.5315243f*x*x*x*x*x;
}

//[-1, 1]
static f32 ATAN(f32 x) {
	return
		0.9959826f*x -
		0.2922813f*x*x*x +
		0.0830216f*x*x*x*x*x;
}

//forward hyperbolic
static f32 COSH(f32 x) {
	f32 y = EXP(x);
	return 0.5f*(1/y + y);
}

static f32 SINH(f32 x) {
	f32 y = EXP(x);
	return 0.5f*(y - 1/y);
}

static f32 TANH(f32 x) {
	f32 y = EXP(2*x);
	return (y - 1)/(y + 1);
}

//inverse hyperbolic
static f32 ACOSH(f32 x) {
	return LOG(x + SQRT(x*x - 1));
}

static f32 ASINH(f32 x) {
	return LOG(x + SQRT(x*x + 1));
}

static f32 ATAHN(f32 x) {
	return 0.5f*(LOG(1 + x) - LOG(1 - x));
}

#endif
