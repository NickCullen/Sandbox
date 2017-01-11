#include "Math/MathLib.h"
#include <stdio.h>

// Our default is column major so column major will be
// linear in memory. Row major needs abit of tweeking
#ifdef ROWMAJOR
/*
 | 0  1  2  3  |
 | 4  5  6  7  |
 | 8  9  10 11 |
 | 12 13 14 15 |
 
 {0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15}
 */
#define E0 0
#define E1 4
#define E2 8
#define E3 12
#define E4 1
#define E5 5
#define E6 9
#define E7 13
#define E8 2
#define E9 6
#define E10 10
#define E11 14
#define E12 3
#define E13 7
#define E14 11
#define E15 15
#else
/*
 | 0  4  8   12 |
 | 1  5  9   13 |
 | 2  6  10  14 |
 | 3  7  11  15 |
 
 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
 */
#define E0 0
#define E1 1
#define E2 2
#define E3 3
#define E4 4
#define E5 5
#define E6 6
#define E7 7
#define E8 8
#define E9 9
#define E10 10
#define E11 11
#define E12 12
#define E13 13
#define E14 14
#define E15 15
#endif

Matrix4f::Matrix4f()
{
    
}

Matrix4f::Matrix4f(const Vector4f& x,const Vector4f& y,const Vector4f& z)
{
    m[E0] = x.x; m[E4] = y.x; m[E8] = z.x;  m[E12] = 0.0f;
    m[E1] = x.y; m[E5] = y.y; m[E9] = z.y;  m[E13] = 0.0f;
    m[E2] = x.z; m[E6] = y.z; m[E10] = z.z; m[E14] = 0.0f;
    m[E3] = x.w; m[E7] = y.w; m[E11] = z.w; m[E15] = 1.0f;
}
Matrix4f::Matrix4f(const Vector4f& x,const Vector4f& y,const Vector4f& z, const Vector4f& w)
{
    m[E0] = x.x; m[E4] = y.x; m[E8] = z.x;  m[E12] = w.x;
    m[E1] = x.y; m[E5] = y.y; m[E9] = z.y;  m[E13] = w.y;
    m[E2] = x.z; m[E6] = y.z; m[E10] = z.z; m[E14] = w.z;
    m[E3] = x.w; m[E7] = y.w; m[E11] = z.w; m[E15] = w.w;
}

Matrix4f::Matrix4f(const Quaternion& q)
{
	FromQuaternion(q);
}


Matrix4f::~Matrix4f()
{
    
}

void Matrix4f::Print() const
{
    printf("| %.3f %.3f %.3f %.3f|\n| %.3f %.3f %.3f %.3f|\n| %.3f %.3f %.3f %.3f|\n| %.3f %.3f %.3f %.3f|",
           m[E0], m[E4], m[E8], m[E12],
           m[E1], m[E5], m[E9], m[E13],
           m[E2], m[E6], m[E10], m[E14],
           m[E3], m[E7], m[E11], m[E15]);
}

Matrix4f Matrix4f::Identity()
{
    Matrix4f ret;
    
    ret.m[E0] = 1.0f; ret.m[E4] = 0.0f; ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
    ret.m[E1] = 0.0f; ret.m[E5] = 1.0f; ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
    ret.m[E2] = 0.0f; ret.m[E6] = 0.0f; ret.m[E10] = 1.0f; ret.m[E14] = 0.0f;
    ret.m[E3] = 0.0f; ret.m[E7] = 0.0f; ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;
    
    return ret;
}

