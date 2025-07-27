cmake_minimum_required(VERSION 3.20)
project(cpp-learnings LANGUAGES C CXX)

# Windows-specific configuration
if(MSVC)
    add_compile_options(/W4 /WX /EHsc /Zc:__cplusplus /MD)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()  # Add for Linux/macOS
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Configure C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/libs/mymath)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
if(WIN32)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/Windows)
elseif(UNIX)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/Linux)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

add_executable(cpp_learningss
    src/main.cpp
)

add_subdirectory(src/cprimerplus)
add_subdirectory(src/cppprimer)
