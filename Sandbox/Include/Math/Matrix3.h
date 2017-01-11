#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Matrix3f
{
private:
    float m[9]; // Matrix data
public:
    
    // Ctor
    Matrix3f();
    Matrix3f(const class Vector3f&x, const class Vector3f&y, const class Vector3f&z);
	Matrix3f(const class Quaternion& q);

    ~Matrix3f();
    
    // Prints the matrix
    void Print() const;
    
    // Returns identity matrix
    static Matrix3f Identity();
	static Matrix3f Translation(const float x, const float y, const float z);
	static Matrix3f RotationX(float degrees);
	static Matrix3f RotationY(float degrees);
	static Matrix3f RotationZ(float degrees);
	static Matrix3f Rotation(const class Quaternion& q);
	static Matrix3f Scale(const float x, const float y, const float z);
	static Matrix3f Scale(const float s);
	static Matrix3f ShearX(const float y, const float z);
	static Matrix3f ShearY(const float x, const float z);
	static Matrix3f ShearZ(const float x, const float y);

    // Access operator
    float& operator()(unsigned int row, unsigned int col);
    
    // Assignment operator
    Matrix3f& operator=(const Matrix3f& rhs);
    
    // Adition function
    static Matrix3f Add(const Matrix3f& lhs, const Matrix3f& rhs);
    
    // Subtraction function
    static Matrix3f Subtract(const Matrix3f& lhs, const Matrix3f& rhs);
    
    // Multiply Functions
    static Matrix3f Multiply(const Matrix3f& lhs, const float rhs);
    static Matrix3f Multiply(const Matrix3f& lhs, const Matrix3f& rhs);
    static class Vector3f Multiply(const Matrix3f& lhs, const class Vector3f& rhs);
    
	// Computes the determinant of the matrix
	static float Determinant(const Matrix3f& m);
	float Determinant();

    // Returns the diagonal of the matrix in vector form
    class Vector3f GetDiagonal() const;
    
    // Returns the sum of the diagonal
    float GetTrace() const;
    
	// Affine transformations
	void TranslateBy(const float x, const float y, const float z);
	void TranslateBy(const class Vector3f& t);

	// Loads matrix from quaternion
	Matrix3f& FromQuaternion(const class Quaternion& quat);
};

// Addition Operator
inline  Matrix3f operator+(const Matrix3f& lhs, const Matrix3f& rhs) { return Matrix3f::Add(lhs, rhs); }

// Subtraction Operator
inline  Matrix3f operator-(const Matrix3f& lhs, const Matrix3f& rhs) { return Matrix3f::Subtract(lhs, rhs); }

// Multiplication operators
inline  Matrix3f operator*(const Matrix3f& lhs, const float rhs) { return Matrix3f::Multiply(lhs, rhs); }
inline  Matrix3f operator*(const float lhs, const Matrix3f& rhs) { return Matrix3f::Multiply(rhs, lhs); }
inline  Matrix3f operator*(const Matrix3f& lhs, const Matrix3f& rhs) { return Matrix3f::Multiply(lhs, rhs); }
inline  Vector3f operator*(const Matrix3f& lhs, const class Vector3f& rhs) { return Matrix3f::Multiply(lhs, rhs); }
