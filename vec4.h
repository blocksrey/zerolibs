#ifndef VEC4_H
#define VEC4_H

typedef struct {
	float x;
	float y;
	float z;
	float w;
} vec4;

vec4 vec4new(float x, float y, float z, float w);

//vec4vec4
vec4 vec4vec4add(vec4 a, vec4 b);
vec4 vec4vec4sub(vec4 a, vec4 b);
vec4 vec4vec4mul(vec4 a, vec4 b);
vec4 vec4vec4div(vec4 a, vec4 b);

//vec4num
vec4 vec4numadd(vec4 a, float b);
vec4 vec4numsub(vec4 a, float b);
vec4 vec4nummul(vec4 a, float b);
vec4 vec4numdiv(vec4 a, float b);

float vec4len(vec4 v);

float vec4dot(vec4 a, vec4 b);

vec4 vec4unit(vec4 v);

#endif