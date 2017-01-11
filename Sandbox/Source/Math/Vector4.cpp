#include "Math/MathLib.h"
#include <stdio.h>

// Debug
void Vector4f::Print()
{
	printf("(%f, %f, %f, %f)\n",x,y,z,w);	
}


// Constructors
Vector4f::Vector4f()
{
	x = y = z = w = 0.0f;
}
Vector4f::Vector4f(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
Vector4f::Vector4f(const Vector3f& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = 0.0f;
}
Vector4f::Vector4f(const Vector4f& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
} 

// Static quick accessors
Vector4f Vector4f::Up()
{
    return Vector4f(0.0f, 1.0f, 0.0f, 0.0f);
}
Vector4f Vector4f::Right()
{
    return Vector4f(1.0f, 0.0f, 0.0f, 0.0f);
}
Vector4f Vector4f::Forward()
{
    return Vector4f(0.0f, 0.0f, 1.0f, 0.0f);
}
Vector4f Vector4f::Zero()
{
	return Vector4f(0.0f, 0.0f, 0.0f, 0.0f);
}

// Returns true if vector is zero
bool Vector4f::IsZero() const
{
	return (Mathf::IsZero(x) & Mathf::IsZero(y) & Mathf::IsZero(z) * Mathf::IsZero(w));
}

// Addition
Vector4f Vector4f::Add(const Vector4f& lhs, const Vector4f& rhs)
{
	return Vector4f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

// Subtraction
Vector4f Vector4f::Subtract(const Vector4f& lhs, const Vector4f& rhs)
{
	return Vector4f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

// Multiplication
Vector4f Vector4f::Multiply(const Vector4f& vec, float scalar)
{
	return Vector4f(vec.x*scalar, vec.y * scalar, vec.z*scalar, vec.w*scalar);
}

// Division
Vector4f Vector4f::Divide(const Vector4f& vec, float scalar)
{
	return Vector4f(vec.x/scalar, vec.y / scalar, vec.z/scalar, vec.w/scalar);
}

float Vector4f::Length() const
{
	return Mathf::Sqrt(x*x + y*y + z*z + w*w);
}

float Vector4f::LengthSquared() const
{
	return x*x + y*y + z*z + w*w;
}

Vector4f& Vector4f::Normalize()
{
	float lenRecip = 1.0f / Length();
	x *= lenRecip;
	y *= lenRecip;
	z *= lenRecip;
	w *= lenRecip;
	return *this;
}

Vector4f Vector4f::Normalized() const
{
	float lenRecip = 1.0f / Length();
	return Vector4f(x*lenRecip, y *lenRecip, z*lenRecip, w*lenRecip);
}

float Vector4f::DotProduct(const Vector4f& lhs, const Vector4f& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

float Vector4f::DotProduct(const Vector4f& other) const
{
	return Vector4f::DotProduct(*this, other);
}

Vector4f Vector4f::CrossProduct(const Vector4f& lhs, const Vector4f& rhs)
{
	return Vector4f(lhs.y*rhs.z - rhs.y*lhs.z,
					lhs.z*rhs.x - rhs.z*lhs.x,
					lhs.x*rhs.y - rhs.x*lhs.y);
}

Vector4f Vector4f::CrossProduct(const Vector4f& other) const
{
	return Vector4f::CrossProduct(*this, other);
}

float Vector4f::Distance(const Vector4f& lhs, const Vector4f& rhs)
{
	return (lhs - rhs).Length();
}

float Vector4f::Distance(const Vector4f& other) const
{
	return Vector4f::Distance(*this, other);
}

float Vector4f::DistanceSquared(const Vector4f& lhs, const Vector4f& rhs)
{
	return (lhs - rhs).LengthSquared();
}

float Vector4f::DistanceSquared(const Vector4f& other) const
{
	return Vector4f::DistanceSquared(*this, other);
}

Vector4f Vector4f::SphericalToCartesian(const Vector4f& s)
{
	return Vector4f(s.x * Mathf::Sin(s.y) * Mathf::Cos(s.z),
					s.x * Mathf::Sin(s.y) * Mathf::Sin(s.z),
					s.x * Mathf::Cos(s.y));
}

Vector4f Vector4f::CartesianToSpherical(const Vector4f& v)
{
	return Vector4f(v.Length(),														// p
					Mathf::Atan2(Mathf::Sqrt(v.x*v.x + v.y*v.y), v.z),				// theta
					Mathf::Atan2(v.y, v.x));										// omega
}