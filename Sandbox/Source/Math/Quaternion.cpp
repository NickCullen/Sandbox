#include "Math/MathLib.h"

Quaternion::Quaternion(const Vector3f& v)
	:x(v.x), y(v.y), z(v.z), w(1)
{

}

Quaternion::Quaternion(const Vector4f& v)
	: x(v.x), y(v.y), z(v.z), w(v.w)
{

}

Quaternion Quaternion::Add(const Quaternion& q1, const Quaternion& other)
{
	return Quaternion(q1.w + other.w, q1.x + other.x, q1.y + other.y, q1.z + other.z);
}

Quaternion Quaternion::operator+(const Quaternion& other)
{
	return Quaternion::Add(*this, other);
}

Quaternion Quaternion::Multiply(const Quaternion& q1, const Quaternion& other)
{
	return Quaternion(q1.w * other.w, q1.x * other.x, q1.y * other.y, q1.z * other.z);
}

Quaternion Quaternion::Multiply(const Quaternion& q1, const float s)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator*(const Quaternion& other)
{
	return Quaternion::Multiply(*this, other);
}

Quaternion Quaternion::Subtract(const Quaternion& q1, const Quaternion& other)
{
	return Quaternion(q1.w - other.w, q1.x - other.x, q1.y - other.y, q1.z - other.z);
}

Quaternion Quaternion::operator-(const Quaternion& other)
{
	return Quaternion::Subtract(*this, other);
}

float Quaternion::Length(const Quaternion& q)
{
	return Mathf::Sqrt((q.w*q.w) + (q.x*q.x) + (q.y*q.y) + (q.z*q.z));
}

float Quaternion::Length()
{
	return Quaternion::Length(*this);
}

Quaternion& Quaternion::Normalize(Quaternion& q)
{
	float len = Quaternion::Length(q);
	q.x /= len;
	q.y /= len;
	q.z /= len;
	q.w /= len;
	return q;
}

Quaternion& Quaternion::Normalize()
{
	return Quaternion::Normalize(*this);
}

Quaternion Quaternion::Normalized()
{
	Quaternion ret = *this;
	return Quaternion::Normalize(ret);
}

float Quaternion::Dot(const Quaternion& q1, const Quaternion& q2)
{
	return (q1.x * q2.x) + (q1.y * q2.y) + (q1.z * q2.z) + (q1.w * q2.w);
}

float Quaternion::Dot(const Quaternion& other)
{
	return Quaternion::Dot(*this, other);
}

Quaternion Quaternion::EulerAngles(const float x, const float y, const float z)
{
	float C1 = Mathf::Cos(x* 0.5f);
	float C2 = Mathf::Cos(y* 0.5f);
	float C3 = Mathf::Cos(z* 0.5f);

	float S1 = Mathf::Sin(x* 0.5f);
	float S2 = Mathf::Sin(y* 0.5f);
	float S3 = Mathf::Sin(z* 0.5f);

	Quaternion q;

	q.w = (C1 * C2 * C3) - (S1 * S2 * S3);
	q.x = (S1 * C2 * C3) + (C1 * S2 * S3);
	q.y = (C1 * S2 * C3) - (S1 * C2 * S3);
	q.z = (C1 * C2 * S3) + (S1 * S2 * C3);

	return q;
}

Quaternion Quaternion::EulerAngles(const class Vector3f& angles)
{
	return Quaternion::EulerAngles(angles.x, angles.y, angles.z);
}