#include "format_literal.h"

#include <gtest/gtest.h>

namespace Capybara {
TEST(FormatLiteralTestSuite, MixedParamsTestCase) {

  const auto actual = "{}-{}-{}::{}::{}<={}={}"_format("a", "b", 23, "dsf",
                                                       1.234345, "d", "Вжух");
  const std::string expected = "a-b-23::dsf::1.234345<=d=Вжух";

  EXPECT_EQ(expected, actual);
}

TEST(FormatLiteralTestSuite, SameParamsTestWihtTwoIntsCase) {
  EXPECT_EQ("1-2-3", "{}-{}-{}"_format(1, 2, 3));
  EXPECT_EQ("-1-2-3-", "-{}-{}-{}-"_format(1, 2, 3));
  EXPECT_EQ("Aaaa-Bbbb-Cccc", "{}-{}-{}"_format("Aaaa", "Bbbb", "Cccc"));
}

TEST(FormatLiteralTestSuite,
     SameParamsTestWihtTwoValuesAndThreePlaceHoldersCase) {
  EXPECT_EQ("1-2-{}", "{}-{}-{}"_format(1, 2));
  EXPECT_EQ("ABC-DEF-{}", "{}-{}-{}"_format("ABC", "DEF"));
}

TEST(FormatLiteralTestSuite,
     SameParamsTestWihtThreeValuesAndTwoPlaceHoldersCase) {
  EXPECT_EQ("1-2", "{}-{}"_format(1, 2, 3));
  EXPECT_EQ("<1-2>", "<{}-{}>"_format(1, 2, 3));
  EXPECT_EQ("<Aaaa-Bbbb>", "<{}-{}>"_format("Aaaa", "Bbbb", "Cccc"));
}

} // namespace Capybara
