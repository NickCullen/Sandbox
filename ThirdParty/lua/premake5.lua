project "lua"
    kind "SharedLib"
    language "C"

    location "../Build"

    configuration "SharedLib"
        defines "LUA_BUILD_AS_DLL"
    configuration {}

    files {
        "**.*"
    }

    excludes {
        "**._*",
        "luac.c",
        "lua.c"
    }