print("OS = " .. os.get())

solution "Sandbox"
    configurations {"Debug", "Release"}

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
        "PONDER_STATIC"
    }

    if os.get() == "windows" then
        defines {
            "WIN32"
        }
    end

    configuration "Debug"
        targetdir "Bin/Debug"

        if os.get() == "windows" then

            flags {
                "Symbols"   -- Debug symbols
            }
        end

    configuration "Release"
        targetdir "Bin/Release"

        flags {
            "Optimize"
        }

    -----------------------------------------


    -- lua scriptinglibrary
    project "lua"
        kind "SharedLib"
        language "C"

        location "Build"

        configuration "SharedLib"
            defines "LUA_BUILD_AS_DLL"
        configuration {}
        files {
            "ThirdParty/lua/**.*"
        }

        excludes {
            "**._*",
            "**/luac.c",
            "**/lua.c"
        }

    -----------------------------------------

    -- Ponder reflection library
    project "Ponder"
        kind "StaticLib"
        language "C++"

        buildoptions {
            "-std=c++14",
        }


        location "Build"

        configuration "SharedLib"
            defines "PONDER_EXPORTS"
        configuration {}

        links {
            "lua"
        }
        
        files {
            "ThirdParty/ponder/**.hpp",
            "ThirdParty/ponder/**.inl",
            "ThirdParty/ponder/**.cpp"
        }

        excludes {
            "**._*"
        }

    -----------------------------------------

    -- Launcher Project
    project "SandboxLauncher"
        kind "ConsoleApp"
        language "C++"

        buildoptions {
            "-std=c++14",
        }

        location "Build"

        links {
            "Sandbox"
        }

        files {
            "Launcher/**.h",
            "Launcher/**.cpp"
        }

        excludes {
            "**._*"
        }
    -------------------------------------------

    -- Sandbox Library
    project "Sandbox"
        kind "SharedLib"
        language "C++"

        buildoptions {
            "-std=c++14",
        }

        configuration "SharedLib"
            defines {
                "SANDBOX_EXPORTS"
            }
        configuration {}

        location "Build"

        links {
            "Ponder",
            "lua"
        }
        files {
            "Sandbox/**.h",
            "Sandbox/**.cpp"
        }

        excludes {
            "**._*",
            "**conf*"
        }
    ----------------------------------------

    






    -- Test C# editor
   --[[ project "Editor"
        kind "ConsoleApp"
        language "C#"

        location "Build"

        links {
            "System",
            "System.Windows.Forms",
            "System.Drawing"
        }

        files {
            "Editor/**.cs"
        }]]--
    -----------------------------------------