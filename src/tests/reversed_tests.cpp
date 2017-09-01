#include "reversed.h"

#include <gtest/gtest.h>

namespace Capybara {
namespace Tests {
TEST(ReverseTestSuite, reversedIntVectorIteratorTestCase) {
  std::vector<int> container = {1, 2, 3, 4};

  std::string result;

  for (const auto &item : reversed(container)) {
    result += std::to_string(item);
  }

  EXPECT_EQ("4321", result);
}

TEST(ReverseTestSuite, reversedIntVectorConstIteratorTestCase) {
  const std::vector<int> container = {1, 2, 3, 4};

  std::string result;

  for (const auto &item : reversed(container)) {
    result += std::to_string(item);
  }

  EXPECT_EQ("4321", result);
}

TEST(ReverseTestSuite, reversedStringVectorIteratorTestCase) {
  std::vector<std::string> container = {"1", "2", "3", "4"};

  std::string result;

  for (const auto &item : reversed(container)) {
    result += item;
  }

  EXPECT_EQ("4321", result);
}

TEST(ReverseTestSuite, reversedStringVectorConstIteratorTestCase) {
  const std::vector<std::string> container = {"1", "2", "3", "4"};

  std::string result;

  for (const auto &item : reversed(container)) {
    result += item;
  }

  EXPECT_EQ("4321", result);
}

} // namespace Tests
} // namespace Capybara
