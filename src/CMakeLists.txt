cmake_minimum_required(VERSION 3.6)

project(Capybara)
include_directories(.)

file(GLOB prod_src
        "*.h"
        "*.cpp"
        )

file(GLOB test_src
        "tests/*.h"
        "tests/*.cpp"
        )

# add_library(${project_name} ${prod_src})
add_executable(${PROJECT_NAME}_test ${test_src})
