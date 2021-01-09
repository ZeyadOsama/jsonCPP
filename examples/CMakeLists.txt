# add the example executable, linked with the jsonCPP library
add_executable(jsonCPP_Example end-to-end/main.cpp)
target_link_libraries(jsonCPP_Example jsonCPP ${SYSTEM_LIBRARIES})