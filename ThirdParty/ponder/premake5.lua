project "Ponder"
    kind "StaticLib"
    language "C++"

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