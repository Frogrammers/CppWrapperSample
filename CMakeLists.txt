cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME "CppWrapperSample")
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    ./src/main.c
    ./src/Wrapper.cpp
)

include_directories(
    ./include
)

target_link_libraries(${PROJECT_NAME}
)
