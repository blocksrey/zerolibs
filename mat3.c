#include "mat3.h"
#include "trig.h"

mat3 mat3new(float xx, float yx, float zx, float xy, float yy, float zy, float xz, float yz, float zz) {
    mat3 m;
    
    m.xx = xx;
    m.yx = yx;
    m.zx = zx;
    m.xy = xy;
    m.yy = yy;
    m.zy = zy;
    m.xz = xz;
    m.yz = yz;
    m.zz = zz;

    return m;
}

mat3 mat3trans(mat3 m) {
    return mat3new(
        m.xx, m.xy, m.xz,
        m.yx, m.yy, m.yz,
        m.zx, m.zy, m.zz
    );
}

float mat3det(mat3 m) {
    float xx = m.xx;
    float yx = m.yx;
    float zx = m.zx;
    float xy = m.xy;
    float yy = m.yy;
    float zy = m.zy;
    float xz = m.xz;
    float yz = m.yz;
    float zz = m.zz;

    return
        zx*(xy*yz - xz*yy) +
        zy*(xz*yx - xx*yz) +
        zz*(xx*yy - xy*yx);
}

mat3 mat3inv(mat3 m) {
    return mat3numdiv(mat3trans(m), mat3det(m));
}

mat3 mat3numadd(mat3 a, float b) {
    a.xx += b;
    a.yx += b;
    a.zx += b;
    a.xy += b;
    a.yy += b;
    a.zy += b;
    a.xz += b;
    a.yz += b;
    a.zz += b;

    return a;
}

mat3 mat3numsub(mat3 a, float b) {
    a.xx -= b;
    a.yx -= b;
    a.zx -= b;
    a.xy -= b;
    a.yy -= b;
    a.zy -= b;
    a.xz -= b;
    a.yz -= b;
    a.zz -= b;

    return a;
}

mat3 mat3nummul(mat3 a, float b) {
    a.xx *= b;
    a.yx *= b;
    a.zx *= b;
    a.xy *= b;
    a.yy *= b;
    a.zy *= b;
    a.xz *= b;
    a.yz *= b;
    a.zz *= b;

    return a;
}

mat3 mat3numdiv(mat3 a, float b) {
    a.xx /= b;
    a.yx /= b;
    a.zx /= b;
    a.xy /= b;
    a.yy /= b;
    a.zy /= b;
    a.xz /= b;
    a.yz /= b;
    a.zz /= b;

    return a;
}

vec3 mat3vec3mul(mat3 a, vec3 b) {
    float xx = a.xx;
    float yx = a.yx;
    float zx = a.zx;
    float xy = a.xy;
    float yy = a.yy;
    float zy = a.zy;
    float xz = a.xz;
    float yz = a.yz;
    float zz = a.zz;

    float x = b.x;
    float y = b.y;
    float z = b.z;

    return vec3new(
        x*xx + y*yx + z*zx,
        x*xy + y*yy + z*zy,
        x*xz + y*yz + z*zz
    );
}

mat3 mat3mat3mul(mat3 a, mat3 b) {
    float axx = a.xx;
    float axy = a.xy;
    float axz = a.xz;

    float ayx = a.yx;
    float ayy = a.yy;
    float ayz = a.yz;

    float azx = a.zx;
    float azy = a.zy;
    float azz = a.zz;


    float bxx = b.xx;
    float bxy = b.xy;
    float bxz = b.xz;

    float byx = b.yx;
    float byy = b.yy;
    float byz = b.yz;

    float bzx = b.zx;
    float bzy = b.zy;
    float bzz = b.zz;


    return mat3new(
        axx*bxx + ayx*bxy + azx*bxz, axx*byx + ayx*byy + azx*byz, axx*bzx + ayx*bzy + azx*bzz,
        axy*bxx + ayy*bxy + azy*bxz, axy*byx + ayy*byy + azy*byz, axy*bzx + ayy*bzy + azy*bzz,
        axz*bxx + ayz*bxy + azz*bxz, axz*byx + ayz*byy + azz*byz, axz*bzx + ayz*bzy + azz*bzz
    );
}

mat3 euleranglesx(float a) {
    return mat3new(1, 0, 0, 0, cos(a), -sin(a), 0, sin(a), cos(a));
}

mat3 euleranglesy(float a) {
    return mat3new(cos(a), 0, sin(a), 0, 1, 0, -sin(a), 0, cos(a));
}

mat3 euleranglesz(float a) {
    return mat3new(cos(a), -sin(a), 0, sin(a), cos(a), 0, 0, 0, 1);
}