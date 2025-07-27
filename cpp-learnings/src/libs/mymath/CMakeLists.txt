add_library(mymath STATIC
    src/mymath.c)

target_include_directories(mymath PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(mymath PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/internal
)
