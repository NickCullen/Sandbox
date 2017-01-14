print("OS = " .. _OS:upper())
solution "Sandbox"
    configurations {"Debug", "Release", "EditorDebug", "EditorRelease"}
    
    location (_MAIN_SCRIPT_DIR .. "/Build")

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

    filter{"language:C++"}
        buildoptions {
            "-std=c++14",
        }
    filter {}

    configuration "windows"
        defines {
            "WIN32",
        }
    configuration {}

    configuration "Debug"
        targetdir (_MAIN_SCRIPT_DIR .. "/Bin/Debug")

        flags {
            "Symbols"   -- Debug symbols
        }

        defines {
            "DEBUG",
            "SANDBOX_DEBUG"
        }
    configuration {}

    configuration "Release"
        targetdir (_MAIN_SCRIPT_DIR .. "/Bin/Release")

        flags {
            "Optimize"
        }

        defines {
            "NDEBUG",
            "SANDBOX_RELEASE"
        }
    configuration {}

    configuration "EditorDebug"
        targetdir (_MAIN_SCRIPT_DIR .. "/Bin/Editor/Debug")

        flags {
            "Symbols"   -- Debug symbols
        }

        defines {
            "DEBUG",
            "SANDBOX_DEBUG",
            "SANDBOX_EDITOR"
        }
        
        include "sb"

    configuration {}

    configuration "EditorRelease"
        targetdir (_MAIN_SCRIPT_DIR .. "/Bin/Editor/Release")

        flags {
            "Optimize"
        }

        defines {
            "NDEBUG",
            "SANDBOX_RELEASE",
            "SANDBOX_EDITOR"
        }

        include "sb"
    
    configuration {}
    
    -----------------------------------------

    include "ThirdParty/lua"
    include "ThirdParty/ponder"
    include "Launcher"
    include "Sandbox"