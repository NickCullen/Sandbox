#include "Core/LuaState.h"

#include <stdio.h>

lua_State* LuaState::L = nullptr;

bool LuaState::Initialize()
{
    L = luaL_newstate();
    if(L == nullptr)
        return false;
    
    // Make standard libraries available in the Lua object
    luaL_openlibs(L);

    printf("Lua State opened\n");

    return true;
    
}

bool LuaState::DoFile(const char* filename)
{
    int result;

    // Load the program; this supports both source code and bytecode files.
    result = luaL_loadfile(L, filename);

    if ( result != LUA_OK ) {
        PrintError(L);
        return false;
    }

    // Finally, execute the program by calling into it.
    // Change the arguments if you're not running vanilla Lua code.

    result = lua_pcall(L, 0, LUA_MULTRET, 0);

    if ( result != LUA_OK ) {
        PrintError(L);
        return false;
    }


    return true;
}

void LuaState::PrintError(lua_State* state)
{
    printf("lua error = %s\n", lua_tostring(L, -1));

}

void LuaState::PrintError()
{
    PrintError(L);
}