workspace "Beehive"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist",
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Beehive"
    location "Beehive"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "bhpch.h"
    pchsource "Beehive/src/bhpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions {"/utf-8"}

        defines
        {
            "BH_PLATFORM_WINDOWS",
            "BH_BUILD_DLL"
        }

        -- Put the generated dll file to the 
        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
        }

    filter "configurations:Debug"
        defines "BH_DEBUG"
        symbols "On"


    filter "configurations:Release"
        defines "BH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BH_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Beehive/vendor/spdlog/include",
        "Beehive/src",
    }

    links
    {
        "Beehive"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions {"/utf-8"}

        defines
        {
            "BH_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "BH_DEBUG"
        symbols "On"


    filter "configurations:Release"
        defines "BH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BH_DIST"
        optimize "On"
