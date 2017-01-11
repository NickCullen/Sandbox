#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Vector3f
{
public:
	float x;
	float y;
	float z;
	
	template<class Archive>
	void serialize(Archive& ar)
	{
		_SERIALIZE_VAR(x, ar);
		_SERIALIZE_VAR(y, ar);
		_SERIALIZE_VAR(z, ar);
	}

	// Debug Print
	void Print();
	
	// Constructors
	Vector3f();
	Vector3f(float x, float y, float z);
	Vector3f(const Vector3f& other);
	Vector3f(const class Vector4f& other);
    
    // Quick access vectors
    static Vector3f Up();
    static Vector3f Right();
    static Vector3f Forward();
	static Vector3f Zero();

	// Returns true if vector is zero
	bool IsZero() const;

	// Addition
	static Vector3f Add(const Vector3f& lhs, const Vector3f& rhs);

	// Subtraction
	static Vector3f Subtract(const Vector3f& lhs, const Vector3f& rhs);

	// Scalar Multiplication
	static Vector3f Multiply(const Vector3f& vec, float scalar);

	// Scalar Division
	static Vector3f Divide(const Vector3f& vec, float scalar);

	// Dot Product
	static float DotProduct(const Vector3f& lhs, const Vector3f& rhs);

	// Non-static version of Dot Product
    float DotProduct(const Vector3f& other) const;

	// Cross Product
	static Vector3f CrossProduct(const Vector3f& lhs, const Vector3f& rhs);

	// Non-static version of Cross Product
    Vector3f CrossProduct(const Vector3f& other) const;

	// Returns the length of the vector
	float Length() const;

	// Returns the length squared of the vector (no sqrt)
	float LengthSquared() const;

	// Normalizes this vector and returns it
	Vector3f& Normalize();

	// Returns the normalized representation of this vector without altering its value
	Vector3f Normalized() const;

	// Returns distance between the vectors (uses sqrt)
	static float Distance(const Vector3f& lhs, const Vector3f& rhs);

	// non-static distance function (uses sqrt)
	float Distance(const Vector3f& other) const;

	// Returns squared distance between the vectors (doesn't use sqrt)
	static float DistanceSquared(const Vector3f& lhs, const Vector3f& rhs);

	// non-static distance squared function (doesn't use sqrt)
	float DistanceSquared(const Vector3f& other) const;

	// Converts spherical coordinates to cartesian
	static Vector3f SphericalToCartesian(const Vector3f& sphericalCoord);

	// Converts Cartesian Coordinates to spherical
	static Vector3f CartesianToSpherical(const Vector3f& cartesianCoord);


};


// Addition Operator
inline  Vector3f operator+(const Vector3f& lhs, const Vector3f& rhs) { return Vector3f::Add(lhs, rhs); }

// Subtraction Operator
inline  Vector3f operator-(const Vector3f& lhs, const Vector3f& rhs) { return Vector3f::Subtract(lhs, rhs); }

// Multiplication Operators
inline  Vector3f operator*(float scalar, const Vector3f& vec) { return Vector3f::Multiply(vec, scalar); }
inline  Vector3f operator*(const Vector3f& vec, float scalar) { return Vector3f::Multiply(vec, scalar); }

// Division Operators
inline  Vector3f operator/(float scalar, const Vector3f& vec) { return Vector3f::Divide(vec, scalar); }
inline  Vector3f operator/(const Vector3f& vec, float scalar) { return Vector3f::Divide(vec, scalar); }
