#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Vector4f
{
public:
	float x;
	float y;
	float z;
	float w;
	
	template<class Archive>
	void serialize(Archive& ar)
	{
		_SERIALIZE_VAR(x, ar);
		_SERIALIZE_VAR(y, ar);
		_SERIALIZE_VAR(z, ar);
		w = 1.0f;
	}

	// Debug Print
	void Print();
	
	// Constructors
	Vector4f();
	Vector4f(float x, float y, float z, float w = 1.0f);
	Vector4f(const class Vector3f& other);
	Vector4f(const Vector4f& other);
    
    // Quick access vectors
    static Vector4f Up();
    static Vector4f Right();
    static Vector4f Forward();
	static Vector4f Zero();

	// Returns true if vector is zero
	bool IsZero() const;

	// Addition
	static Vector4f Add(const Vector4f& lhs, const Vector4f& rhs);

	// Subtraction
	static Vector4f Subtract(const Vector4f& lhs, const Vector4f& rhs);

	// Scalar Multiplication
	static Vector4f Multiply(const Vector4f& vec, float scalar);

	// Scalar Division
	static Vector4f Divide(const Vector4f& vec, float scalar);

	// Dot Product
	static float DotProduct(const Vector4f& lhs, const Vector4f& rhs);

	// Non-static version of Dot Product
	float DotProduct(const Vector4f& other) const;

	// Cross Product
	static Vector4f CrossProduct(const Vector4f& lhs, const Vector4f& rhs);

	// Non-static version of Cross Product
	Vector4f CrossProduct(const Vector4f& other) const;

	// Returns the length of the vector
	float Length() const;

	// Returns the length squared of the vector (no sqrt)
	float LengthSquared() const;

	// Normalizes this vector and returns it
	Vector4f& Normalize();

	// Returns the normalized representation of this vector without altering its value
	Vector4f Normalized() const;

	// Returns distance between the vectors (uses sqrt)
	static float Distance(const Vector4f& lhs, const Vector4f& rhs);

	// non-static distance function (uses sqrt)
	float Distance(const Vector4f& other) const;

	// Returns squared distance between the vectors (doesn't use sqrt)
	static float DistanceSquared(const Vector4f& lhs, const Vector4f& rhs);

	// non-static distance squared function (doesn't use sqrt)
	float DistanceSquared(const Vector4f& other) const;

	// Converts spherical coordinates to cartesian
	static Vector4f SphericalToCartesian(const Vector4f& sphericalCoord);

	// Converts Cartesian Coordinates to spherical
	static Vector4f CartesianToSpherical(const Vector4f& cartesianCoord);
};

// Addition Operator
inline  Vector4f operator+(const Vector4f& lhs, const Vector4f& rhs) { return Vector4f::Add(lhs, rhs); }

// Subtraction Operator
inline  Vector4f operator-(const Vector4f& lhs, const Vector4f& rhs) { return Vector4f::Subtract(lhs, rhs); }

// Multiplication Operators
inline  Vector4f operator*(float scalar, const Vector4f& vec) { return Vector4f::Multiply(vec, scalar); }
inline  Vector4f operator*(const Vector4f& vec, float scalar) { return Vector4f::Multiply(vec, scalar); }

// Division Operators
inline  Vector4f operator/(float scalar, const Vector4f& vec) { return Vector4f::Divide(vec, scalar); }
inline  Vector4f operator/(const Vector4f& vec, float scalar) { return Vector4f::Divide(vec, scalar); }
