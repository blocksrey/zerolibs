#include "quat.h"

//quat quatident = new(1.0f, 0.0f, 0.0f, 0.0f);

quat quatnew(float w, float x, float y, float z) {
	quat newquat;

	newquat.w = w;
	newquat.x = x;
	newquat.y = y;
	newquat.z = z;

	return newquat;
}

quat quatinv(quat q) {
	return quatnew(q.w, -q.x, -q.y, -q.z);
}

quat slerp(quat a, quat b, float n) {
	float aw = a.w;
	float ax = a.x;
	float ay = a.y;
	float az = a.z;

	float bw = b.w;
	float bx = b.x;
	float by = b.y;
	float bz = b.z;

	if (aw*bw + ax*bx + ay*by + az*bz < 0) {
		aw = -aw;
		ax = -ax;
		ay = -ay;
		az = -az;
	}

	float w = aw*bw + ax*bx + ay*by + az*bz;
	float x = aw*bx - ax*bw + ay*bz - az*by;
	float y = aw*by - ax*bz - ay*bw + az*bx;
	float z = aw*bz + ax*by - ay*bx - az*bw;

	float t = n*acos(w);
	float s = sin(t)/sqrt(x*x + y*y + z*z);

	bw = cos(t);
	bx = s*x;
	by = s*y;
	bz = s*z;

	return quatnew(
		aw*bw - ax*bx - ay*by - az*bz,
		aw*bx + ax*bw - ay*bz + az*by,
		aw*by + ax*bz + ay*bw - az*bx,
		aw*bz - ax*by + ay*bx + az*bw
	);
}

quat quateulerx(float a) {
	return quatnew(cos(0.5f*a), sin(0.5f*a), 0.0f, 0.0f);
}

quat quateulery(float a) {
	return quatnew(cos(0.5f*a), 0.0f, sin(0.5f*a), 0.0f);
}

quat quateulerz(float a) {
	return quatnew(cos(0.5f*a), 0.0f, 0.0f, sin(0.5f*a));
}

quat quatmat3(mat3 m) {
	float xx = m.xx;
	float yx = m.yx;
	float zx = m.zx;
	float xy = m.xy;
	float yy = m.yy;
	float zy = m.zy;
	float xz = m.xz;
	float yz = m.yz;
	float zz = m.zz;
	if (xx + yy + zz > 0.0f) {
		float s = sqrt(2.0f*(1 + xx + yy + zz));
		return quatnew(0.25f*s, (yz - zy)/s, (zx - xz)/s, (xy - yx)/s);
	}
	else if (xx > yy && xx > zz) {
		float s = sqrt(2.0f*(1 + xx - yy - zz));
		return quatnew((yz - zy)/s, 0.25f*s, (yx + xy)/s, (zx + xz)/s);
	}
	else if (yy > zz) {
		float s = sqrt(2.0f*(1 - xx + yy - zz));
		return quatnew((zx - xz)/s, (yx + xy)/s, 0.25f*s, (zy + yz)/s);
	}
	else {
		float s = sqrt(2.0f*(1 - xx - yy + zz));
		return quatnew((xy - yx)/s, (zx + xz)/s, (zy + yz)/s, 0.25f*s);
	}
}

quat quatlook(vec3 a, vec3 b) {
	float ax = a.x;
	float ay = a.y;
	float az = a.z;

	float bx = b.x;
	float by = b.y;
	float bz = b.z;

	float w = ax*bx + ay*by + az*bz;
	float x = ay*bz - az*by;
	float y = az*bx - ax*bz;
	float z = ax*by - ay*bz;

	float m = sqrt(w*w + x*x + y*y + z*z);
	float q = sqrt(2.0f*m*(m + w));

	if (q < 1e-6) return quatnew(1.0f, 0.0f, 0.0f, 0.0f);
	else return quatnew((w + m)/q, x/q, y/q, z/q);
}

quat quataxisangle(vec3 v) {
	float x = v.x;
	float y = v.y;
	float z = v.z;
	float m = sqrt(x*x + y*y + z*z);
	float s = sin(0.5f*m);
	return quatnew(cos(0.5f*m), s*x/m, s*y/m, s*z/m);
}

quat quatquatmul(quat a, quat b) {
	return quatnew(
		a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z,
		a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
		a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
		a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w
	);
}

quat quatquatpow(quat q, float n) {
	float w = q.w;
	float x = q.x;
	float y = q.y;
	float z = q.z;
	float t = n*acos(w);
	float s = sin(t)/sqrt(x*x + y*y + z*z);
	return quatnew(cos(t), s*x, s*y, s*z);
}