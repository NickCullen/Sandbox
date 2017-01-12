#include "Math/Mathf.h"

#include "Core/LuaState.h"
#include "Core/Reflection.h"


PONDER_TYPE(Mathf);


void Mathf::Initialize()
{
	ponder::Class::declare<Mathf>()
		//.property("Pi", &Mathf::Pi)
		//.property("Epsilon", &Mathf::Epsilon)
		.function("IsZero", &Mathf::IsZero)
		.function("CompareFloats", &Mathf::CompareFloats)
		.function("Abs", &Mathf::Abs)
		.function("Sqrt", &Mathf::Sqrt)
		.function("Sin", &Mathf::Sin)
		.function("Cos", &Mathf::Cos)
		.function("Tan", &Mathf::Tan)
		.function("Atan2", &Mathf::Atan2)
		;

	ponder::lua::expose<Mathf>(LuaState::L, "Mathf");
	
}