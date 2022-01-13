cmake_minimum_required(VERSION 3.17.0)
project(cpp20_demo)

include(CTest)
enable_testing()

add_subdirectory(cpp17)
add_subdirectory(cpp20)

add_executable(cpp20_demo main.cpp)

target_link_libraries(cpp20_demo
    PUBLIC
        cpp17_demo_lib
        cpp20_demo_lib
)
