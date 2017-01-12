project "SandboxLauncher"
    kind "ConsoleApp"
    language "C++"

    buildoptions {
        "-std=c++14",
    }

    location "../Build"

    links {
        "Sandbox"
    }

    files {
        "**.h",
        "**.cpp"
    }

    excludes {
        "**._*"
    }