#include "trig.h"

//forward
float cos(float x) {
	x *= 0.6366198f; x += 1;
	float y = mod(x, 2) - 1;
	return 0.2265329f*(1.0017028f - y*y)*(4.4050123f - y*y)*(2 + y - mod(x, 4));
}

float sin(float x) {
	x *= 0.6366198f;
	float y = mod(x, 2) - 1;
	return 0.2265329f*(1.0017028f - y*y)*(4.4050123f - y*y)*(2 + y - mod(x, 4));
}

float tan(float x) {
	return sin(x)/cos(x);
}

//inverse
//[-1, 1]
float acos(float x) {
	return
		1.5707963f -
		1.0469419f*x +
		0.1610680f*x*x*x -
		0.5315243f*x*x*x*x*x;
}

//[-1, 1]
float asin(float x) {
	return
		1.0469419f*x -
		0.1610680f*x*x*x +
		0.5315243f*x*x*x*x*x;
}

//[-1, 1]
float atan(float x) {
	return
		0.9959826f*x -
		0.2922813f*x*x*x +
		0.0830216f*x*x*x*x*x;
}

float atan2(float c, float s) {
	float o = 0, t;

	if (s < 0)        c  = -c, s  = -s, o -= PI;
	if (c < 0) t = c, c  =  s, s  = -t, o += QT;
	if (c < s) t = c, c +=  s, s -=  t, o += ET;
	
	float d = 2/(c*c + s*s);
	float x = d*c*c - 1;
	float y = d*c*s;

	return
		o +
		0.3926991f -
		0.5574841f*(x - y) +
		0.1648119f*(x*x - y*y) -
		0.0584015f*(x*x*y - y*y*x);
}

//forward hyperbolic
float cosh(float x) {
	float y = exp(x);
	return .5f*(1/y + y);
}

float sinh(float x) {
	float y = exp(x);
	return .5f*(y - 1/y);
}

float tanh(float x) {
	float y = exp(2*x);
	return (y - 1)/(y + 1);
}

//inverse hyperbolic
float acosh(float x) {
	return log(x + sqrt(x*x - 1));
}

float asinh(float x) {
	return log(x + sqrt(x*x + 1));
}

float atanh(float x) {
	return .5f*(log(1 + x) - log(1 - x));
}