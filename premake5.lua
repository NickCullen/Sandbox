print("OS = " .. _OS:upper())

solution "Sandbox"
    configurations {"Debug", "Release", "EditorDebug", "EditorRelease"}
    
    location "Build"

    includedirs {
        "ThirdParty",
        "ThirdParty/ponder/include",
        "ThirdParty/lua",
        "Sandbox/Include"
    }

    defines {
        "PONDER_USING_LUA=1",
        "PONDER_USES_LUA_IMPL",
        "PONDER_USES_RUNTIME_IMPL",
        "PONDER_STATIC",
        "SANDBOX_" .. _OS:upper()
    }


    configuration "windows"
        defines {
            "WIN32",
        }
   
    configuration "Debug"
        targetdir "Bin/Debug"

        flags {
            "Symbols"   -- Debug symbols
        }

        defines {
            "DEBUG",
            "SANDBOX_DEBUG"
        }

    configuration "Release"
        targetdir "Bin/Release"

        flags {
            "Optimize"
        }

        defines {
            "NDEBUG",
            "SANDBOX_RELEASE"
        }

    configuration "EditorDebug"
        targetdir "Bin/Editor/Debug"

        flags {
            "Symbols"   -- Debug symbols
        }

        defines {
            "DEBUG",
            "SANDBOX_DEBUG",
            "SANDBOX_EDITOR"
        }
        
        include "sb"

    configuration "EditorRelease"
        targetdir "Bin/Editor/Release"

        flags {
            "Optimize"
        }

        defines {
            "NDEBUG",
            "SANDBOX_RELEASE",
            "SANDBOX_EDITOR"
        }

        include "sb"
    
    -----------------------------------------

    include "ThirdParty/lua"
    include "ThirdParty/ponder"
    include "Launcher"
    include "Sandbox"