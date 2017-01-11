#include "Math/MathLib.h"

// Constructors
Line::Line()
{

}
Line::Line(const Vector2f& origin, const Vector2f& direction)
{
	this->origin = Vector3f(origin.x,origin.y, 0.0f);
	this->direction = Vector3f(direction.x, direction.y, 0.0f);
}
Line::Line(const Vector3f& origin, const Vector3f& direction)
{
	this->origin = origin;
	this->direction = direction;
}

// Destructor
Line::~Line()
{

}

Vector3f Line::GetPoint(const Line& line, const float t)
{
	return line.origin + (t * line.direction);
}

Vector3f Line::GetPoint(const float t) const
{
	return Line::GetPoint(*this, t);
}


// Returns if point lies on a line
bool Line::IsPointOnLine(const Line& line, const Vector3f& point)
{
	Vector3f end = Line::GetPoint(line, 1.0f);

	Vector3f cross = Vector3f::CrossProduct(point - line.origin, end - line.origin);

	return cross.IsZero();	// If cross product is zero then point is on the line
}

// Non-static version
bool Line::IsPointOnLine(const Vector2f& point) const
{
	return Line::IsPointOnLine(*this, Vector3f(point.x, point.y, 0.0f));
}
bool Line::IsPointOnLine(const Vector3f& point) const
{
	return Line::IsPointOnLine(*this, point);
}

bool Line::TestCollinear3Points(const Vector3f& p0,const Vector3f& p1,const Vector3f& p2)
{
    Vector3f v0 = p1 - p0;
    Vector3f v1 = p2 - p0;
    
    return v0.CrossProduct(v1).IsZero();
}

bool Line::TestCollinear4Points(const Vector3f& p0,const Vector3f& p1,const Vector3f& p2,const Vector3f& p3)
{
    Vector3f v0 = p1 - p0;
    Vector3f v1 = p2 - p0;
    Vector3f v2 = p3 - p0;
    
    return v0.CrossProduct(v1).IsZero() & v0.CrossProduct(v2).IsZero();
}