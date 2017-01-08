#pragma once

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

/** 
 * Responsible for maining LuaState and various lua methods 
 */
class LuaState
{
private:

public:
    static lua_State* L;

    static bool Initialize();

    static bool DoFile(const char* filePath);

    static void PrintError(lua_State* state);
    static void PrintError();
};