Matrix4f Matrix4f::Translation(const float x, const float y, const float z)
{
	Matrix4f ret;

	ret.m[E0] = 1.0f; ret.m[E4] = 0.0f; ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E5] = 1.0f; ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E6] = 0.0f; ret.m[E10] = 1.0f; ret.m[E14] = 0.0f;
	ret.m[E3] = x;    ret.m[E7] = y;    ret.m[E11] = z;    ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::RotationX(float d)
{
	Matrix4f ret;

	d = DEG2RAD(d);

	ret.m[E0] = 1.0f; ret.m[E4] = 0.0f;			  ret.m[E8] = 0.0f;			  ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E5] = Mathf::Cos(d);  ret.m[E9] = Mathf::Sin(d);  ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E6] = -Mathf::Sin(d); ret.m[E10] = Mathf::Cos(d); ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f; ret.m[E7] = 0.0f;			  ret.m[E11] = 0.0f;		  ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::RotationY(float d)
{
	Matrix4f ret;

	d = DEG2RAD(d);

	ret.m[E0] = Mathf::Cos(d);	ret.m[E4] = 0.0f; ret.m[E8] = -Mathf::Sin(d);	ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f;			ret.m[E5] = 1.0f; ret.m[E9] = 0.0f;				ret.m[E13] = 0.0f;
	ret.m[E2] = Mathf::Sin(d);	ret.m[E6] = 0.0f; ret.m[E10] = Mathf::Cos(d);	ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f;			ret.m[E7] = 0.0f; ret.m[E11] = 0.0f;			ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::RotationZ(float d)
{
	Matrix4f ret;

	d = DEG2RAD(d);

	ret.m[E0] = Mathf::Cos(d);  ret.m[E4] = Mathf::Sin(d);	ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
	ret.m[E1] = -Mathf::Sin(d); ret.m[E5] = Mathf::Cos(d);	ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f;			ret.m[E6] = 0.0f;			ret.m[E10] = 1.0f; ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f;			ret.m[E7] = 0.0f;			ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::Rotation(const Quaternion& q)
{
	Matrix4f ret;
	return ret.FromQuaternion(q);
}

Matrix4f Matrix4f::Scale(const float x, const float y, const float z)
{
	Matrix4f ret;

	ret.m[E0] = x;	  ret.m[E4] = 0.0f; ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E5] = y;	ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E6] = 0.0f; ret.m[E10] = z;	   ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f; ret.m[E7] = 0.0f; ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::Scale(const float s)
{
	Matrix4f ret;

	ret.m[E0] = s;	  ret.m[E4] = 0.0f; ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E5] = s;	ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E6] = 0.0f; ret.m[E10] = s;	   ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f; ret.m[E7] = 0.0f; ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::ShearX(const float y, const float z)
{
	Matrix4f ret;

	ret.m[E0] = 1.0f; ret.m[E4] = y;	ret.m[E8] = z;	   ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E5] = 1.0f; ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E6] = 0.0f; ret.m[E10] = 1.0f; ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f; ret.m[E7] = 0.0f; ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::ShearY(const float x, const float z)
{
	Matrix4f ret;

	ret.m[E0] = 1.0f; ret.m[E4] = 0.0f; ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
	ret.m[E1] = x;	  ret.m[E5] = 1.0f; ret.m[E9] = z;	   ret.m[E13] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E6] = 0.0f; ret.m[E10] = 1.0f; ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f; ret.m[E7] = 0.0f; ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::ShearZ(const float x, const float y)
{
	Matrix4f ret;

	ret.m[E0] = 1.0f; ret.m[E4] = 0.0f; ret.m[E8] = 0.0f;  ret.m[E12] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E5] = 1.0f; ret.m[E9] = 0.0f;  ret.m[E13] = 0.0f;
	ret.m[E2] = x;	  ret.m[E6] = y;	ret.m[E10] = 1.0f; ret.m[E14] = 0.0f;
	ret.m[E3] = 0.0f; ret.m[E7] = 0.0f; ret.m[E11] = 0.0f; ret.m[E15] = 1.0f;

	return ret;
}

Matrix4f Matrix4f::Add(const Matrix4f& l, const Matrix4f& r)
{
    Matrix4f m;
    
    m.m[E0] = l.m[E0] + r.m[E0];
    m.m[E1] = l.m[E1] + r.m[E1];
    m.m[E2] = l.m[E2] + r.m[E2];
    m.m[E3] = l.m[E3] + r.m[E3];
    m.m[E4] = l.m[E4] + r.m[E4];
    m.m[E5] = l.m[E5] + r.m[E5];
    m.m[E6] = l.m[E6] + r.m[E6];
    m.m[E7] = l.m[E7] + r.m[E7];
    m.m[E8] = l.m[E8] + r.m[E8];
    m.m[E9] = l.m[E9] + r.m[E9];
    m.m[E10] = l.m[E10] + r.m[E10];
    m.m[E11] = l.m[E11] + r.m[E11];
    m.m[E12] = l.m[E12] + r.m[E12];
    m.m[E13] = l.m[E13] + r.m[E13];
    m.m[E14] = l.m[E14] + r.m[E14];
    m.m[E15] = l.m[E15] + r.m[E15];
    
    return m;
}

