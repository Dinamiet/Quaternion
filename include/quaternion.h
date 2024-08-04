#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "vector.h"

typedef struct _Quaternion_
{
	float  R;
	Vector V;
} Quaternion;

Quaternion Quaternion_Create(Vector v, float theta);
Quaternion Quaternion_Add(const Quaternion a, const Quaternion b);
Quaternion Quaternion_Multiply(const Quaternion a, const Quaternion b);
Quaternion Quaternion_Unit(const Quaternion a);
Vector     Quaternion_RotateVector(const Vector v, const Quaternion q);

#endif
