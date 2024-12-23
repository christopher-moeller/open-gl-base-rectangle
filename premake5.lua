-- premake5.lua
workspace "OpenGLBaseRectangle"
    configurations { "Debug", "Release" }
    platforms { "x64" }

project "OpenGLBaseRectangle"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"

    files { "src/**.h", "src/**.cpp" }

    includedirs { -- Path to GLFW and GLEW headers
        "vendor/GLFW/include",
        "vendor/GLEW/include"
    }

    externalincludedirs { "vendor/GLFW/include", "vendor/GLEW/include" } -- This is needed for XCode

    libdirs { -- Path to GLFW libraries
        "vendor/GLFW/lib",
        "vendor/GLEW/lib"
    }

    -- Link GLFW and macOS system frameworks
    links { 
        "GLEW",
        "GLFW",                      -- Link GLFW
        "OpenGL.framework"            -- OpenGL on macOS
    }
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
