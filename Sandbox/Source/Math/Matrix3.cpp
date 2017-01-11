#include "Math/MathLib.h"
#include <stdio.h>

// Our default is column major so column major will be
// linear in memory. Row major needs abit of tweeking
#ifdef ROWMAJOR
/*
 | 0 1 2 |
 | 3 4 5 |
 | 6 7 8 |
 
 {0, 3, 6, 1, 4, 7, 2, 5, 8}
 */
#define E0 0
#define E1 3
#define E2 6
#define E3 1
#define E4 4
#define E5 7
#define E6 2
#define E7 5
#define E8 8
#else
/*
 | 0 3 6 |
 | 1 4 7 |
 | 2 5 8 |
 
 {0, 1, 2, 3, 4, 5, 6, 7, 8}
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
#endif

Matrix3f::Matrix3f()
{
    
}

Matrix3f::Matrix3f(const Vector3f&x, const Vector3f&y, const Vector3f&z)
{
    m[E0] = x.x; m[E3] = y.x; m[E6] = z.x;
    m[E1] = x.y; m[E4] = y.y; m[E7] = z.y;
    m[E2] = x.z; m[E5] = y.z; m[E8] = z.z;
}

Matrix3f::Matrix3f(const Quaternion& q)
{
	FromQuaternion(q);
}

Matrix3f::~Matrix3f()
{
    
}

void Matrix3f::Print() const
{
    printf("| %.3f %.3f %.3f |\n| %.3f %.3f %.3f |\n| %.3f %.3f %.3f |", m[E0], m[E3], m[E6],
                                                                         m[E1], m[E4], m[E7],
                                                                         m[E2], m[E5], m[E8]);
}

Matrix3f Matrix3f::Identity()
{
    Matrix3f ret;
    
    ret.m[E0] = 1.0f; ret.m[E3] = 0.0f; ret.m[E6] = 0.0f;
    ret.m[E1] = 0.0f; ret.m[E4] = 1.0f; ret.m[E7] = 0.0f;
    ret.m[E2] = 0.0f; ret.m[E5] = 0.0f; ret.m[E8] = 1.0f;
    
    return ret;
}

Matrix3f Matrix3f::Translation(const float x, const float y, const float z)
{
	Matrix3f ret;

	ret.m[E0] = 1.0f; ret.m[E3] = 0.0f; ret.m[E6] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E4] = 1.0f; ret.m[E7] = 0.0f;
	ret.m[E2] = x;	  ret.m[E5] = y;	ret.m[E8] = z;

	return ret;
}

Matrix3f Matrix3f::RotationX(float d)
{
	Matrix3f ret;

	d = DEG2RAD(d);

	ret.m[E0] = 1.0f; ret.m[E3] = 0.0f;				ret.m[E6] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E4] = Mathf::Cos(d);	ret.m[E7] = Mathf::Sin(d);
	ret.m[E2] = 0.0f; ret.m[E5] = -Mathf::Sin(d);	ret.m[E8] = Mathf::Cos(d);

	return ret;
}

Matrix3f Matrix3f::RotationY(float d)
{
	Matrix3f ret;

	d = DEG2RAD(d);

	ret.m[E0] = Mathf::Cos(d);  ret.m[E3] = 0.0f; ret.m[E6] = -Mathf::Sin(d);
	ret.m[E1] = 0.0f;			ret.m[E4] = 1.0f; ret.m[E7] = 0.0f;
	ret.m[E2] = Mathf::Sin(d);  ret.m[E5] = 0.0f; ret.m[E8] = Mathf::Cos(d);

	return ret;
}

Matrix3f Matrix3f::RotationZ(float d)
{
	Matrix3f ret;

	d = DEG2RAD(d);

	ret.m[E0] = Mathf::Cos(d);	ret.m[E3] = Mathf::Sin(d);  ret.m[E6] = 0.0f;
	ret.m[E1] = -Mathf::Sin(d); ret.m[E4] = Mathf::Cos(d);  ret.m[E7] = 0.0f;
	ret.m[E2] = 0.0f;			ret.m[E5] = 0.0f;			ret.m[E8] = 1.0f;

	return ret;
}

Matrix3f Matrix3f::Rotation(const Quaternion& q)
{
	Matrix3f m;
	return m.FromQuaternion(q);
}

Matrix3f& Matrix3f::FromQuaternion(const Quaternion& q)
{
	float s, xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;

	// if Q is normalized, s = 2.0f
	s = 2.0f / (q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);

	xs = s*q.x;		ys = s*q.y;		zs = s*q.z;
	wx = q.w*xs;	wy = q.w*ys;	wz = q.w*zs;
	xx = q.x*xs;	xy = q.x*ys;	xz = q.x*zs;
	yy = q.y*ys;	yz = q.y*zs;	zz = q.z*zs;

	m[E0] = 1.0f - (yy + zz);
	m[E3] = xy - wz;
	m[E6] = xz + wy;

	m[E1] = xy + wz;
	m[E4] = 1.0f - (xx + zz);
	m[E7] = yz - wx;

	m[E2] = xz - wy;
	m[E5] = yz + wx;
	m[E8] = 1.0f - (xx + yy);

	return *this;
}

Matrix3f Matrix3f::Scale(const float x, const float y, const float z)
{
	Matrix3f ret;

	ret.m[E0] = x;	  ret.m[E3] = 0.0f; ret.m[E6] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E4] = y;	ret.m[E7] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E5] = 0.0f; ret.m[E8] = z;

	return ret;
}

Matrix3f Matrix3f::Scale(const float s)
{
	Matrix3f ret;

	ret.m[E0] = s;	  ret.m[E3] = 0.0f; ret.m[E6] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E4] = s;	ret.m[E7] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E5] = 0.0f; ret.m[E8] = s;

	return ret;
}

Matrix3f Matrix3f::ShearX(const float y, const float z)
{
	Matrix3f ret;

	ret.m[E0] = 1.0f; ret.m[E3] = y;	ret.m[E6] = z;
	ret.m[E1] = 0.0f; ret.m[E4] = 1.0f; ret.m[E7] = 0.0f;
	ret.m[E2] = 0.0f; ret.m[E5] = 0.0f; ret.m[E8] = 1.0f;

	return ret;
}

Matrix3f Matrix3f::ShearY(const float x, const float z)
{
	Matrix3f ret;

	ret.m[E0] = 1.0f; ret.m[E3] = 0.0f; ret.m[E6] = 0.0f;
	ret.m[E1] = x;	  ret.m[E4] = 1.0f; ret.m[E7] = z;
	ret.m[E2] = 0.0f; ret.m[E5] = 0.0f; ret.m[E8] = 1.0f;

	return ret;
}

Matrix3f Matrix3f::ShearZ(const float x, const float y)
{
	Matrix3f ret;

	ret.m[E0] = 1.0f; ret.m[E3] = 0.0f; ret.m[E6] = 0.0f;
	ret.m[E1] = 0.0f; ret.m[E4] = 1.0f; ret.m[E7] = 0.0f;
	ret.m[E2] = x;	  ret.m[E5] = y;	ret.m[E8] = 1.0f;

	return ret;
}

Matrix3f Matrix3f::Add(const Matrix3f& l, const Matrix3f& r)
{
    Matrix3f m;
    
    m.m[E0] = l.m[E0] + r.m[E0];
    m.m[E1] = l.m[E1] + r.m[E1];
    m.m[E2] = l.m[E2] + r.m[E2];
    m.m[E3] = l.m[E3] + r.m[E3];
    m.m[E4] = l.m[E4] + r.m[E4];
    m.m[E5] = l.m[E5] + r.m[E5];
    m.m[E6] = l.m[E6] + r.m[E6];
    m.m[E7] = l.m[E7] + r.m[E7];
    m.m[E8] = l.m[E8] + r.m[E8];
    
    return m;
}

Matrix3f Matrix3f::Subtract(const Matrix3f& l, const Matrix3f& r)
{
    Matrix3f m;
    
    m.m[E0] = l.m[E0] - r.m[E0];
    m.m[E1] = l.m[E1] - r.m[E1];
    m.m[E2] = l.m[E2] - r.m[E2];
    m.m[E3] = l.m[E3] - r.m[E3];
    m.m[E4] = l.m[E4] - r.m[E4];
    m.m[E5] = l.m[E5] - r.m[E5];
    m.m[E6] = l.m[E6] - r.m[E6];
    m.m[E7] = l.m[E7] - r.m[E7];
    m.m[E8] = l.m[E8] - r.m[E8];
    
    return m;
}

Matrix3f Matrix3f::Multiply(const Matrix3f& l, const float r)
{
    Matrix3f m;
    
    m.m[E0] = l.m[E0] * r;
    m.m[E1] = l.m[E1] * r;
    m.m[E2] = l.m[E2] * r;
    m.m[E3] = l.m[E3] * r;
    m.m[E4] = l.m[E4] * r;
    m.m[E5] = l.m[E5] * r;
    m.m[E6] = l.m[E6] * r;
    m.m[E7] = l.m[E7] * r;
    m.m[E8] = l.m[E8] * r;
    
    return m;
}

// Matrix Row * Vector Column
Vector3f Matrix3f::Multiply(const Matrix3f& l, const Vector3f& r)
{
    Vector3f ret;
    
    ret.x = l.m[E0]*r.x + l.m[E3]*r.y + l.m[E6]*r.z;
    ret.y = l.m[E1]*r.x + l.m[E4]*r.y + l.m[E7]*r.z;
    ret.z = l.m[E2]*r.x + l.m[E5]*r.y + l.m[E8]*r.z;
    
    return ret;
}
// Matrix Row * Matrix Column
Matrix3f Matrix3f::Multiply(const Matrix3f& l, const Matrix3f& r)
{
    Matrix3f ret;
    
    ret.m[E0] = l.m[E0]*r.m[E0] + l.m[E3]*r.m[E1] + l.m[E6]*r.m[E2];
    ret.m[E1] = l.m[E1]*r.m[E0] + l.m[E4]*r.m[E1] + l.m[E7]*r.m[E2];
    ret.m[E2] = l.m[E2]*r.m[E0] + l.m[E5]*r.m[E1] + l.m[E8]*r.m[E2];
                                              
    ret.m[E3] = l.m[E0]*r.m[E3] + l.m[E3]*r.m[E4] + l.m[E6]*r.m[E5];
    ret.m[E4] = l.m[E1]*r.m[E3] + l.m[E4]*r.m[E4] + l.m[E7]*r.m[E5];
    ret.m[E5] = l.m[E2]*r.m[E3] + l.m[E5]*r.m[E4] + l.m[E8]*r.m[E5];
    
    ret.m[E6] = l.m[E0]*r.m[E6] + l.m[E3]*r.m[E7] + l.m[E6]*r.m[E8];
    ret.m[E7] = l.m[E1]*r.m[E6] + l.m[E4]*r.m[E7] + l.m[E7]*r.m[E8];
    ret.m[E8] = l.m[E2]*r.m[E6] + l.m[E5]*r.m[E7] + l.m[E8]*r.m[E8];
    
    return ret;
}

float& Matrix3f::operator()(unsigned int row, unsigned int col)
{
#ifdef ROWMAJOR
    return m[row * 3 + col];
#else
    return m[col * 3 + row];
#endif
}

Matrix3f& Matrix3f::operator=(const Matrix3f& rhs)
{
    m[0] = rhs.m[0]; m[3] = rhs.m[3]; m[6] = rhs.m[6];
    m[1] = rhs.m[1]; m[4] = rhs.m[4]; m[7] = rhs.m[7];
    m[2] = rhs.m[2]; m[5] = rhs.m[5]; m[8] = rhs.m[8];
    
    return *this;
}

float Matrix3f::Determinant(const Matrix3f& m)
{
	float d1 = m.m[E0] * Matrix2f::Determinant(m.m[E4], m.m[E8], m.m[E5], m.m[E7]);	// 4*8-5*7
	float d2 = (-m.m[E1]) * Matrix2f::Determinant(m.m[E3], m.m[E8], m.m[E5], m.m[E6]);	// 3*8-5*6
	float d3 = m.m[E2] * Matrix2f::Determinant(m.m[E3], m.m[E7], m.m[E4], m.m[E6]);	// 3*7-4*6

	return d1 + d2 + d3;
}

float Matrix3f::Determinant()
{
	return Matrix3f::Determinant(*this);
}

Vector3f Matrix3f::GetDiagonal() const
{
    return Vector3f(m[E0], m[E4], m[E8]);
}

float Matrix3f::GetTrace() const
{
    return m[E0] + m[E4] + m[E8];
}

void Matrix3f::TranslateBy(const float x, const float y, const float z)
{
	m[E2] += x;
	m[E5] += y;
	m[E8] += z;
}

void Matrix3f::TranslateBy(const Vector3f& t)
{
	TranslateBy(t.x, t.y, t.z);
}