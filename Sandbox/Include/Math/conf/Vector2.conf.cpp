#include "Math/Vector2.h"

#include "Core/LuaState.h"
#include "Core/Reflection.h"


PONDER_TYPE(Vector2f);


void Vector2f::Initialize()
{
	ponder::Class::declare<Vector2f>("Vector2f")
		.constructor()
		.constructor<float, float>()
		.constructor<const Vector2f&>()
		.property("x", &Vector2f::x)
		.property("y", &Vector2f::y)
		.function("Up", &Vector2f::Up)
		.function("Right", &Vector2f::Right)
		.function("Zero", &Vector2f::Zero)
		.function("IsZero", &Vector2f::IsZero)
		.function("Add", &Vector2f::Add)
		.function("Subtract", &Vector2f::Subtract)
		.function("Multiply", &Vector2f::Multiply)
		.function("Divide", &Vector2f::Divide)
		.function("DotProduct", &Vector2f::DotProduct)
		.function("Length", &Vector2f::Length)
		.function("LengthSquared", &Vector2f::LengthSquared)
		.function("Normalize", &Vector2f::Normalize)
		.function("Normalized", &Vector2f::Normalized)
		.function("Distance", &Vector2f::Distance)
		.function("DistanceSquared", &Vector2f::DistanceSquared)
		.function("Perpendicular", &Vector2f::Perpendicular)
		.function("PolarToCartesian", &Vector2f::PolarToCartesian)
		.function("CartesianToPolar", &Vector2f::CartesianToPolar)
		;

	ponder::lua::expose<Vector2f>(LuaState::L, "Vector2f");
}