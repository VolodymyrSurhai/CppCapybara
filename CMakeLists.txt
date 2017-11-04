cmake_minimum_required(VERSION 3.5)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(CppCapybara)

set(CC_ENABLE_TESTS TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if (NOT CLANG_TIDY_PATH)
    message(error "Please set path to clang-tidy. Example: -DCLANG_TIDY_PATH=\"/usr/local/opt/llvm50/bin/clang-tidy-5.0\"")
endif (NOT CLANG_TIDY_PATH)

set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_PATH};-checks=cert-*,modernize-*,performance-*,readability-*,misc-*")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

if (${CC_ENABLE_TESTS})
    add_subdirectory(thirdparty/googletest)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    if (${MSVC})
        set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "CapybaraTest")

        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
        link_directories(${gtest_BINARY_DIR}/Debug)
    else()
        link_directories(${gtest_BINARY_DIR})
    endif()
endif (${CC_ENABLE_TESTS})

add_subdirectory(src)
