#include "quaternion.h"

#include <math.h>

Quaternion Quaternion_Create(Vector v, float theta)
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

Quaternion Quaternion_Add(const Quaternion a, const Quaternion b)
{
	Quaternion q;
	q.R = a.R + b.R;
	q.V = Vector_Add(a.V, b.V);

	return q;
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

Vector Quaternion_RotateVector(const Vector v, const Quaternion q)
{
	Vector t    = Vector_Cross(Vector_Scale(q.V, 2.0f), v);
	Vector tmp1 = Vector_Scale(t, q.R);
	Vector tmp2 = Vector_Cross(q.V, t);

	Vector sum = Vector_Add(tmp1, tmp2);
	return Vector_Add(v, sum);
}
