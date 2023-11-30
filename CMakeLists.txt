cmake_minimum_required(VERSION 3.26)
project(cpp-core)

option(EXT_BUILD_DIR "Output build result to diffrent directory" OFF)

if (EXT_BUILD_DIR)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/debug)
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/release)
    else ()
        message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
    endif ()
endif ()

set(CMAKE_CXX_STANDARD 23)

add_library(core
        core.cpp
        core.h
)