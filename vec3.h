#ifndef VEC3_H
#define VEC3_H

typedef struct {
	float x;
	float y;
	float z;
} vec3;

vec3 vec3new(float x, float y, float z);

//vec3vec3
vec3 vec3vec3add(vec3 a, vec3 b);
vec3 vec3vec3sub(vec3 a, vec3 b);
vec3 vec3vec3mul(vec3 a, vec3 b);
vec3 vec3vec3div(vec3 a, vec3 b);

//vec3num
vec3 vec3numadd(vec3 a, float b);
vec3 vec3numsub(vec3 a, float b);
vec3 vec3nummul(vec3 a, float b);
vec3 vec3numdiv(vec3 a, float b);

float vec3len(vec3 v);

float vec3dot(vec3 a, vec3 b);

vec3 vec3unit(vec3 v);

float vec3dotself(vec3 v);

float vec3dist(vec3 a, vec3 b);

vec3 vec3tween(vec3 a, vec3 b, float p);

vec3 vec3reflect(vec3 v, vec3 n);

#endif