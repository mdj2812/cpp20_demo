set(CMAKE_CXX_STANDARD 20)

add_library(cpp20_demo_lib STATIC
    DesignatedInitializer.cpp
    ThreeWayComp.cpp
)

target_include_directories(cpp20_demo_lib
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${PROJECT_SOURCE_DIR}
)
