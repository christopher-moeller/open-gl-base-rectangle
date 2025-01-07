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

    files { "src/**.h", "src/**.cpp", "src/**.glsl" }

    includedirs { -- Path to GLFW, GLEW and GLM headers
        "vendor/GLFW/include",
        "vendor/GLEW/include",
        "vendor/GLM/include"
    }

    externalincludedirs { "vendor/GLFW/include", "vendor/GLEW/include", "vendor/GLM/include" } -- This is needed for XCode

    libdirs { -- Path to GLFW libraries
        "vendor/GLFW/lib",
        "vendor/GLEW/lib",
        "vendor/GLM/lib"
    }

    -- Link GLFW and macOS system frameworks
    links { 
        "GLEW",
        "GLM",
        "GLFW",                      -- Link GLFW
        "OpenGL.framework"            -- OpenGL on macOS
    }

    debugdir "." -- Set the working directory to the root of your project directory
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
