#ifndef ZEROMATH_H
#define ZEROMATH_H

#include "zerolibc.h"

#define ET 0.7853982f
#define QT 1.5707963f
#define PI 3.1415927f
#define IP 0.3183099f
#define TAU 6.2831853f
#define E 2.7182818f
#define RT 1.4142136f
#define PHI 1.6180340f
#define IHP 0.6180340f
#define MAN 0x007fffff

#define MINI(a, b) a^(a^b) & -(a > b)
#define MAXI(a, b) a^(a^b) & -(a < b)
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
#define CLAMP(n, l, h) MAX(l, MIN(n, h))
#define ABS(n) n < 0 ? n : -n
#define POW(b, e) exp(LOG(b)*e)
#define LOG(n) 0.6931472f*log2(n)
#define FLRP32(n) (i32)(n)
#define RNDP(n) FLRP32(n + 0.5f)
#define NFIB(n) RNDP(0.4472136f*(POW(PHI, n) - POW(-IHP, n)))
#define STIR(n) sqrt(2*PI*n)*POW(n/E, n)
#define FMODP32(n, d) (n - (i32)(n/d)*d)

#define FPACC 11
#define FPNEW(i) i << FPACC
#define FPMUL(a, b) a*b >> FPACC
#define FPDIV(a, b) (FPNEW(a))/b

#define LOW(a) a & 0xffff
#define HIW(a) LOW(a >> 16)


typedef union {
	f32 f;
	i32 i;
} f_u;

static f32 exp(f32 n) {
	f_u u;

	/*exp(n) = 2^i*2^f; i = FLR(log2(e)*x), 0 <= f <= 1*/
	n *= 1.4426950f;
	i32 i = FLRP32(n);
	f32 f = n - (f32)i;

	u.f = (0.3371894f*f + 0.6576363f)*f + 1.0017248f;/*compute 2^f*/
	u.i += i << 23;/*scale by 2^i*/

	return u.f;
}

static f32 log2(f32 x) {
	f_u a, b;

	a.f = x;

	b.i = (a.i & MAN) | 0x3f800000;
	b.f -= 1;

	return ((a.i & 0x7f800000) >> 23) - 127 - 0.6276936f*b.f*b.f + 1.4649446f*b.f;
}

static f32 sqrt(f32 n) {
	f_u u;

	u.f = n;
	u.i = 0x1fc00000 + (u.i >> 1);

	u.f = 0.5f*(u.f + n/u.f);/*Baybylonian #1*/

	return u.f;
}

static f32 isqrt(f32 n) {
	f_u u;

	u.f = n;
	u.i = 0x5f3759df - (u.i >> 1);

	u.f *= 0.5f*(3 - n*u.f*u.f);/*Newton #1*/

	return u.f;
}

static f32 fact(f32 x) {
	return x > 0 ? x*fact(x - 1) : 1;
}



















#define TAN(x) (SIN(x)/COS(x))
#define SINP(t) cosp(t - QT)

static f32 cosp(f32 t) {
	t *= IP;
	i32 i = RNDP(t);
	f32 f = t - (f32)i;
	return (1 + i%2*~1)*(1 + (3.6527833f*f*f - 4.9070450f)*f*f);
}

static f32 atan2(f32 c, f32 s) {
	f32 o = 0;

	if (s < 0) {
		c = -c;
		s = -s;
		o -= PI;
	}

	if (c < 0) {
		f32 t = c;
		c = s;
		s = -t;
		o += QT;
	}

	if (c < s) {
		f32 t = c;
		c += s;
		s -= t;
		o += ET;
	}

	f32 d = 2/(c*c + s*s);
	f32 x = d*c*c - 1;
	f32 y = d*c*s;

	return
		o +
		0.3926991f -
		0.5574841f*(x - y) +
		0.1648119f*(x*x - y*y) -
		0.0584015f*(x*x*y - y*y*x);
}

