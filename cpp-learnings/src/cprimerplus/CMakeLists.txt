set(CPRIMER_SOURCES
    src/01_01.c
    src/02_01.c
    src/02_02.c
    src/03_01.c
    src/04_01.c
    src/05_01.c
    src/05_02.c
    src/05_03.c
)

set(CPRIMER_INTERNAL_SOURCES
    src/internal/recursives.c
)

foreach(source_file ${CPRIMER_SOURCES})
    get_filename_component(source_file_name ${source_file} NAME_WE)
    
    add_executable(cprimerplus_${source_file_name}
        ${source_file}
        ${CPRIMER_INTERNAL_SOURCES})

    target_include_directories(cprimerplus_${source_file_name} 
        PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    )
endforeach()

target_link_libraries(cprimerplus_01_01 PRIVATE 
    mymath
    mymath2
)