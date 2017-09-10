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
    result += zipped.second;

    zipped.first += 10;
    result += std::to_string(zipped.first);
  }

  EXPECT_EQ("first21second31third41fourth51", result);
}

TEST(ZipTestSuite, ZipIntAndStringModernFor) {
  std::vector<int> numbers = {11, 21, 31, 41};
  std::vector<std::string> texts = {"first", "second", "third", "fourth"};

  std::string result;

  for (auto zipped : zip(numbers, texts)) {
    result += zipped.second;

    zipped.first += 10;
    result += std::to_string(zipped.first);
  }

  EXPECT_EQ("first21second31third41fourth51", result);

  ASSERT_EQ(4u, numbers.size());
  EXPECT_EQ(11, numbers[0]);
  EXPECT_EQ(21, numbers[1]);
  EXPECT_EQ(31, numbers[2]);
  EXPECT_EQ(41, numbers[3]);
}

TEST(ZipTestSuite, ZipIntAndStringModernForWithModification) {
  std::vector<int> numbers = {11, 21, 31, 41};
  std::vector<std::string> texts = {"first", "second", "third", "fourth"};

  std::string result;

  for (auto& zipped : zip(numbers, texts)) {
    result += zipped.second;

    zipped.first += 10;
    result += std::to_string(zipped.first);
  }

  EXPECT_EQ("first21second31third41fourth51", result);

  ASSERT_EQ(4u, numbers.size());
  EXPECT_EQ(21, numbers[0]);
  EXPECT_EQ(31, numbers[1]);
  EXPECT_EQ(41, numbers[2]);
  EXPECT_EQ(51, numbers[3]);
}

TEST(ZipTestSuite, ZipConstIntAndStringOldFor) {
  const std::vector<int> numbers = {11, 21, 31, 41};
  const std::vector<std::string> texts = {"first", "second", "third", "fourth"};

  std::string result;

  auto zipped = zip(numbers, texts);

  auto zippedIterator = std::begin(zipped);
  auto endIterator = std::end(zipped);
  for (; zippedIterator != endIterator; ++zippedIterator) {
    auto zipped = *zippedIterator;
    result += zipped.second;

    zipped.first += 10;
    result += std::to_string(zipped.first);
  }

  EXPECT_EQ("first21second31third41fourth51", result);
}

TEST(ZipTestSuite, ZipConstIntAndStringModernFor) {
  const std::vector<int> numbers = {11, 21, 31, 41};
  const std::vector<std::string> texts = {"first", "second", "third", "fourth"};

  std::string result;

  for (auto zipped : zip(numbers, texts)) {
    result += zipped.second;

    zipped.first += 10;
    result += std::to_string(zipped.first);
  }

  EXPECT_EQ("first21second31third41fourth51", result);
}

} // namespace Tests
} // namespace Capybara
