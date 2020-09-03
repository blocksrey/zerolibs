#include "rand.h"

unsigned long s1, s2, s3, b;

float rand() {
	/* Generates numbers between 0 and 1. */
	b  = (((s1 << 13) ^ s1) >> 19);
	s1 = (((s1 & 4294967294) << 12) ^ b);
	b  = (((s2 <<  2) ^ s2) >> 25);
	s2 = (((s2 & 4294967288) <<  4) ^ b);
	b  = (((s3 <<  3) ^ s3) >> 11);
	s3 = (((s3 & 4294967280) << 17) ^ b);
	return (float)((s1 ^ s2 ^ s3) * 2.3283064365e-10);
}

float uniform() {
	return rand();
}

vec2 uniform2() {
	return vec2new(
		rand(),
		rand()
	);
}

vec3 uniform3() {
	return vec3new(
		rand(),
		rand(),
		rand()
	);
}

vec4 uniform4() {
	return vec4new(
		rand(),
		rand(),
		rand(),
		rand()
	);
}

vec2 gaussian2() {
	float m = sqrt(-2.0f*log(1 - rand()));
	float a = TAU*rand();
	return vec2new(
		m*cos(a),
		m*sin(a)
	);
}

vec4 gaussian4() {
	float m0 = sqrt(2.0f*log(1 - rand()));
	float m1 = sqrt(2.0f*log(1 - rand()));
	float a0 = TAU*rand();
	float a1 = TAU*rand();
	return vec4new(
		m0*cos(a0),
		m0*sin(a0),
		m1*cos(a1),
		m1*sin(a1)
	);
}

float randunit() {
	return rand() < 0.5f ? -1 : 1;
}

vec2 randunit2() {
	float a = TAU*rand();
	return vec2new(
		cos(a),
		sin(a)
	);
}

vec3 randunit3() {
	float x = 2.0f*rand() - 1;
	float i = sqrt(1 - x*x);
	float a = TAU*rand();
	return vec3new(
		x,
		i*cos(a),
		i*sin(a)
	);
}

vec4 randunit4() {
	float l0 = log(1 - rand());
	float l1 = log(1 - rand());
	float m0 = sqrt(l0/(l0 + l1));
	float m1 = sqrt(l1/(l0 + l1));
	float a0 = TAU*rand();
	float a1 = TAU*rand();
	return vec4new(
		m0*cos(a0),
		m0*sin(a0),
		m1*cos(a1),
		m1*sin(a1)
	);
}

float triangular() {
	return rand() + rand() - 1;
}

vec2 triangular2() {
	return vec2new(
		rand() + rand() - 1,
		rand() + rand() - 1
	);
}

vec3 triangular3() {
	return vec3new(
		rand() + rand() - 1,
		rand() + rand() - 1,
		rand() + rand() - 1
	);
}

vec4 triangular4() {
	return vec4new(
		rand() + rand() - 1,
		rand() + rand() - 1,
		rand() + rand() - 1,
		rand() + rand() - 1
	);
}

vec4 triangular4x2() {
	return vec4new(
		2.0f*(rand() + rand() - 1),
		2.0f*(rand() + rand() - 1),
		2.0f*(rand() + rand() - 1),
		2.0f*(rand() + rand() - 1)
	);
}