project "sb"
    kind "ConsoleApp"
    language "C++"
    
    links {
        "Ponder",
        "lua",
        "Sandbox"
    }

    defines {
        "SB_LUA_DIR=\"".._MAIN_SCRIPT_DIR.."/sb/lua/\""
    }

    files {
        "**.h",
        "**.cpp"
    }

    excludes {
        "**._*",
        "**conf*"
    }

    configurations {"Debug", "EditorDebug"}

        debugargs {
            "test",
            "Hello",
            "234"
        }
    configurations{}
    

    