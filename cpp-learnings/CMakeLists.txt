cmake_minimum_required(VERSION 3.20)
project(cpp-learnings LANGUAGES C CXX)

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

file(GLOB CPP_LEARNINGS_SOURCES_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/sources/*.cpp")
message(STATUS "Collected sources for cpp_learnings: ${CPP_LEARNINGS_SOURCES_SOURCES}")
add_executable(cpp_learnings
    src/main.cpp
    ${CPP_LEARNINGS_SOURCES_SOURCES}
)
target_include_directories(cpp_learnings
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/includes
)

add_executable(c_learnings
    src/main.c
)

add_subdirectory(src/cprimerplus)
add_subdirectory(src/cppprimer)
