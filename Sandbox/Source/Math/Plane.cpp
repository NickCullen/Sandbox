#include "Math/MathLib.h"
#include <stdio.h>
Plane::Plane()
{

}
Plane::Plane(float a, float b, float c, float d)
{
	normal = Vector3f(a, b, c).Normalized();
	offset = d;
}
Plane::Plane(const Vector3f& normal, float offset)
{
	this->normal = normal.Normalized();
	this->offset = offset;
}
Plane::Plane(const Vector3f& position, const Vector3f& normal)
{
	this->normal = normal.Normalized();
	this->offset = -(this->normal.x*position.x + this->normal.y*position.y + this->normal.z*position.z);
}

// Destructor
Plane::~Plane()
{

}

Plane Plane::FromPoints(const Vector3f& p,const Vector3f& q,const Vector3f& r)
{
	Vector3f u = q - p;
	Vector3f v = r - p;
	
	Vector3f n = u.CrossProduct(v).Normalized();
	
	float d = -(n.x*p.x + n.y*p.y + n.z*p.z);

	return Plane(n,d);
}

bool Plane::IsPointOnPlane(const Plane& plane, const Vector3f& point)
{
	return Mathf::IsZero(plane.normal.x*point.x + plane.normal.y*point.y + plane.normal.z*point.z + plane.offset);
}

// Non-static version
bool Plane::IsPointOnPlane(const Vector3f& point) const
{
	return Plane::IsPointOnPlane(*this, point);
}

PlaneTestResult Plane::TestPoint(const Vector3f& point) const
{
    float result = normal.x*point.x + normal.y*point.y + normal.z*point.z + offset;
    
    if(Mathf::IsZero(result))
        return OnPlane;
    else if(result < 0.0f)
        return Inside;
    else
        return Outside;
}
bool Plane::TestCoplanar4Points(const Vector3f& p0,const Vector3f& p1,const Vector3f& p2,const Vector3f& p3)
{
    Vector3f v0 = p1 - p0;
    Vector3f v1 = p2 - p0;
    Vector3f v2 = p3 - p0;

    return Mathf::IsZero(v0.DotProduct(v1.CrossProduct(v2)));
    
}

PlaneTestResult Plane::PointInTriangle(const Vector3f& p0,const Vector3f& p1,const Vector3f& p2,const Vector3f& point)
{
    // Vectors of the triangle
    Vector3f v0 = p1 - p0;
    Vector3f v1 = p2 - p1;
    Vector3f v2 = p0 - p2;
    
    // normal of the triangle
    Vector3f n = v0.CrossProduct(v1);
    
    // Vectors from triangle points to test point
    Vector3f w0 = point - p0;
    Vector3f w1 = point - p1;
    Vector3f w2 = point - p2;
    
    // Test dot product if it is less than 0 then it is outside
    if (v0.CrossProduct(w0).DotProduct(n) < 0 ||
        v1.CrossProduct(w1).DotProduct(n) < 0 ||
        v2.CrossProduct(w2).DotProduct(n) < 0)
        return Outside;
    
    // If we reach here then we are iside the triangle
    return Inside;
}

Vector2f Plane::BarycentricCoordinates(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2, const Vector3f& point)
{
    if (Plane::PointInTriangle(p0, p1, p2, point) == Inside)
    {
        Vector3f u = p1 - p0;
        Vector3f v = p2 - p0;
        Vector3f w = point - p0;
        
        float a = 0.5f * u.CrossProduct(w).Length();
        float b = 0.5f * v.CrossProduct(w).Length();
        float c = 0.5f * u.CrossProduct(v).Length();
        
        return Vector2f(b/c,a/c);
    }
    
    return Vector2f::Zero();
}

Vector3f Plane::BarycentricCoordToPoint(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2, const float s, const float t)
{
    return p0 + (s * (p1 - p0)) + (t * (p2 - p0));
}

Vector3f Plane::BarycentricCoordToPoint(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2, const Vector2f& barCoord)
{
    return Plane::BarycentricCoordToPoint(p0, p1, p2, barCoord.x, barCoord.y);
}
