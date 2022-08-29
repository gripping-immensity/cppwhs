cmake_minimum_required(VERSION 3.14)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(print_ip VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt"
    GIT_TAG "master"
)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest"
    GIT_TAG "main"
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

set(SRC_PATH "src/")
set(IMPL_PATH "src/impl")
set(TESTS_PATH "src/tests")

add_executable(print_ip main.cpp)
target_link_libraries(print_ip fmt::fmt)
target_include_directories(print_ip PRIVATE ${SRC_PATH})

add_executable(print_ip_tests "${TESTS_PATH}/tests.cpp")
target_link_libraries(print_ip_tests fmt::fmt gtest gtest_main)
target_include_directories(print_ip_tests PRIVATE ${SRC_PATH})

if(MSVC)
    target_compile_options(print_ip PRIVATE /W4)
    target_compile_options(print_ip_tests PRIVATE /W4)
else()
    target_compile_options(print_ip PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(print_ip_tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
add_test(print_ip_tests print_ip_tests)
