project "Ponder"
    kind "StaticLib"
    language "C++"

    buildoptions {
        "-std=c++14",
    }


    location "../Build"

    configuration "SharedLib"
        defines "PONDER_EXPORTS"
    configuration {}

    links {
        "lua"
    }
    
    files {
        "**.hpp",
        "**.inl",
        "**.cpp"
    }

    excludes {
        "**._*"
    }