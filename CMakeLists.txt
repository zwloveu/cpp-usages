cmake_minimum_required(VERSION 3.31)

project(cpp_workspace)

# Windows-specific configuration
if(MSVC)
    add_compile_options(
        /W4               # Enable all warning levels (highest level of compiler warnings)
        /WX               # Treat all warnings as errors
        /EHsc             # Enable C++ exception handling (only catches C++ exceptions)
        /Zc:__cplusplus   # Ensure __cplusplus macro reports correct C++ standard version
        /MD               # Use multi-threaded DLL runtime library
        /permissive-      # Enforce strict C++ standard compliance
    )
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()  # Add for Linux/macOS and MinGW
    add_compile_options(
        -Wall             # Enable all basic compiler warnings
        -Wextra           # Enable extra warning flags not included in -Wall
        -Wpedantic        # Enforce strict ISO C/C++ standard compliance
        -Werror           # Treat all warnings as errors
        -g                # Generate debug information
        -O0               # Disable compiler optimizations (for debugging)
        -pedantic-errors  # Make pedantic warnings into errors
    )
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src/learnings)