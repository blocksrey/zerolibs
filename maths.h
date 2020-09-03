#ifndef MATHS_H
#define MATHS_H

#define ET  0.7853982f
#define QT  1.5707963f
#define PI  3.1415927f
#define TAU 6.2831853f
#define E   2.7182818f
#define RT  1.4142136f
#define PHI 1.6180340f

#define sqrt sqrtsqrt
#define pow powpow
#define exp expexp
#define log loglog
#define log2 log2log2
#define floor floorfloor
#define ceil ceilceil

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(x) (x < 0 ? x : -x)

float invsqrt(float x);
float sqrt(float x);
float mod(float x, float y);
float pow(float x, float y);
float fact(float x);
float stir(float x);
float exp(float x);
float log(float x);
float log2(float x);
float fib(float x, float y);
float bin(float x, float y);
int floor(float x);
int ceil(float x);

#endif