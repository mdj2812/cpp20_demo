set(CMAKE_CXX_STANDARD 20)

file(GLOB cpp20_demo_SRC
     "*.cpp"
)

add_library(cpp20_demo_lib STATIC
    ${cpp20_demo_SRC}
)

target_include_directories(cpp20_demo_lib
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${PROJECT_SOURCE_DIR}
)
