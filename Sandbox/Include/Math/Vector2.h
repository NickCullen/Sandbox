#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Vector2f
{
public: 
	static void Initialize();

public:
	// Members
	float x;
	float y;
	
	template<class Archive>
	void serialize(Archive& ar)
	{
		_SERIALIZE_VAR(x, ar);
		_SERIALIZE_VAR(y, ar);
	}

	// Debug Print
	void Print();
	
	// Constructors
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(const Vector2f& other);
	Vector2f(const class Vector3f& other);
	Vector2f(const class Vector4f& other);
    
    // Quick access vectors
    static Vector2f Up();
    static Vector2f Right();
	static Vector2f Zero();

	// Return is zero vector
	bool IsZero() const;

    
	// Addition
	static Vector2f Add(const Vector2f& lhs, const Vector2f& rhs);

	// Subtraction
	static Vector2f Subtract(const Vector2f& lhs, const Vector2f& rhs);
	
	// Scalar Multiplication
	static Vector2f Multiply(const Vector2f& vec, float scalar);

	// Scalar Division
	static Vector2f Divide(const Vector2f& vec, float scalar);

	// Dot Product
	static float DotProduct(const Vector2f& lhs, const Vector2f& rhs);

	// Non-static version of Dot Product
   // float DotProduct(const Vector2f& other) const;

	// Returns the length of the vector
	float Length() const;

	// Returns the length squared of the vector (no sqrt)
	float LengthSquared() const;

	// Normalizes this vector and returns it
	Vector2f& Normalize();

	// Returns the normalized representation of this vector without altering its value
	Vector2f Normalized() const;

	// Returns distance between the vectors (uses sqrt)
	static float Distance(const Vector2f& lhs, const Vector2f& rhs);

	// non-static distance function (uses sqrt)
	//float Distance(const Vector2f& other) const;

	// Returns squared distance between the vectors (doesn't use sqrt)
	static float DistanceSquared(const Vector2f& lhs, const Vector2f& rhs);

	// non-static distance squared function (doesn't use sqrt)
	//float DistanceSquared(const Vector2f& other) const;
    
    // Returns the perpendicular vector of this
    Vector2f Perpendicular() const;

	// Converts polar coordinates (in vector2f form) to cartesian and returns a Vector
	static Vector2f PolarToCartesian(const Vector2f& polarCoord);

	// Converts cartesian coordinates into polar coordinates and returns a vector
	static Vector2f CartesianToPolar(const Vector2f& cartesianCoord);
};


// Addition Operator
inline  Vector2f operator+(const Vector2f& lhs, const Vector2f& rhs) { return Vector2f::Add(lhs, rhs); }

// Subtraction Operator
inline  Vector2f operator-(const Vector2f& lhs, const Vector2f& rhs) { return Vector2f::Subtract(lhs, rhs); }

// Multiplication Operators
inline  Vector2f operator*(float scalar, const Vector2f& vec) { return Vector2f::Multiply(vec, scalar); }
inline  Vector2f operator*(const Vector2f& vec, float scalar) { return Vector2f::Multiply(vec, scalar); }

// Division Operators
inline  Vector2f operator/(float scalar, const Vector2f& vec) { return Vector2f::Divide(vec, scalar); }
inline  Vector2f operator/(const Vector2f& vec, float scalar) { return Vector2f::Divide(vec, scalar); }
