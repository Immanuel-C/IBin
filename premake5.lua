workspace "IWindow"
    configurations {"Debug", "Release"}
    architecture "x86_64"

    
    function defaultBuildLocation()
        targetdir ("bin/%{prj.name}/%{cfg.buildcfg}")
        objdir ("bin-int/%{prj.name}/%{cfg.buildcfg}")
    end

    function defaultBuildCfg() -- defaultBuildCfg should always be under defaultBuildLocation
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
            runtime "Debug"
            optimize "Debug"

        filter "configurations:Release"
            defines { "NDEBUG" }
            symbols "Off"
            runtime "Release"
            optimize "Speed"
    end
    
    startproject("Test")
    project "Test"
        location "test"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++11"

        includedirs { "src" }
        files { "test/Main.cpp", "src/IBin.cpp" }

        defaultBuildLocation()
        defaultBuildCfg()
    