#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Matrix2f
{
private:
    float m[4]; // Matrix data
public:
    // Ctor
    Matrix2f();
    Matrix2f(const class Vector2f& x, const class Vector2f& y);
    
    // Dtor
    ~Matrix2f();
    
    // Prints the matrix
    void Print() const;
    
    // Returns identity matrix
    static Matrix2f Identity();
	static Matrix2f Translation(const float x, const float y);
	static Matrix2f Rotation(float degrees);
	static Matrix2f Scale(const float x, const float y);
	static Matrix2f Scale(const float s);
	static Matrix2f ShearX(const float y);
	static Matrix2f ShearY(const float x);

    // Access operator
    float& operator()(unsigned int row, unsigned int col);
    
    // Assignment operator
    Matrix2f& operator=(const Matrix2f& rhs);
    
    // Adition function
    static Matrix2f Add(const Matrix2f& lhs, const Matrix2f& rhs);
    
    // Subtraction function
    static Matrix2f Subtract(const Matrix2f& lhs, const Matrix2f& rhs);
    
    // Multiply functions
    static Matrix2f Multiply(const Matrix2f& lhs, const float rhs);
    static Matrix2f Multiply(const Matrix2f& lhs, const Matrix2f& rhs);
    static class Vector2f Multiply(const Matrix2f& lhs, const class Vector2f& rhs);
	
	// Computes the determinant (size of parralellogram of the matrix2)
	static float Determinant(const float a, const float d, const float b, const float c);
	static float Determinant(const Matrix2f& m);
	float Determinant();

    // Returns the diagonal of the matrix in vector form
    class Vector2f GetDiagonal() const;
    
    // Returns the sum of the diagonal
    float GetTrace() const;

    // Affine transformations
	void TranslateBy(const float x, const float y);
	void TranslateBy(const class Vector2f& t);
};

// Addition Operator
inline  Matrix2f operator+(const Matrix2f& lhs, const Matrix2f& rhs) { return Matrix2f::Add(lhs, rhs); }

// Subtraction Operator
inline  Matrix2f operator-(const Matrix2f& lhs, const Matrix2f& rhs) { return Matrix2f::Subtract(lhs, rhs); }

// Multiplication operators
inline  Matrix2f operator*(const Matrix2f& lhs, const float rhs) { return Matrix2f::Multiply(lhs, rhs); }
inline  Matrix2f operator*(const float lhs, const Matrix2f& rhs) { return Matrix2f::Multiply(rhs, lhs); }
inline  Matrix2f operator*(const Matrix2f& lhs, const Matrix2f& rhs) { return Matrix2f::Multiply(lhs, rhs); }
inline  Vector2f operator*(const Matrix2f& lhs, const class Vector2f& rhs) { return Matrix2f::Multiply(lhs, rhs); }
