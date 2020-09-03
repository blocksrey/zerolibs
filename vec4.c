#include "vec4.h"
#include "maths.h"

vec4 vec4new(float x, float y, float z, float w) {
	vec4 newvec4;

	newvec4.x = x;
	newvec4.y = y;
	newvec4.z = z;
	newvec4.w = w;

	return newvec4;
}

//vec4vec4
vec4 vec4vec4add(vec4 a, vec4 b) {
	return vec4new(
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		a.w + b.w
	);
}

vec4 vec4vec4sub(vec4 a, vec4 b) {
	return vec4new(
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w
	);
}

vec4 vec4vec4mul(vec4 a, vec4 b) {
	return vec4new(
		a.x*b.x,
		a.y*b.y,
		a.z*b.z,
		a.w*b.w
	);
}

vec4 vec4vec4div(vec4 a, vec4 b) {
	return vec4new(
		a.x/b.x,
		a.y/b.y,
		a.z/b.z,
		a.w/b.w
	);
}

//vec4num
vec4 vec4numadd(vec4 a, float b) {
	return vec4new(
		a.x + b,
		a.y + b,
		a.z + b,
		a.w + b
	);
}

vec4 vec4numsub(vec4 a, float b) {
	return vec4new(
		a.x - b,
		a.y - b,
		a.z - b,
		a.w - b
	);
}

vec4 vec4nummul(vec4 a, float b) {
	return vec4new(
		a.x*b,
		a.y*b,
		a.z*b,
		a.w*b
	);
}

vec4 vec4numdiv(vec4 a, float b) {
	return vec4new(
		a.x/b,
		a.y/b,
		a.z/b,
		a.w/b
	);
}

float vec4len(vec4 v) {
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

float vec4dot(vec4 a, vec4 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

vec4 vec4unit(vec4 v) {
	float len = vec4len(v);
	if (len > 0) return vec4new(v.x/len, v.y/len, v.z/len, v.w/len);
	else return vec4new(0, 0, 0, 0);
}