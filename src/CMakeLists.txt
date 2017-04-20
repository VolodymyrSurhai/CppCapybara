project(Capybara)
include_directories(.)

file(GLOB PROD_SRC
        "*.h"
        "*.cpp"
        "utils/*.h"
        "utils/*.cpp"
        )

file(GLOB TEST_SRC
        "tests/*.h"
        "tests/*.cpp"
        )

message(${PROD_SRC})
message(${TEST_SRC})

add_library(${PROJECT_NAME} ${PROD_SRC})
add_executable(${PROJECT_NAME}Test ${TEST_SRC})
target_link_libraries(${PROJECT_NAME}Test
        ${PROJECT_NAME}
        gtest_main
        )
