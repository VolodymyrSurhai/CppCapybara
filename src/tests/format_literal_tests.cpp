#include "format_literal.h"

#include <gtest/gtest.h>

namespace Capybara
{
    TEST(FormatLiteralTestSuite, MixedParamsTestCase)
    {

        const auto actual = "{}-{}-{}::{}::{}<={}={}"_format("a", "b", 23, "dsf", 1.234345, 'd', "Вжух");
        const std::string expected = "a-b-23::dsf::1.234345<=d=Вжух";

        EXPECT_EQ(expected, actual);
    }

    TEST(FormatLiteralTestSuite, SameParamsTestWihtTwoInstansesCase)
    {
        EXPECT_EQ("1-2-3", "{}-{}-{}"_format(1, 2, 3));
        EXPECT_EQ("3-2-1", "{}-{}-{}"_format(3, 2, 1));
    }
} // namespace Capybara


