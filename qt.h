#ifndef qt_h
#define qt_h

#include "maths.h"
#include "trig.h"
#include "m3f.h"
#include "v3f.h"
#include "rand.h"

typedef struct {
	f32 x;
	f32 y;
	f32 z;
	f32 w;
} qt;

//qt qtident = new(1, 0, 0, 0);

qt qtnew(f32 w, f32 x, f32 y, f32 z) {
	qt newqt;

	newqt.w = w;
	newqt.x = x;
	newqt.y = y;
	newqt.z = z;

	return newqt;
}

qt qtinv(qt q) {
	return qtnew(q.w, -q.x, -q.y, -q.z);
}

qt slerp(qt a, qt b, f32 n) {
	f32 aw = a.w;
	f32 ax = a.x;
	f32 ay = a.y;
	f32 az = a.z;

	f32 bw = b.w;
	f32 bx = b.x;
	f32 by = b.y;
	f32 bz = b.z;

	if (aw*bw + ax*bx + ay*by + az*bz < 0) {
		aw = -aw;
		ax = -ax;
		ay = -ay;
		az = -az;
	}

	f32 w = aw*bw + ax*bx + ay*by + az*bz;
	f32 x = aw*bx - ax*bw + ay*bz - az*by;
	f32 y = aw*by - ax*bz - ay*bw + az*bx;
	f32 z = aw*bz + ax*by - ay*bx - az*bw;

	f32 t = n*acos(w);
	f32 s = sin(t)/sqrt(x*x + y*y + z*z);

	bw = cos(t);
	bx = s*x;
	by = s*y;
	bz = s*z;

	return qtnew(
		aw*bw - ax*bx - ay*by - az*bz,
		aw*bx + ax*bw - ay*bz + az*by,
		aw*by + ax*bz + ay*bw - az*bx,
		aw*bz - ax*by + ay*bx + az*bw
	);
}

qt qteulerx(f32 a) {
	return qtnew(cos(0.5f*a), sin(0.5f*a), 0, 0);
}

qt qteulery(f32 a) {
	return qtnew(cos(0.5f*a), 0, sin(0.5f*a), 0);
}

qt qteulerz(f32 a) {
	return qtnew(cos(0.5f*a), 0, 0, sin(0.5f*a));
}

qt qtm3f(m3f m) {
	f32 xx = m.xx;
	f32 yx = m.yx;
	f32 zx = m.zx;
	f32 xy = m.xy;
	f32 yy = m.yy;
	f32 zy = m.zy;
	f32 xz = m.xz;
	f32 yz = m.yz;
	f32 zz = m.zz;
	if (xx + yy + zz > 0) {
		f32 s = sqrt(2*(1 + xx + yy + zz));
		return qtnew(0.25f*s, (yz - zy)/s, (zx - xz)/s, (xy - yx)/s);
	}
	else if (xx > yy && xx > zz) {
		f32 s = sqrt(2*(1 + xx - yy - zz));
		return qtnew((yz - zy)/s, 0.25f*s, (yx + xy)/s, (zx + xz)/s);
	}
	else if (yy > zz) {
		f32 s = sqrt(2*(1 - xx + yy - zz));
		return qtnew((zx - xz)/s, (yx + xy)/s, 0.25f*s, (zy + yz)/s);
	}
	else {
		f32 s = sqrt(2*(1 - xx - yy + zz));
		return qtnew((xy - yx)/s, (zx + xz)/s, (zy + yz)/s, 0.25f*s);
	}
}

qt qtlook(v3f a, v3f b) {
	f32 ax = a.x;
	f32 ay = a.y;
	f32 az = a.z;

	f32 bx = b.x;
	f32 by = b.y;
	f32 bz = b.z;

	f32 w = ax*bx + ay*by + az*bz;
	f32 x = ay*bz - az*by;
	f32 y = az*bx - ax*bz;
	f32 z = ax*by - ay*bz;

	f32 m = sqrt(w*w + x*x + y*y + z*z);
	f32 q = sqrt(2*m*(m + w));

	if (q < 1e-6) return qtnew(1, 0, 0, 0);
	else return qtnew((w + m)/q, x/q, y/q, z/q);
}

qt qtaxisangle(v3f v) {
	f32 x = v.x;
	f32 y = v.y;
	f32 z = v.z;
	f32 m = sqrt(x*x + y*y + z*z);
	f32 s = sin(0.5f*m);
	return qtnew(cos(0.5f*m), s*x/m, s*y/m, s*z/m);
}

qt qtqtmul(qt a, qt b) {
	return qtnew(
		a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z,
		a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
		a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
		a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w
	);
}

qt qtqtpow(qt q, f32 n) {
	f32 w = q.w;
	f32 x = q.x;
	f32 y = q.y;
	f32 z = q.z;
	f32 t = n*acos(w);
	f32 s = sin(t)/sqrt(x*x + y*y + z*z);
	return qtnew(cos(t), s*x, s*y, s*z);
}

#endif