Matrix4f Matrix4f::Subtract(const Matrix4f& l, const Matrix4f& r)
{
    Matrix4f m;
    
    m.m[E0] = l.m[E0] - r.m[E0];
    m.m[E1] = l.m[E1] - r.m[E1];
    m.m[E2] = l.m[E2] - r.m[E2];
    m.m[E3] = l.m[E3] - r.m[E3];
    m.m[E4] = l.m[E4] - r.m[E4];
    m.m[E5] = l.m[E5] - r.m[E5];
    m.m[E6] = l.m[E6] - r.m[E6];
    m.m[E7] = l.m[E7] - r.m[E7];
    m.m[E8] = l.m[E8] - r.m[E8];
    m.m[E9] = l.m[E9] - r.m[E9];
    m.m[E10] = l.m[E10] - r.m[E10];
    m.m[E11] = l.m[E11] - r.m[E11];
    m.m[E12] = l.m[E12] - r.m[E12];
    m.m[E13] = l.m[E13] - r.m[E13];
    m.m[E14] = l.m[E14] - r.m[E14];
    m.m[E15] = l.m[E15] - r.m[E15];
    
    return m;
}

Matrix4f Matrix4f::Multiply(const Matrix4f& l, const float r)
{
    Matrix4f m;
    
    m.m[E0] = l.m[E0] * r;
    m.m[E1] = l.m[E1] * r;
    m.m[E2] = l.m[E2] * r;
    m.m[E3] = l.m[E3] * r;
    m.m[E4] = l.m[E4] * r;
    m.m[E5] = l.m[E5] * r;
    m.m[E6] = l.m[E6] * r;
    m.m[E7] = l.m[E7] * r;
    m.m[E8] = l.m[E8] * r;
    m.m[E9] = l.m[E9] * r;
    m.m[E10] = l.m[E10] * r;
    m.m[E11] = l.m[E11] * r;
    m.m[E12] = l.m[E12] * r;
    m.m[E13] = l.m[E13] * r;
    m.m[E14] = l.m[E14] * r;
    m.m[E15] = l.m[E15] * r;
    
    return m;
}

// Matrix Row * Vector Column
Vector4f Matrix4f::Multiply(const Matrix4f& l, const Vector4f& r)
{
    Vector4f ret;
    
    ret.x = l.m[E0]*r.x + l.m[E4]*r.y + l.m[E8]*r.z + l.m[E12]*r.w;
    ret.y = l.m[E1]*r.x + l.m[E5]*r.y + l.m[E9]*r.z + l.m[E13]*r.w;
    ret.z = l.m[E2]*r.x + l.m[E6]*r.y + l.m[E10]*r.z + l.m[E14]*r.w;
    ret.w = l.m[E3]*r.x + l.m[E7]*r.y + l.m[E11]*r.z + l.m[E15]*r.w;
    
    return ret;
}
// Matrix Row * Matrix Column
Matrix4f Matrix4f::Multiply(const Matrix4f& l, const Matrix4f& r)
{
    Matrix4f ret;
    
    ret.m[E0] = l.m[E0]*r.m[E0] + l.m[E4]*r.m[E1] + l.m[E8]*r.m[E2] + l.m[E12]*r.m[E3];
    ret.m[E1] = l.m[E1]*r.m[E0] + l.m[E5]*r.m[E1] + l.m[E9]*r.m[E2] + l.m[E13]*r.m[E3];
    ret.m[E2] = l.m[E2]*r.m[E0] + l.m[E6]*r.m[E1] + l.m[E10]*r.m[E2] + l.m[E14]*r.m[E3];
    ret.m[E3] = l.m[E3]*r.m[E0] + l.m[E7]*r.m[E1] + l.m[E11]*r.m[E2] + l.m[E15]*r.m[E3];
    
    ret.m[E4] = l.m[E0]*r.m[E4] + l.m[E4]*r.m[E5] + l.m[E8]*r.m[E6] + l.m[E12]*r.m[E7];
    ret.m[E5] = l.m[E1]*r.m[E4] + l.m[E5]*r.m[E5] + l.m[E9]*r.m[E6] + l.m[E13]*r.m[E7];
    ret.m[E6] = l.m[E2]*r.m[E4] + l.m[E6]*r.m[E5] + l.m[E10]*r.m[E6] + l.m[E14]*r.m[E7];
    ret.m[E7] = l.m[E3]*r.m[E4] + l.m[E7]*r.m[E5] + l.m[E11]*r.m[E6] + l.m[E15]*r.m[E7];
    
    ret.m[E8] = l.m[E0]*r.m[E8] + l.m[E4]*r.m[E9] + l.m[E8]*r.m[E10] + l.m[E12]*r.m[E11];
    ret.m[E9] = l.m[E1]*r.m[E8] + l.m[E5]*r.m[E9] + l.m[E9]*r.m[E10] + l.m[E13]*r.m[E11];
    ret.m[E10] = l.m[E2]*r.m[E8] + l.m[E6]*r.m[E9] + l.m[E10]*r.m[E10] + l.m[E14]*r.m[E11];
    ret.m[E11] = l.m[E3]*r.m[E8] + l.m[E7]*r.m[E9] + l.m[E11]*r.m[E10] + l.m[E15]*r.m[E11];
    
    ret.m[E12] = l.m[E0]*r.m[E12] + l.m[E4]*r.m[E13] + l.m[E8]*r.m[E14] + l.m[E12]*r.m[E15];
    ret.m[E13] = l.m[E1]*r.m[E12] + l.m[E5]*r.m[E13] + l.m[E9]*r.m[E14] + l.m[E13]*r.m[E15];
    ret.m[E14] = l.m[E2]*r.m[E12] + l.m[E6]*r.m[E13] + l.m[E10]*r.m[E14] + l.m[E14]*r.m[E15];
    ret.m[E15] = l.m[E3]*r.m[E12] + l.m[E7]*r.m[E13] + l.m[E11]*r.m[E14] + l.m[E15]*r.m[E15];
    
    return ret;
}

