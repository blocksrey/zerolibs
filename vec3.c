#include "vec3.h"
#include "maths.h"

vec3 vec3new(float x, float y, float z) {
	vec3 newvec3;

	newvec3.x = x;
	newvec3.y = y;
	newvec3.z = z;

	return newvec3;
}

//vec3vec3
vec3 vec3vec3add(vec3 a, vec3 b) {
	return vec3new(
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	);
}

vec3 vec3vec3sub(vec3 a, vec3 b) {
	return vec3new(
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	);
}

vec3 vec3vec3mul(vec3 a, vec3 b) {
	return vec3new(
		a.x*b.x,
		a.y*b.y,
		a.z*b.z
	);
}

vec3 vec3vec3div(vec3 a, vec3 b) {
	return vec3new(
		a.x/b.x,
		a.y/b.y,
		a.z/b.z
	);
}

//vec3num
vec3 vec3numadd(vec3 a, float b) {
	return vec3new(
		a.x + b,
		a.y + b,
		a.z + b
	);
}

vec3 vec3numsub(vec3 a, float b) {
	return vec3new(
		a.x - b,
		a.y - b,
		a.z - b
	);
}

vec3 vec3nummul(vec3 a, float b) {
	return vec3new(
		a.x*b,
		a.y*b,
		a.z*b
	);
}

vec3 vec3numdiv(vec3 a, float b) {
	return vec3new(
		a.x/b,
		a.y/b,
		a.z/b
	);
}

float vec3len(vec3 v) {
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

float vec3dot(vec3 a, vec3 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec3 vec3unit(vec3 v) {
	float len = vec3len(v);
	if (len > 0) return vec3new(v.x/len, v.y/len, v.z/len);
	else return vec3new(0, 0, 0);
}

float vec3dotself(vec3 v) {
	return v.x*v.x + v.y*v.y + v.z*v.z;
}

float vec3dist(vec3 a, vec3 b) {
	return sqrt(vec3dotself(vec3vec3sub(b, a)));
}

vec3 vec3tween(vec3 a, vec3 b, float p) {
	float o = 1 - p;
	
	return vec3new(
		o*a.x + p*b.x,
		o*a.y + p*b.y,
		o*a.z + p*b.z
	);
}

vec3 vec3reflect(vec3 v, vec3 n) {
	return vec3vec3sub(v, vec3nummul(n, 2*vec3dot(v, n)));
}