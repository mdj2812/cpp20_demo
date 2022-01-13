cmake_minimum_required(VERSION 3.17.0)
project(cpp20_demo)

# global compile options
add_compile_options(-pipe)
add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-Wfatal-errors)
add_compile_options(-fno-strict-aliasing) # this optimization can be re-enabled once code is compliant
add_compile_options(-fno-omit-frame-pointer)
add_compile_options(-pedantic )

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
