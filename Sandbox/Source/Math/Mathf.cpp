#include "Math/MathLib.h"
#include <math.h>

const float Mathf::Pi = 3.141592653f;
const float Mathf::Epsilon = 1.0e-6f;


bool Mathf::IsZero(float val)
{
	return (fabsf(val) < Mathf::Epsilon);
}

bool Mathf::CompareFloats(float f1, float f2)
{
	return Mathf::IsZero(Mathf::Abs(f1 - f2));
}

float Mathf::Abs(float input)
{
	return fabsf(input);
}

float Mathf::Sqrt(float val)
{
	return sqrtf(val);
}

float Mathf::Sin(float val)
{
	return sinf(val);
}
float Mathf::Cos(float val)
{
	return cosf(val);
}
float Mathf::Tan(float val)
{
	return tanf(val);
}
float Mathf::Atan2(float y, float x)
{
	return atan2f(y, x);
}