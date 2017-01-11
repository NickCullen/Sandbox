#include "Core/Engine.h"
#include "Core/LuaState.h"
#include "Math/MathLib.h"



bool Engine::Initialize()
{   
    if(!LuaState::Initialize())
        return false;

	Mathf::Initialize();
	Vector2f::Initialize();

    return true;
} 


void Engine::DoTests()
{

    /*glm::vec2 v2 = glm::vec2(33, 15);
    const ponder::Class& v2Class = ponder::classByObject(v2);
    ponder::UserObject o = v2Class.getUserObjectFromPointer(&v2);

    printf("Name = %s\n", v2Class.name().c_str());
    printf("Constructor count = %lu\n", v2Class.constructorCount());
    printf("X = %f Y = %f\n\n", o.get("x").to<float>(), o.get("y").to<float>());

    // Retrieve the metaclass (containing the member data)
    const ponder::Class& metaclass = ponder::classByName("glm::vec2");
    
    

    // Use the metaclass to construct a new vector
    ponder::runtime::ObjectFactory factory(metaclass);
    ponder::UserObject v = factory.create(10.0f, 10.0f);
    
    /// Set x
    v.set("x", 232);
    
    // get x
    ponder::Value val = v.get("x");
    printf("X was set to %f via reflection\n", val.to<float>());

    // Kill John (not really)
    factory.destroy(v);*/


    LuaState::DoFile("test.lua");

}