/*inverse*/
/*[-1, 1]*/
static f32 acos(f32 x) {
	return
		1.5707963f -
		1.0469419f*x +
		0.1610680f*x*x*x -
		0.5315243f*x*x*x*x*x;
}

/*[-1, 1]*/
static f32 asin(f32 x) {
	return
		1.0469419f*x -
		0.1610680f*x*x*x +
		0.5315243f*x*x*x*x*x;
}

/*[-1, 1]*/
static f32 atan(f32 x) {
	return
		0.9959826f*x -
		0.2922813f*x*x*x +
		0.0830216f*x*x*x*x*x;
}

/*forward hyperbolic*/
static f32 cosh(f32 x) {
	f32 y = exp(x);
	return 0.5f*(1/y + y);
}

static f32 sinh(f32 x) {
	f32 y = exp(x);
	return 0.5f*(y - 1/y);
}

static f32 tanh(f32 x) {
	f32 y = exp(2*x);
	return (y - 1)/(y + 1);
}

/*inverse hyperbolic*/
static f32 Acosh(f32 x) {
	return LOG(x + sqrt(x*x - 1));
}

static f32 asinh(f32 x) {
	return LOG(x + sqrt(x*x + 1));
}

static f32 atanh(f32 x) {
	return 0.5f*(LOG(1 + x) - LOG(1 - x));
}

































typedef struct {
	f32 x;
	f32 y;
} v2f;

static v2f v2f_v2fadd(v2f a, v2f b);
static v2f v2f_v2fsub(v2f a, v2f b);

static v2f v2f_numadd(v2f a, f32 b);
static v2f v2f_numsub(v2f a, f32 b);
static v2f v2f_nummul(v2f a, f32 b);
static v2f v2f_numdiv(v2f a, f32 b);













typedef struct {
	f32 x;
	f32 y;
	f32 z;
} v3f;

static v3f v3f_v3fadd(v3f a, v3f b);
static v3f v3f_v3fsub(v3f a, v3f b);
static v3f v3f_v3fmul(v3f a, v3f b);
static v3f v3f_v3fdiv(v3f a, v3f b);

static v3f v3f_numadd(v3f a, f32 b);
static v3f v3f_numsub(v3f a, f32 b);
static v3f v3f_nummul(v3f a, f32 b);
static v3f v3f_numdiv(v3f a, f32 b);

static f32 v3f_len(v3f v);

static f32 v3f_dot(v3f a, v3f b);

static v3f v3f_unit(v3f v);

static f32 v3f_dotself(v3f v);

static f32 v3f_dist(v3f a, v3f b);

static v3f v3f_tween(v3f a, v3f b, f32 p);

static v3f v3f_reflect(v3f v, v3f n);













typedef struct {
	f32 x;
	f32 y;
	f32 z;
	f32 w;
} v4f;

static v4f v4f_v4fadd(v4f a, v4f b);
static v4f v4f_v4fsub(v4f a, v4f b);
static v4f v4f_v4fmul(v4f a, v4f b);
static v4f v4f_v4fdiv(v4f a, v4f b);

static v4f v4f_numadd(v4f a, f32 b);
static v4f v4f_numsub(v4f a, f32 b);
static v4f v4f_nummul(v4f a, f32 b);
static v4f v4f_numdiv(v4f a, f32 b);

static f32 v4f_len(v4f v);

static f32 v4f_dot(v4f a, v4f b);

static v4f v4f_unit(v4f v);






















/*

typedef struct {
	f32 x;
	f32 y;
	f32 z;
	f32 w;
} qt;

/*qt qt_ident = new(1, 0, 0, 0);*/

