#ifndef RAND_H
#define RAND_H

#include "maths.h"
#include "trig.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

float rand();

float uniform();
vec2 uniform2();
vec3 uniform3();
vec4 uniform4();

vec2 gaussian2();
vec4 gaussian4();

float randunit();
vec2 randunit2();
vec3 randunit3();
vec4 randunit4();

float triangular();
vec2 triangular2();
vec3 triangular3();
vec4 triangular4();
vec4 triangular4x2();

#endif