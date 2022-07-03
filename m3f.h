#ifndef m3fh
#define m3fh

#include "v3f.h"

typedef struct {
	f32 xx;
	f32 yx;
	f32 zx;

	f32 xy;
	f32 yy;
	f32 zy;

	f32 xz;
	f32 yz;
	f32 zz;
} m3f;

m3f m3fnew(f32 xx, f32 yx, f32 zx, f32 xy, f32 yy, f32 zy, f32 xz, f32 yz, f32 zz) {
	m3f m;

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

m3f m3ftrans(m3f m) {
	return m3fnew(
		m.xx, m.xy, m.xz,
		m.yx, m.yy, m.yz,
		m.zx, m.zy, m.zz
	);
}

f32 m3fdet(m3f m) {
	f32 xx = m.xx;
	f32 yx = m.yx;
	f32 zx = m.zx;
	f32 xy = m.xy;
	f32 yy = m.yy;
	f32 zy = m.zy;
	f32 xz = m.xz;
	f32 yz = m.yz;
	f32 zz = m.zz;

	return
		zx*(xy*yz - xz*yy) +
		zy*(xz*yx - xx*yz) +
		zz*(xx*yy - xy*yx);
}

m3f m3finv(m3f m) {
	return m3fnumdiv(m3ftrans(m), m3fdet(m));
}

m3f m3fnumadd(m3f a, f32 b) {
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

m3f m3fnumsub(m3f a, f32 b) {
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

m3f m3fnummul(m3f a, f32 b) {
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

m3f m3fnumdiv(m3f a, f32 b) {
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

v3f m3fv3fmul(m3f a, v3f b) {
	f32 xx = a.xx;
	f32 yx = a.yx;
	f32 zx = a.zx;
	f32 xy = a.xy;
	f32 yy = a.yy;
	f32 zy = a.zy;
	f32 xz = a.xz;
	f32 yz = a.yz;
	f32 zz = a.zz;

	f32 x = b.x;
	f32 y = b.y;
	f32 z = b.z;

	return v3fnew(
		x*xx + y*yx + z*zx,
		x*xy + y*yy + z*zy,
		x*xz + y*yz + z*zz
	);
}

m3f m3fm3fmul(m3f a, m3f b) {
	f32 axx = a.xx;
	f32 axy = a.xy;
	f32 axz = a.xz;

	f32 ayx = a.yx;
	f32 ayy = a.yy;
	f32 ayz = a.yz;

	f32 azx = a.zx;
	f32 azy = a.zy;
	f32 azz = a.zz;


	f32 bxx = b.xx;
	f32 bxy = b.xy;
	f32 bxz = b.xz;

	f32 byx = b.yx;
	f32 byy = b.yy;
	f32 byz = b.yz;

	f32 bzx = b.zx;
	f32 bzy = b.zy;
	f32 bzz = b.zz;


	return m3fnew(
		axx*bxx + ayx*bxy + azx*bxz, axx*byx + ayx*byy + azx*byz, axx*bzx + ayx*bzy + azx*bzz,
		axy*bxx + ayy*bxy + azy*bxz, axy*byx + ayy*byy + azy*byz, axy*bzx + ayy*bzy + azy*bzz,
		axz*bxx + ayz*bxy + azz*bxz, axz*byx + ayz*byy + azz*byz, axz*bzx + ayz*bzy + azz*bzz
	);
}

m3f euleranglesx(f32 a) {
	return m3fnew(1, 0, 0, 0, cos(a), -sin(a), 0, sin(a), cos(a));
}

m3f euleranglesy(f32 a) {
	return m3fnew(cos(a), 0, sin(a), 0, 1, 0, -sin(a), 0, cos(a));
}

m3f euleranglesz(f32 a) {
	return m3fnew(cos(a), -sin(a), 0, sin(a), cos(a), 0, 0, 0, 1);
}

#endif
