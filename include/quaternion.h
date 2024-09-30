#ifndef _QUATERNION_H_
#define _QUATERNION_H_

/**
 * \file
 *
 * Quaternion
 *
 * Quaternion library
 */

#include "vector.h"

/**
 * Quaternion structure
 */
typedef struct _Quaternion_
{
	float  R; /** Quaternion R component */
	Vector V; /** Quaternion Vector component */
} Quaternion;

/**
 * Create a Quaternion from a vector and angle
 * \param v Vector
 * \param theta Angle
 * \return New Quaternion
 */
Quaternion Quaternion_Create(const Vector v, const float theta);

/**
 * Create a Quaternion from its individial components
 * \param w Quaternion W component
 * \param x Quaternion X component
 * \param y Quaternion Y component
 * \param z Quaternion Z component
 * \return New Quaternion
 */
Quaternion Quaternion_Make(const float w, const float x, const float y, const float z);

/**
 * Scales a quaternion by a factor
 * \param q Quaternion to scale
 * \param scale Factor by which to scale
 * \return New scaled quaternion
 */
Quaternion Quaternion_Scale(const Quaternion q, const float scale);

/**
 * Multiply quaternions
 * \param a Quaternion A
 * \param b Quaternion B
 * \return A * B
 */
Quaternion Quaternion_Multiply(const Quaternion a, const Quaternion b);

/**
 * Creates a unit quaternion
 * \param a Quaternion A
 * \return Unit quaternion
 */
Quaternion Quaternion_Unit(const Quaternion a);

/**
 * Quaternion's vector and rotation components
 * \param q The quaternion
 * \param v The rotation vector of q
 * \param theta Rotation angle around v of q
 */
void Quaternion_VectorAngle(const Quaternion q, Vector* v, float* theta);

/**
 * Rotates vector according to a quaternion
 * \param v Vector to rotate
 * \param q Rotation quaternion
 * \return Rotated vector
 */
Vector Quaternion_RotateVector(const Vector v, const Quaternion q);

/**
 * Retreive quaternion's rotation values
 * \param q The Quaternion
 * \param yaw The Yaw angle of q
 * \param pitch The Pitch angle of q
 * \param roll The Roll angle of q
 */
void Quaternion_YawPitchRoll(const Quaternion q, float* yaw, float* pitch, float* roll);

#endif
