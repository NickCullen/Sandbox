print("OS = " .. os.get())

solution "Sandbox"
    configurations {"Debug", "Release"}

    location "Build"

    includedirs {
        "ThirdParty",
        "ThirdParty/glm",
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


    -- lua scriptinglibrary
    project "lua"
        kind "StaticLib"
        language "C"

        location "Build"

        files {
            "ThirdParty/lua/**.*"
        }

        excludes {
            "**._*"
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
            "Sandbox",
            "Ponder",
            "lua"
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
        kind "StaticLib"
        language "C++"

        buildoptions {
            "-std=c++14",
        }

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
            "**._*"
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