/*

static qt qt_new(f32 w, f32 x, f32 y, f32 z) {
	qt newqt;

	newqt_.w = w;
	newqt_.x = x;
	newqt_.y = y;
	newqt_.z = z;

	return newqt;
}

static qt qt_inv(qt q) {
	return qt_new(q.w, -q.x, -q.y, -q.z);
}

static qt qt_slerp(qt a, qt b, f32 n) {
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

	return qt_new(
		aw*bw - ax*bx - ay*by - az*bz,
		aw*bx + ax*bw - ay*bz + az*by,
		aw*by + ax*bz + ay*bw - az*bx,
		aw*bz - ax*by + ay*bx + az*bw
	};
}

static qt qt_eulerx(f32 a) {
	return qt_new(cos(0.5f*a), sin(0.5f*a), 0, 0);
}

static qt qt_eulery(f32 a) {
	return qt_new(cos(0.5f*a), 0, sin(0.5f*a), 0);
}

static qt qt_eulerz(f32 a) {
	return qt_new(cos(0.5f*a), 0, 0, sin(0.5f*a));
}

qt qt_m3f(m3f m) {
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
		return qt_new(0.25f*s, (yz - zy)/s, (zx - xz)/s, (xy - yx)/s);
	}
	else if (xx > yy && xx > zz) {
		f32 s = sqrt(2*(1 + xx - yy - zz));
		return qt_new((yz - zy)/s, 0.25f*s, (yx + xy)/s, (zx + xz)/s);
	}
	else if (yy > zz) {
		f32 s = sqrt(2*(1 - xx + yy - zz));
		return qt_new((zx - xz)/s, (yx + xy)/s, 0.25f*s, (zy + yz)/s);
	}
	else {
		f32 s = sqrt(2*(1 - xx - yy + zz));
		return qt_new((xy - yx)/s, (zx + xz)/s, (zy + yz)/s, 0.25f*s);
	}
}

qt qt_look(v3f a, v3f b) {
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

	if (q < 1e-6) return qt_new(1, 0, 0, 0);
	else return qt_new((w + m)/q, x/q, y/q, z/q);
}

qt qt_axisangle(v3f v) {
	f32 x = v.x;
	f32 y = v.y;
	f32 z = v.z;
	f32 m = sqrt(x*x + y*y + z*z);
	f32 s = sin(0.5f*m);
	return qt_new(cos(0.5f*m), s*x/m, s*y/m, s*z/m);
}

qt qt_qt_mul(qt a, qt b) {
	return qt_new(
		a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z,
		a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
		a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
		a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w
	};
}

qt qt_qt_pow(qt q, f32 n) {
	f32 w = q.w;
	f32 x = q.x;
	f32 y = q.y;
	f32 z = q.z;
	f32 t = n*acos(w);
	f32 s = sin(t)/sqrt(x*x + y*y + z*z);
	return qt_new(cos(t), s*x, s*y, s*z);
}



*/

















/*

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

m3f m3ftrans(m3f m) {
	return (m3f){
		m.xx, m.xy, m.xz,
		m.yx, m.yy, m.yz,
		m.zx, m.zy, m.zz
	};
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

	return (v3f){
		x*xx + y*yx + z*zx,
		x*xy + y*yy + z*zy,
		x*xz + y*yz + z*zz
	};
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


	return (m3f){
		axx*bxx + ayx*bxy + azx*bxz, axx*byx + ayx*byy + azx*byz, axx*bzx + ayx*bzy + azx*bzz,
		axy*bxx + ayy*bxy + azy*bxz, axy*byx + ayy*byy + azy*byz, axy*bzx + ayy*bzy + azy*bzz,
		axz*bxx + ayz*bxy + azz*bxz, axz*byx + ayz*byy + azz*byz, axz*bzx + ayz*bzy + azz*bzz
	};
}

m3f euleranglesx(f32 a) {
	return (m3f){1, 0, 0, 0, cos(a), -sin(a), 0, sin(a), cos(a));
}

m3f euleranglesy(f32 a) {
	return (m3f){cos(a), 0, sin(a), 0, 1, 0, -sin(a), 0, cos(a));
}

m3f euleranglesz(f32 a) {
	return (m3f){cos(a), -sin(a), 0, sin(a), cos(a), 0, 0, 0, 1);
}
*/



















