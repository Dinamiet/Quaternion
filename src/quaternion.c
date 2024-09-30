#include "quaternion.h"

#include <math.h>

Quaternion Quaternion_Create(const Vector v, const float theta)
{
	Quaternion q;

	float c = cosf(theta / 2.0f);
	float s = sinf(theta / 2.0f);

	q.R   = c;
	q.V.X = v.X * s;
	q.V.Y = v.Y * s;
	q.V.Z = v.Z * s;

	return q;
}

Quaternion Quaternion_Make(const float w, const float x, const float y, const float z)
{
	Quaternion q;

	q.R   = w;
	q.V.X = x;
	q.V.Y = y;
	q.V.Z = z;

	return q;
}

Quaternion Quaternion_Scale(const Quaternion q, const float scale)
{
	Quaternion scaled;

	scaled.R   = q.R * scale;
	scaled.V.X = q.V.X * scale;
	scaled.V.Y = q.V.Y * scale;
	scaled.V.Z = q.V.Z * scale;

	return scaled;
}

Quaternion Quaternion_Multiply(const Quaternion a, const Quaternion b)
{
	Quaternion q;

	q.R = a.R * b.R - Vector_Dot(a.V, b.V);

	Vector tmp = Vector_Add(Vector_Scale(b.V, a.R), Vector_Scale(a.V, b.R));
	q.V        = Vector_Add(tmp, Vector_Cross(a.V, b.V));

	return q;
}

Quaternion Quaternion_Unit(const Quaternion a)
{
	Quaternion q;
	float      size = sqrtf(a.R * a.R + a.V.X * a.V.X + a.V.Y * a.V.Y + a.V.Z * a.V.Z);

	q.R   = a.R / size;
	q.V.X = a.V.X / size;
	q.V.Y = a.V.Y / size;
	q.V.Z = a.V.Z / size;

	return q;
}

void Quaternion_VectorAngle(const Quaternion q, Vector* v, float* theta)
{
	*theta  = 2.0f * acosf(q.R);
	float s = sinf(*theta / 2.0f);
	v->X    = q.V.X / s;
	v->Y    = q.V.Y / s;
	v->Z    = q.V.Z / s;
}

Vector Quaternion_RotateVector(const Vector v, const Quaternion q)
{
	Vector t    = Vector_Cross(Vector_Scale(q.V, 2.0f), v);
	Vector tmp1 = Vector_Scale(t, q.R);
	Vector tmp2 = Vector_Cross(q.V, t);

	Vector sum = Vector_Add(tmp1, tmp2);
	return Vector_Add(v, sum);
}

void Quaternion_YawPitchRoll(const Quaternion q, float* yaw, float* pitch, float* roll)
{
	*roll  = atan2f(2 * (q.R * q.V.X + q.V.Y * q.V.Z), 1 - 2 * (q.V.X * q.V.X + q.V.Y * q.V.Y));
	*pitch = asinf(2 * (q.R * q.V.Y - q.V.X * q.V.Z));
	*yaw   = atan2f(2 * (q.R * q.V.Z + q.V.X * q.V.Y), 1 - 2 * (q.V.Y * q.V.Y + q.V.Z * q.V.Z));
}
