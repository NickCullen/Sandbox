project "Sandbox"
    kind "SharedLib"
    language "C++"
    
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

    --linkoptions{ "-L%{cfg.targetdir}" }
    --linkoptions{ "-Wl,-rpath=./" }

    filter { "kind:SharedLib", "system:macosx" }
        linkoptions { '-Wl,-install_name', '-Wl,@loader_path/%{cfg.linktarget.name}' }
    filter {}
    

    