cmake_minimum_required(VERSION 3.10.0)
project(cpp20_demo)

# global compile options
set(CMAKE_CXX_COMPILER "g++-10")

add_compile_options(-pipe)
add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wfatal-errors)
add_compile_options(-pedantic )
add_compile_options(-fsanitize=address)
add_compile_options(-fcoroutines)
add_compile_options(-O3 )
add_link_options(-fsanitize=address)

add_subdirectory(cpp17)
add_subdirectory(cpp20)

add_executable(cpp20_demo main.cpp)

target_link_libraries(cpp20_demo
    PUBLIC
        cpp17_demo_lib
        cpp20_demo_lib
)
