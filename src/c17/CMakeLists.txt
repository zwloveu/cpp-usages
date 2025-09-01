cmake_minimum_required(VERSION 3.31)
project(c_17 LANGUAGES C)

add_executable(${PROJECT_NAME}
    src/main.c
)

target_sources(${PROJECT_NAME} PRIVATE
    src/utils/char_utils.c
)

target_sources(${PROJECT_NAME} PRIVATE
    src/data_structures/dictionary/dict_utils.c
    src/data_structures/dictionary/dictionary.c
    src/data_structures/dictionary/dict_insert.c
)

target_sources(${PROJECT_NAME} PRIVATE
    src/module01_memory_alignment/demonstrate_memory_alignment.c
)

target_sources(${PROJECT_NAME} PRIVATE
    src/module02_data_structures/demonstrate_data_structure_dictionary.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)