cmake_minimum_required(VERSION 3.31)
project(cpp_23 LANGUAGES C CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_sources(${PROJECT_NAME} PRIVATE
    FILE_SET CXX_MODULES FILES
    modules/math/math.cppm
    modules/math/add.cppm
    modules/math/sub.cppm
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)