float& Matrix4f::operator()(unsigned int row, unsigned int col)
{
#ifdef ROWMAJOR
    return m[row * 4 + col];
#else
    return m[col * 4 + row];
#endif
}


Matrix4f& Matrix4f::operator=(const Matrix4f& rhs)
{
    m[0] = rhs.m[0]; m[4] = rhs.m[4]; m[8] = rhs.m[8]; m[12] = rhs.m[12];
    m[1] = rhs.m[1]; m[5] = rhs.m[5]; m[9] = rhs.m[9]; m[13] = rhs.m[13];
    m[2] = rhs.m[2]; m[6] = rhs.m[6]; m[10] = rhs.m[10]; m[14] = rhs.m[14];
    m[3] = rhs.m[3]; m[7] = rhs.m[7]; m[11] = rhs.m[11]; m[15] = rhs.m[15];
    
    return *this;
}

float Matrix4f::Determinant(const Matrix4f& m)
{
	float d1 = m.m[E0] *	Matrix2f::Determinant(m.m[E5], m.m[E10], m.m[E6], m.m[E9]);// 0 -> 5*10-6*9
	float d2 = (-m.m[E1]) * Matrix2f::Determinant(m.m[E4], m.m[E10], m.m[E6], m.m[E8]);// 1 -> 4*10-6*8
	float d3 = m.m[E2] *	Matrix2f::Determinant(m.m[E4], m.m[E9], m.m[E5], m.m[E8]);// 2 -> 4*9-5*8

	return d1 + d2 + d3;
}

float Matrix4f::Determinant()
{
	return Matrix4f::Determinant(*this);
}

Vector4f Matrix4f::GetDiagonal() const
{
    return Vector4f(m[E0], m[E5], m[E10], m[E15]);
}

float Matrix4f::GetTrace() const
{
    return m[E0] + m[E5] + m[E10] + m[E15];
}

void Matrix4f::TranslateBy(const float x, const float y, const float z)
{
	m[E3] += x;
	m[E7] += y;
	m[E11] += z;
}

void Matrix4f::TranslateBy(const Vector3f& t)
{
	TranslateBy(t.x, t.y, t.z);
}

void Matrix4f::TranslateBy(const Vector4f& t)
{
	TranslateBy(t.x, t.y, t.z);
}

Matrix4f& Matrix4f::FromQuaternion(const Quaternion& q)
{
	float s, xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;

	// if Q is normalized, s = 2.0f
	s = 2.0f / (q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);

	xs = s*q.x;		ys = s*q.y;		zs = s*q.z;
	wx = q.w*xs;	wy = q.w*ys;	wz = q.w*zs;
	xx = q.x*xs;	xy = q.x*ys;	xz = q.x*zs;
	yy = q.y*ys;	yz = q.y*zs;	zz = q.z*zs;

	m[E0] = 1.0f - (yy + zz);
	m[E4] = xy - wz;
	m[E8] = xz + wy;

	m[E1] = xy + wz;
	m[E5] = 1.0f - (xx + zz);
	m[E9] = yz - wx;

	m[E2] = xz - wy;
	m[E6] = yz + wx;
	m[E10] = 1.0f - (xx + yy);

	// Default the rest
	m[E3] = m[E7] = m[E11] = m[E12] = m[E13] = m[E14] = 0.0f;
	m[E15] = 1.0f;

	return *this;
}