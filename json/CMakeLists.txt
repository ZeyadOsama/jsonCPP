# JSON Library CMakeLists.txt

include_directories(include)
add_library(
        JSON
        SHARED

        src/Base/Parser.cpp
        src/Base/Value.cpp
        src/Utils/Utils.cpp
)