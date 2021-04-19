cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(BinaryHeap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC
        src/binary_heap.cpp include/binary_heap.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

# add executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${PROJECT_NAME})