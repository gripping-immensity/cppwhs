cmake_minimum_required(VERSION 3.23)
project(EditorSketch)

set(CMAKE_CXX_STANDARD 14)

add_executable(EditorSketch main.cpp)
target_include_directories(EditorSketch PRIVATE "src/include/")

