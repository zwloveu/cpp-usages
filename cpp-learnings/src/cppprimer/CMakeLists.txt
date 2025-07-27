file(GLOB INTERNAL_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CppPrimer/**/**/*.cpp
)

message(STATUS "Found internal sources: ${INTERNAL_SOURCES}")

add_library(cppprimer_lib OBJECT
    ${INTERNAL_SOURCES}
)

target_include_directories(cppprimer_lib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(CPPPRIMER_SOURCES
    src/01_01.cpp
)

foreach(source_file ${CPPPRIMER_SOURCES})
    get_filename_component(source_file_name ${source_file} NAME_WE)
    
    add_executable(cppprimer_${source_file_name}
        ${source_file}
        $<TARGET_OBJECTS:cppprimer_lib>
    )

    target_include_directories(cppprimer_${source_file_name} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
endforeach()