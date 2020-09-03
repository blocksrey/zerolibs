#ifndef VEC2_H
#define VEC2_H

typedef struct {
	float x;
	float y;
} vec2;

vec2 vec2new(float x, float y);

//vec2vec2
vec2 vec2vec2add(vec2 a, vec2 b);
vec2 vec2vec2sub(vec2 a, vec2 b);

//vec2num
vec2 vec2numadd(vec2 a, float b);
vec2 vec2numsub(vec2 a, float b);
vec2 vec2nummul(vec2 a, float b);
vec2 vec2numdiv(vec2 a, float b);

#endif