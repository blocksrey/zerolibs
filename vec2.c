#include "vec2.h"

vec2 vec2new(float x, float y) {
	vec2 newvec2;

	newvec2.x = x;
	newvec2.y = y;

	return newvec2;
}

//vec2vec2
vec2 vec2vec2add(vec2 a, vec2 b) {
	return vec2new(
		a.x + b.x,
		a.y + b.y
	);
}

vec2 vec2vec2sub(vec2 a, vec2 b) {
	return vec2new(
		a.x - b.x,
		a.y - b.y
	);
}

//vec2num
vec2 vec2numadd(vec2 a, float b) {
	return vec2new(
		a.x + b,
		a.y + b
	);
}

vec2 vec2numsub(vec2 a, float b) {
	return vec2new(
		a.x - b,
		a.y - b
	);
}

vec2 vec2nummul(vec2 a, float b) {
	return vec2new(
		a.x*b,
		a.y*b
	);
}

vec2 vec2numdiv(vec2 a, float b) {
	return vec2new(
		a.x/b,
		a.y/b
	);
}