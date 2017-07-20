cmake_minimum_required(VERSION 3.5)

project(CppCapybara)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

if (${CC_ENABLE_TESTS})
    add_subdirectory(thirdparty/googletest)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    if (${MSVC})
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
        link_directories(${gtest_BINARY_DIR}/Debug)
    else()
        link_directories(${gtest_BINARY_DIR})
    endif()
endif (${CC_ENABLE_TESTS})

add_subdirectory(src)
