# Set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)

# Project settings.
project(JSON-CPP VERSION 1.0.0)

# Set C++ standard to c++11.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DDATA_PATH="./examples/data/")

include_directories(prerequisites)
include_directories(include)

add_subdirectory(src)

option(jsonCPP_BUILD_EXAMPLES "Build the example of jsonCPP." OFF)
if (jsonCPP_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()

option(jsonCPP_BUILD_TESTS "Build the tests of jsonCPP." OFF)
if (jsonCPP_BUILD_TESTS)
    add_subdirectory(tests)
    include(CTest)
    add_test(NAME System-Tests
            COMMAND system-tests
            )
endif ()