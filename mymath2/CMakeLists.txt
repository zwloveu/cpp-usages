cmake_minimum_required(VERSION 3.20)
project(mymath2 LANGUAGES C)

# Windows-specific configuration
if(MSVC)
    add_compile_options(/W4 /WX /EHsc /Zc:__cplusplus /MD /analyze /sdl)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()  # Add for Linux/macOS and MinGW
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -g -O0)
endif()

# Configure C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configure C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(mymath2 STATIC
    src/mymath2.c
)

target_include_directories(mymath2 PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(mymath2 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/internal
)
