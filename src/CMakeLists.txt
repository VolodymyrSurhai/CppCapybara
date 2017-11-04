project(Capybara)
include_directories(.)

file(GLOB PROD_SRC
        "*.h"
        "*.cpp"
        "utils/*.h"
        "utils/*.cpp"
        )
add_library(${PROJECT_NAME} ${PROD_SRC})

if (${CC_ENABLE_TESTS})
    enable_testing()

    file(GLOB TEST_SRC
            "tests/*.h"
            "tests/*.cpp"
            )

    add_executable(${PROJECT_NAME}Test ${TEST_SRC})
    add_test(AllTests ${PROJECT_NAME}Test)
    target_link_libraries(${PROJECT_NAME}Test
            ${PROJECT_NAME}
            gtest_main
            )
endif (${CC_ENABLE_TESTS})