//static u64 s1, s2, s3, b;
static u32 s1, s2, s3, b;

static u32 rnd_s;
static u32 rnd_u32() { rnd_s += 0xff80; rnd_s ^= rnd_s >> 1; return rnd_s; }

static f32 rnd_f32() {
	/*Generates numbers between 0 and 1.*/
	b = (((s1 << 13)^s1) >> 19);
	s1 = (((s1 & 4294967294) << 12)^b);
	b = (((s2 << 2)^s2) >> 25);
	s2 = (((s2 & 4294967288) << 4)^b);
	b = (((s3 << 3)^s3) >> 11);
	s3 = (((s3 & 4294967280) << 17)^b);
	return (f32)((s1^s2^s3) * 2.3283064365e-10);
}

#define rnd_uniform() rnd_f32()
#define rnd_uniform2() (v2f){rnd_f32(), rnd_f32()}
#define rnd_uniform3() (v3f){rnd_f32(), rnd_f32(), rnd_f32()}
#define rnd_uniform4() (v4f){rnd_f32(), rnd_f32(), rnd_f32(), rnd_f32()}

static v2f rnd_gaussian2() {
	f32 m = sqrt(-2*LOG(1 - rnd_f32()));
	f32 a = TAU*rnd_f32();
	return (v2f){
		m*cosp(a),
		m*SINP(a)
	};
}

static v4f rnd_gaussian4() {
	f32 m0 = sqrt(2*LOG(1 - rnd_f32()));
	f32 m1 = sqrt(2*LOG(1 - rnd_f32()));
	f32 a0 = TAU*rnd_f32();
	f32 a1 = TAU*rnd_f32();
	return (v4f){
		m0*cosp(a0),
		m0*SINP(a0),
		m1*cosp(a1),
		m1*SINP(a1)
	};
}

#define RND_UNIT() rnd_f32() < 0.5f ? -1 : 1

static v2f rnd_unit2() {
	f32 a = TAU*rnd_f32();
	return (v2f){
		cosp(a),
		SINP(a)
	};
}

static v3f rnd_unit3() {
	f32 x = 2*rnd_f32() - 1;
	f32 i = sqrt(1 - x*x);
	f32 a = TAU*rnd_f32();
	return (v3f){
		x,
		i*cosp(a),
		i*SINP(a)
	};
}

static v4f rnd_unit4() {
	f32 l0 = LOG(1 - rnd_f32());
	f32 l1 = LOG(1 - rnd_f32());
	f32 m0 = sqrt(l0/(l0 + l1));
	f32 m1 = sqrt(l1/(l0 + l1));
	f32 a0 = TAU*rnd_f32();
	f32 a1 = TAU*rnd_f32();
	return (v4f){
		m0*cosp(a0),
		m0*SINP(a0),
		m1*cosp(a1),
		m1*SINP(a1)
	};
}

#define RND_TRIANGULAR() (rnd_f32() + rnd_f32() - 1)
#define RND_TRIANGULAR2() (v2f){rnd_f32() + rnd_f32() - 1, rnd_f32() + rnd_f32() - 1}
#define RND_TRIANGULAR3() (v3f){rnd_f32() + rnd_f32() - 1, rnd_f32() + rnd_f32() - 1, rnd_f32() + rnd_f32() - 1}
#define RND_TRIANGULAR4() (v4f){rnd_f32() + rnd_f32() - 1, rnd_f32() + rnd_f32() - 1, rnd_f32() + rnd_f32() - 1, rnd_f32() + rnd_f32() - 1}

#define RND_TRIANGULAR4x2() (v4f){2*(rnd_f32() + rnd_f32() - 1), 2*(rnd_f32() + rnd_f32() - 1), 2*(rnd_f32() + rnd_f32() - 1), 2*(rnd_f32() + rnd_f32() - 1)}







#endif