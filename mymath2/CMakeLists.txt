cmake_minimum_required(VERSION 3.20)
project(mymath2 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /WX /MD)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_library(mymath2 STATIC
    src/mymath2.c
)

target_include_directories(mymath2 PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(mymath2 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/internal
)
