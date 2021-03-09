cmake_minimum_required(VERSION 3.10)
project(AudioEffect)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
if(UNIT_TEST)
    add_subdirectory(tests)
endif()