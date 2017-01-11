#ifndef MATHF
#define MATHF

#include "SandboxAPI.h"

// Macros
#define DEG2RAD(d) d * 0.0174532925199444f		// PI / 180 
#define RAD2DEG(r) r * 57.29577951307855f		// 180 / PI

class SANDBOX_API Mathf
{
public:
	static void Initialize();

public:
	static const float Pi;		// 3.141592653
	static const float Epsilon; // 1.0e-6f

	// Returns if float is zero
	static bool IsZero(float val);

	// Compares floats
	static bool CompareFloats(float float1, float float2);

	// Extracts sign from float
	static float Abs(float input);

	// Square root of val
	static float Sqrt(float val);

	// sin/cos/tan
	static float Sin(float val);
	static float Cos(float val);
	static float Tan(float val);

	// Arctan2
	static float Atan2(float y, float x);
};

#endif