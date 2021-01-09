set(SOURCES

        ${CMAKE_CURRENT_SOURCE_DIR}/common/dataunits/Value.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/parsers/Parser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/Utils.cpp
        )

add_library(jsonCPP
        STATIC
        ${SOURCES}
        )