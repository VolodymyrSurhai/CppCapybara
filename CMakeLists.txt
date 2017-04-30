cmake_minimum_required(VERSION 3.6)

project(CppCapybara)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

if (${ENABLE_TESTS})
    add_subdirectory(thirdparty/googletest)
    include_directories(thirdparty/googletest/googletest/include)
    link_directories(${PROJECT_BINARY_DIR}/thirdparty/googletest/googlemock/gtest)
endif (${ENABLE_TESTS})

add_subdirectory(src)
