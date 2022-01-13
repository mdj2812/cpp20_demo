set(CMAKE_CXX_STANDARD 17)

add_library(cpp17_demo_lib STATIC
    ThreeComp.cpp
)

target_include_directories(cpp17_demo_lib
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${PROJECT_SOURCE_DIR}
)
