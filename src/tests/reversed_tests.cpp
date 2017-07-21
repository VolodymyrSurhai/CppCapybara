#include "reversed.h"

#include <gtest/gtest.h>


namespace Capybara
{
    TEST(ReverseTestSuite, ReversedIntVectorIteratorTestCase)
    {
        std::vector<int> container = {1, 2, 3, 4};

        std::string result;

        for (const auto& item : reversed(container))
        {
            result += std::to_string(item);
        }

        EXPECT_EQ("4321", result);

    }

    TEST(ReverseTestSuite, ReversedIntVectorConstIteratorTestCase)
    {
        const std::vector<int> container = {1, 2, 3, 4};

        std::string result;

        for (const auto& item : reversed(container))
        {
            result += std::to_string(item);
        }

        EXPECT_EQ("4321", result);

    }

    TEST(ReverseTestSuite, ReversedStringVectorIteratorTestCase)
    {
        std::vector<std::string> container = {"1", "2", "3", "4"};

        std::string result;

        for (const auto& item : reversed(container))
        {
            result += item;
        }

        EXPECT_EQ("4321", result);
    }

    TEST(ReverseTestSuite, ReversedStringVectorConstIteratorTestCase)
    {
        const std::vector<std::string> container = {"1", "2", "3", "4"};

        std::string result;

        for (const auto& item : reversed(container))
        {
            result += item;
        }

        EXPECT_EQ("4321", result);
    }

} // namespace Capybara
