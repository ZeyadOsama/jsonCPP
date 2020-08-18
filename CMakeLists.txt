cmake_minimum_required(VERSION 3.4)
project(JSON-Parser)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DDATA_PATH="./examples/data/")

add_subdirectory(json)
include_directories(json/include)

option(JSON_BUILD_EXAMPLE "Build the example of CLogger." OFF)
if (JSON_BUILD_EXAMPLE)
    # add the example executable, linked with the JSON library
    add_executable(JSON_Example examples/main.cpp)
    target_link_libraries(JSON_Example JSON ${SYSTEM_LIBRARIES})
endif ()