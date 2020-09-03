#include "vec3.h"

typedef struct {
    float xx;
    float yx;
    float zx;

    float xy;
    float yy;
    float zy;

    float xz;
    float yz;
    float zz;
} mat3;

//mat3 new
mat3 mat3new(float xx, float yx, float zx, float xy, float yy, float zy, float xz, float yz, float zz);

//mat3 stuff
mat3 mat3trans(mat3 m);
mat3 mat3inv(mat3 m);

//mat3 mat3
mat3 mat3mat3mul(mat3 a, mat3 b);

//mat3 eulerangles
mat3 euleranglesx(float a);
mat3 euleranglesy(float a);
mat3 euleranglesz(float a);

//mat3 num
mat3 mat3numadd(mat3 a, float b);
mat3 mat3numsub(mat3 a, float b);
mat3 mat3nummul(mat3 a, float b);
mat3 mat3numdiv(mat3 a, float b);

//float determinant
float mat3det(mat3 m);

//mat3 vec3
vec3 mat3vec3mul(mat3 a, vec3 b);