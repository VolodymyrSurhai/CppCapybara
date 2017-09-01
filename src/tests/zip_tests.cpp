#include "zip.h"

#include <gtest/gtest.h>

#include <string>

namespace Capybara {
namespace Tests {
TEST(ZipTestSuite, ZipIntAndString) {
  std::vector<int> numbers = {11, 21, 31, 41};
  std::vector<std::string> text = {"first", "second", "third", "fourth"};

  std::string result;

  for (auto& zipped : zip(numbers, text)) {
    result += std::to_string(zipped.second);

    zipped.first += 10;
    result += zipped.first;
  }

  EXPECT_EQ("first21second31third41fourth51", result);
}
} // namespace Tests
} // namespace Capybara
