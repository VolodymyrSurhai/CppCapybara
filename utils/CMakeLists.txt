cmake_minimum_required (VERSION 3.6)

project (utils)
include_directories(sources)

file(GLOB prod_src
    "sources/*.h"
    "sources/*.cpp"
)

file(GLOB test_src
    "tests/*.h"
    "tests/*.cpp"
)

# add_library(${project_name} ${prod_src})
add_executable(${PROJECT_NAME}_test ${test_src})
target_link_libraries(${PROJECT_NAME}_test c++)






