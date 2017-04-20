cmake_minimum_required(VERSION 3.6)

project(Capybara)
include_directories(.)

file(GLOB PROD_SRC
        "*.h"
        "*.cpp"
        )

file(GLOB TEST_SRC
        "tests/*.h"
        "tests/*.cpp"
        )

# add_library(${PROJECT_NAME} ${PROD_SRC})
add_executable(${PROJECT_NAME}Test ${TEST_SRC})
target_link_libraries(${PROJECT_NAME}Test gtest_main)
