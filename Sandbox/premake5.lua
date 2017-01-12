project "Sandbox"
    kind "SharedLib"
    language "C++"
    
    location "../Build"

    buildoptions {
        "-std=c++14",
    }

    links {
        "Ponder",
        "lua"
    }

    files {
        "**.h",
        "**.cpp"
    }

    excludes {
        "**._*",
        "**conf*"
    }

    configuration "SharedLib"
        defines {
            "SANDBOX_EXPORTS"
        }
    configuration {}

    

    