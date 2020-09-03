#ifndef QUAT_H
#define QUAT_H

#include "maths.h"
#include "trig.h"
#include "mat3.h"
#include "rand.h"

typedef struct {
	float x;
	float y;
	float z;
	float w;
} quat;

quat quatnew(float w, float x, float y, float z);

quat quatinv(quat q);

quat slerp(quat a, quat b, float t);

quat quateulerx(float a);
quat quateulerx(float a);
quat quateulerx(float a);

quat quatmat3(mat3 m);

quat quatlook(vec3 a, vec3 b);

quat quataxisangle(vec3 v);

quat quatquatmul(quat a, quat b);

quat quatquatpow(quat q, float n);

#endif