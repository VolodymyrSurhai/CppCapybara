#include "zip.h"

#include <gtest/gtest.h>

#include <string>

namespace Capybara {
namespace Tests {
TEST(ZipTestSuite, ZipIntAndStringOldFor) {
  std::vector<int> numbers = {11, 21, 31, 41};
  std::vector<std::string> texts = {"first", "second", "third", "fourth"};

  std::string result;

  auto zipped = zip(numbers, texts);

  auto zippedIterator = std::begin(zipped);
  auto endIterator = std::end(zipped);
  for (; zippedIterator != endIterator; ++zippedIterator) {
    auto zipped = *zippedIterator;
    result += std::to_string(zipped.first);

    zipped.first += 10;
    result += zipped.first;
  }

  EXPECT_EQ("first21second31third41fourth51", result);
}

TEST(ZipTestSuite, ZipIntAndStringModernFor) {
  std::vector<int> numbers = {11, 21, 31, 41};
  std::vector<std::string> texts = {"first", "second", "third", "fourth"};

  std::string result;

  for (auto zipped : zip(numbers, texts)) {
    result += std::to_string(zipped.first);

    zipped.first += 10;
    result += zipped.first;
  }

  EXPECT_EQ("first21second31third41fourth51", result);
}
} // namespace Tests
} // namespace Capybara
