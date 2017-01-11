#include "Math/MathLib.h"
#include <stdio.h>

// Our default is column major so column major will be
// linear in memory. Row major needs abit of tweeking
#ifdef ROWMAJOR
/*
 | 0 1 |
 | 2 3 |
 
 {0, 2, 1, 3}
 */
#define E0 0
#define E1 2
#define E2 1
#define E3 3
#else
/*
 | 0 2 |
 | 1 3 |
 
 {0, 1, 2, 3}
 */
#define E0 0
#define E1 1
#define E2 2
#define E3 3
#endif


Matrix2f::Matrix2f()
{
    
}

Matrix2f::Matrix2f(const Vector2f& x, const Vector2f& y)
{
    m[E0] = x.x;
    m[E1] = x.y;
    m[E2] = y.x;
    m[E3] = y.y;
}

Matrix2f::~Matrix2f()
{
    
}

void Matrix2f::Print() const
{
    printf("| %.3f %.3f |\n| %.3f %.3f |", m[E0], m[E2], m[E1], m[E3]);
}

Matrix2f Matrix2f::Identity()
{
    Matrix2f ret;
    
    ret.m[E0] = 1.0f; ret.m[E2] = 0.0f;
    ret.m[E1] = 0.0f; ret.m[E3] = 1.0f;
    
    return ret;
}

Matrix2f Matrix2f::Translation(const float x, const float y)
{
	Matrix2f m;

	m.m[E0] = 1.0f;
	m.m[E1] = x;
	m.m[E2] = 0.0f;
	m.m[E3] = y;

	return m;
}

Matrix2f Matrix2f::Rotation(float d)
{
	Matrix2f m;

	d = DEG2RAD(d);

	m.m[E0] = Mathf::Cos(d);  m.m[E2] = Mathf::Sin(d);
	m.m[E1] = -Mathf::Sin(d); m.m[E3] = Mathf::Cos(d);
	
	return m;

}

Matrix2f Matrix2f::Scale(const float x, const float y)
{
	Matrix2f ret;

	ret.m[E0] = x;	  ret.m[E2] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E3] = y;

	return ret;
}

Matrix2f Matrix2f::Scale(const float s)
{
	Matrix2f ret;

	ret.m[E0] = s;	  ret.m[E2] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E3] = s;

	return ret;
}

Matrix2f Matrix2f::ShearX(const float y)
{
	Matrix2f ret;

	ret.m[E0] = 1.0f; ret.m[E2] = y;
	ret.m[E1] = 0.0f; ret.m[E3] = 1.0f;

	return ret;
}

Matrix2f Matrix2f::ShearY(const float x)
{
	Matrix2f ret;

	ret.m[E0] = 1.0f; ret.m[E2] = 0.0f;
	ret.m[E1] = x;	  ret.m[E3] = 1.0f;

	return ret;
}

Matrix2f Matrix2f::Add(const Matrix2f& l, const Matrix2f& r)
{
    Matrix2f m;
    
    m.m[E0] = l.m[E0] + r.m[E0];
    m.m[E1] = l.m[E1] + r.m[E1];
    m.m[E2] = l.m[E2] + r.m[E2];
    m.m[E3] = l.m[E3] + r.m[E3];
    
    return m;
}

Matrix2f Matrix2f::Subtract(const Matrix2f& l, const Matrix2f& r)
{
    Matrix2f m;
    
    m.m[E0] = l.m[E0] - r.m[E0];
    m.m[E1] = l.m[E1] - r.m[E1];
    m.m[E2] = l.m[E2] - r.m[E2];
    m.m[E3] = l.m[E3] - r.m[E3];
    
    return m;
}

Matrix2f Matrix2f::Multiply(const Matrix2f &l, const float r)
{
    Matrix2f m;
    
    m.m[E0] = l.m[E0] * r;
    m.m[E1] = l.m[E1] * r;
    m.m[E2] = l.m[E2] * r;
    m.m[E3] = l.m[E3] * r;
    
    return m;
}

// Matrix Row * Vector Column
Vector2f Matrix2f::Multiply(const Matrix2f& l, const Vector2f& r)
{
    Vector2f ret;
    
    ret.x = l.m[E0]*r.x + l.m[E2]*r.y;
    ret.y = l.m[E1]*r.x + l.m[E3]*r.y;
    
    return ret;
}
// Matrix Row * Matrix Column
Matrix2f Matrix2f::Multiply(const Matrix2f& l, const Matrix2f& r)
{
    Matrix2f ret;
    
    ret.m[E0] = l.m[E0]*r.m[E0] + l.m[E2]*r.m[E1];
    ret.m[E1] = l.m[E1]*r.m[E0] + l.m[E3]*r.m[E1];
    
    ret.m[E2] = l.m[E0]*r.m[E2] + l.m[E2]*r.m[E3];
    ret.m[E3] = l.m[E1]*r.m[E2] + l.m[E3]*r.m[E3];
    
    return ret;
}

// Access operator
float& Matrix2f::operator()(unsigned int row, unsigned int col)
{
#ifdef ROWMAJOR
    return m[row * 2 + col];
#else
    return m[col * 2 + row];
#endif
}

Matrix2f& Matrix2f::operator=(const Matrix2f& rhs)
{
    m[0] = rhs.m[0]; m[2] = rhs.m[2];
    m[1] = rhs.m[1]; m[3] = rhs.m[3];
    return *this;
}

Vector2f Matrix2f::GetDiagonal() const
{
    return Vector2f(m[E0], m[E3]);
}

float Matrix2f::GetTrace() const
{
    return m[E0] + m[E3];
}

float Matrix2f::Determinant(const float a, const float d, const float b, const float c)
{
	return (a*d) - (b*c);
}

float Matrix2f::Determinant(const Matrix2f& m)
{
	return (m.m[E0] * m.m[E3]) - (m.m[E1] * m.m[E2]);
}

float Matrix2f::Determinant()
{
	return Matrix2f::Determinant(*this);
}

// Affine transformations
void Matrix2f::TranslateBy(const float x, const float y)
{
	m[E1] += x;
	m[E3] += y;
}

void Matrix2f::TranslateBy(const Vector2f& t)
{
	TranslateBy(t.x, t.y);
}