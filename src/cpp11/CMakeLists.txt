cmake_minimum_required(VERSION 3.20)
project(cpp_11 LANGUAGES C CXX)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/module01_range_for/demonstrate_range_for.cpp
    src/module02_left_right_value/demonstrate_left_right_value.cpp
    src/module03_raii/demonstrate_raii.cpp
    src/module04_constructor/demonstrate_constructor.cpp
    src/module04_constructor/my_class.cpp
    src/module05_pointer/demonstrate_pointer.cpp
    src/module06_namespace/demonstrate_namespace.cpp
    src/module06_namespace/country.cpp
    src/module07_extern_c/demonstrate_extern_c.cpp
    src/module07_extern_c/c_functions.c
    src/module08_third_party/demonstrate_third_party.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE
    $<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/libs/lib/Windows>
    $<$<PLATFORM_ID:Linux>:${CMAKE_CURRENT_SOURCE_DIR}/libs/lib/Linux>
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    mymath2
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/
    PATTERN "README.md" EXCLUDE
)