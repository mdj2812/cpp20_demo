set(CMAKE_CXX_STANDARD 17)

file(GLOB cpp17_demo_SRC
     "*.cpp"
)

add_library(cpp17_demo_lib STATIC
    ${cpp17_demo_SRC}
)

target_include_directories(cpp17_demo_lib
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${PROJECT_SOURCE_DIR}
)
