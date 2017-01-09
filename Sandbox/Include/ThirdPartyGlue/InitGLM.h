// Do not include this file directly - include via "Sandbox.h"

namespace glm
{
    // Vec2 serialization
    template<class Archive>
    void serialize(Archive & archive, glm::vec2 & v)
    {
        archive ( 
            cereal::make_nvp("x",v.x), 
            cereal::make_nvp("y",v.y)
        );
    }

    // Vec3 serialization
    template<class Archive>
    void serialize(Archive & archive, glm::vec3 & v)
    {
        archive ( 
            cereal::make_nvp("x",v.x), 
            cereal::make_nvp("y",v.y), 
            cereal::make_nvp("z",v.z) 
        );
    }

    // Vec4 serialization
    template<class Archive>
    void serialize(Archive & archive, glm::vec4 & v)
    {
        archive ( 
            cereal::make_nvp("x",v.x), 
            cereal::make_nvp("y",v.y), 
            cereal::make_nvp("z",v.z),
            cereal::make_nvp("w",v.w)
        );
    }
}

// Register all glm classes with Ponder
PONDER_TYPE(glm::vec2);
PONDER_TYPE(glm::vec3);
PONDER_TYPE(glm::vec4);

/**
 * Used to glue together the GLM library with the reflection library
 */
class GLMInitializer
{
public:

    static bool Initialize()
    {
        // Vec2
        ponder::Class::declare<glm::vec2>()
            .constructor()
            .constructor<float,float>()
            .property("x", &glm::vec2::x)
            .property("y", &glm::vec2::y)
            .function("Add", &glm::vec2::Add, ponder::policy::ReturnCopy())
				.tag("__add")
            .function("Subtract", &glm::vec2::Subtract, ponder::policy::ReturnCopy())
                .tag("__sub")
            .function("Multiply", &glm::vec2::Multiply, ponder::policy::ReturnCopy())
                .tag("__mul")
            .function("Divide", &glm::vec2::Divide, ponder::policy::ReturnCopy())
                .tag("_div")

            ;

        ponder::lua::expose<glm::vec2>(LuaState::L, "vec2");

        // Vec3
        ponder::Class::declare<glm::vec3>()
            .constructor()
            .constructor<float,float, float>()
            .property("x", &glm::vec3::x)
            .property("y", &glm::vec3::y)
            .property("z", &glm::vec3::y)
            ;

        ponder::lua::expose<glm::vec3>(LuaState::L, "vec3");

        // Vec4
        ponder::Class::declare<glm::vec4>()
            .constructor()
            .constructor<float,float, float, float>()
            .property("x", &glm::vec4::x)
            .property("y", &glm::vec4::y)
            .property("z", &glm::vec4::y)
            .property("w", &glm::vec4::y)
            ;

        ponder::lua::expose<glm::vec4>(LuaState::L, "vec4");

        return true;
    }
};