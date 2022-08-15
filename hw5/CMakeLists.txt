cmake_minimum_required(VERSION 3.23)
project(EditorSketch)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt"
    GIT_TAG "master"
)

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(EditorSketch main.cpp)
target_include_directories(EditorSketch PRIVATE "src/include/")
target_link_libraries(EditorSketch fmt)


