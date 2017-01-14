project "lua"
    kind "SharedLib"
    language "C"
    
    --[[configurations {"windows", "SharedLib"}
       defines "LUA_BUILD_AS_DLL"
    configurations {}
    ]]--
    files {
        "**.*"
    }

    excludes {
        "**._*",
        "luac.c",
        "lua.c"
    }