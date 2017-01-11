#pragma once

#include "SandboxAPI.h"

class SANDBOX_API Line
{
public:
	class Vector3f origin; // Origin of line
	class Vector3f direction; // Direction of line

	// Constructors
	Line();
	Line(const class Vector2f& origin, const class Vector2f& direction);
	Line(const class Vector3f& origin, const class Vector3f& direction);

	// Destructor
	~Line();

	// Returns the point on line given the paremeter
	static Vector3f GetPoint(const Line& line, const float t);

	// Non-static version
	Vector3f GetPoint(const float t) const;

	// Returns if point lies on a line
	static bool IsPointOnLine(const Line& line, const class Vector3f& point);

	// Non-static version
	bool IsPointOnLine(const class Vector2f& point) const;
	bool IsPointOnLine(const class Vector3f& point) const;
    
    // Checks to see if the three points are collinear (in a straight line)
    static bool TestCollinear3Points(const class Vector3f& p0,const class Vector3f& p1,const class Vector3f& p2);
    
    // Checks to see if the four points are collinear (in a straight line)
    static bool TestCollinear4Points(const class Vector3f& p0,const class Vector3f& p1,const class Vector3f& p2,const class Vector3f& p3);
};
