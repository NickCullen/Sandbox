project "SandboxLauncher"
    kind "ConsoleApp"
    language "C++"
    
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