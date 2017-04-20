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
} // namespace Capybara


