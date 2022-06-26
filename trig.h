#ifndef TRIG_H
#define TRIG_H

#include "maths.h"

/*
f32 cos(f32 x) {
	x *= 0.6366198; x += 1;
	f32 y = mod(x, 2) - 1;
	return 0.2265329*(1.0017028f - y*y)*(4.4050123f - y*y)*(2 + y - mod(x, 4));
}

f32 sin(f32 x) {
	x *= 0.6366198;
	f32 y = mod(x, 2) - 1;
	return 0.2265329*(1.0017028f - y*y)*(4.4050123f - y*y)*(2 + y - mod(x, 4));
}
*/

#define TAN(x) (SIN(x)/COS(x))

//inverse
//[-1, 1]
f32 ACOS(f32 x) {
	return
		1.5707963 -
		1.0469419*x +
		0.1610680*x*x*x -
		0.5315243*x*x*x*x*x;
}

//[-1, 1]
f32 ASIN(f32 x) {
	return
		1.0469419*x -
		0.1610680*x*x*x +
		0.5315243*x*x*x*x*x;
}

//[-1, 1]
f32 ATAN(f32 x) {
	return
		0.9959826*x -
		0.2922813*x*x*x +
		0.0830216*x*x*x*x*x;
}

//forward hyperbolic
f32 COSH(f32 x) {
	f32 y = EXP(x);
	return 0.5*(1/y + y);
}

f32 SINH(f32 x) {
	f32 y = EXP(x);
	return 0.5*(y - 1/y);
}

f32 TANH(f32 x) {
	f32 y = EXP(2*x);
	return (y - 1)/(y + 1);
}

//inverse hyperbolic
f32 ACOSH(f32 x) {
	return LOG(x + SQRT(x*x - 1));
}

f32 ASINH(f32 x) {
	return LOG(x + SQRT(x*x + 1));
}

f32 ATAHN(f32 x) {
	return 0.5*(LOG(1 + x) - LOG(1 - x));
}

#endif