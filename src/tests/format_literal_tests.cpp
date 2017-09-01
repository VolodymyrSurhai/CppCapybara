#include "format_literal.h"

#include <gtest/gtest.h>

namespace Capybara {
namespace Tests {
TEST(FormatLiteralTestSuite, mixedParamsTestCase) {

  const auto actual = "{}-{}-{}::{}::{}<={}={}"_format("a", "b", 23, "dsf",
                                                       1.234345, "d", "Вжух");
  const std::string expected = "a-b-23::dsf::1.234345<=d=Вжух";

  EXPECT_EQ(expected, actual);
}

TEST(FormatLiteralTestSuite, sameParamsTestWihtTwoIntsCase) {
  EXPECT_EQ("1-2-3", "{}-{}-{}"_format(1, 2, 3));
  EXPECT_EQ("-1-2-3-", "-{}-{}-{}-"_format(1, 2, 3));
  EXPECT_EQ("Aaaa-Bbbb-Cccc", "{}-{}-{}"_format("Aaaa", "Bbbb", "Cccc"));
}

TEST(FormatLiteralTestSuite,
     sameParamsTestWihtTwoValuesAndThreePlaceHoldersCase) {
  EXPECT_EQ("1-2-{}", "{}-{}-{}"_format(1, 2));
  EXPECT_EQ("ABC-DEF-{}", "{}-{}-{}"_format("ABC", "DEF"));
}

TEST(FormatLiteralTestSuite,
     sameParamsTestWihtThreeValuesAndTwoPlaceHoldersCase) {
  EXPECT_EQ("1-2", "{}-{}"_format(1, 2, 3));
  EXPECT_EQ("<1-2>", "<{}-{}>"_format(1, 2, 3));
  EXPECT_EQ("<Aaaa-Bbbb>", "<{}-{}>"_format("Aaaa", "Bbbb", "Cccc"));
}

} // namespace Tests
} // namespace Capybara
