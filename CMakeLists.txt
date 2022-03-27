cmake_minimum_required(VERSION 3.21)
project(terminal_style)

set(CMAKE_CXX_STANDARD 14)

option(PROJECTS_TESTS "Builds the unit tests" OFF)
option(PROJECTS_DEMO "Builds the demo app for showing feature of the this lib" OFF)

if(PROJECTS_TESTS)
    add_subdirectory(tests)
endif()
if(PROJECTS_DEMO)
    add_subdirectory(demo)
endif()


add_subdirectory(lib)

