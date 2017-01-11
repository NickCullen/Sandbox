#pragma once

#include "SandboxAPI.h"
//#include "Vector4.h"

class SANDBOX_API Matrix4f
{
private:
    float m[16]; // Matrix data
public:
    
    Matrix4f();
    Matrix4f(const class Vector4f& x,const class Vector4f& y,const class Vector4f& z);
    Matrix4f(const class Vector4f& x,const class Vector4f& y,const class Vector4f& z, const class Vector4f& w);
	Matrix4f(const class Quaternion& q);

    ~Matrix4f();
    
    // Prints the matrix
    void Print() const;
    
    // Returns identity matrix
    static Matrix4f Identity();
	static Matrix4f Translation(const float x, const float y, const float z);
	static Matrix4f RotationX(float degrees);
	static Matrix4f RotationY(float degrees);
	static Matrix4f RotationZ(float degrees);
	static Matrix4f Rotation(const class Quaternion& q);
	static Matrix4f Scale(const float x, const float y, const float z);
	static Matrix4f Scale(const float s);
	static Matrix4f ShearX(const float y, const float z);
	static Matrix4f ShearY(const float x, const float z);
	static Matrix4f ShearZ(const float x, const float y);

    // Access operator
    float& operator()(unsigned int row, unsigned int col);
    
    // Assignment operator
    Matrix4f& operator=(const Matrix4f& rhs);
    
    // Adition function
    static Matrix4f Add(const Matrix4f& lhs, const Matrix4f& rhs);
    
    // Subtraction function
    static Matrix4f Subtract(const Matrix4f& lhs, const Matrix4f& rhs);
    
    // Multiply Functions
    static Matrix4f Multiply(const Matrix4f& lhs, const float rhs);
    static Matrix4f Multiply(const Matrix4f& lhs, const Matrix4f& rhs);
    static class Vector4f Multiply(const Matrix4f& lhs, const class Vector4f& rhs);
    
	// Determinants of 4x4 matrices are computed as 3x3 matrices for efficency
	static float Determinant(const Matrix4f& m);
	float Determinant();

    // Returns the diagonal of the matrix in vector form
    class Vector4f GetDiagonal() const;
    
    // Returns the sum of the diagonal
    float GetTrace() const;

	// Affine transformations
	void TranslateBy(const float x, const float y, const float z);
	void TranslateBy(const class Vector3f& t);
	void TranslateBy(const class Vector4f& t);

	// Loads matrix from quaternion
	Matrix4f& FromQuaternion(const class Quaternion& quat);
};

// Addition Operator
inline  Matrix4f operator+(const Matrix4f& lhs, const Matrix4f& rhs) { return Matrix4f::Add(lhs, rhs); }

// Subtraction Operator
inline  Matrix4f operator-(const Matrix4f& lhs, const Matrix4f& rhs) { return Matrix4f::Subtract(lhs, rhs); }

// Multiplication operators
inline  Matrix4f operator*(const Matrix4f& lhs, const float rhs) { return Matrix4f::Multiply(lhs, rhs); }
inline  Matrix4f operator*(const float lhs, const Matrix4f& rhs) { return Matrix4f::Multiply(rhs, lhs); }
inline  Matrix4f operator*(const Matrix4f& lhs, const Matrix4f& rhs) { return Matrix4f::Multiply(lhs, rhs); }
inline  Vector4f operator*(const Matrix4f& lhs, const class Vector4f& rhs) { return Matrix4f::Multiply(lhs, rhs); }
