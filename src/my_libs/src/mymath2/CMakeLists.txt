cmake_minimum_required(VERSION 3.31)
project(mymath2 LANGUAGES C)

add_library(${PROJECT_NAME}
    STATIC
    src/lib.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
