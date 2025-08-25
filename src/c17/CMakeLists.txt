cmake_minimum_required(VERSION 3.20)
project(c_17 LANGUAGES C)

add_executable(${PROJECT_NAME}
    src/main.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)