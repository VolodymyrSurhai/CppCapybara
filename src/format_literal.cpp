#include "format_literal.h"

#include <vector>

namespace {
const std::string StringRepresentationPlaceHolder = "{}";

using Tokens = Capybara::FormattedString::Tokens;
using PlaceHolder = Capybara::FormattedString::PlaceHolder;

Tokens parsePattern(const std::string &pattern) {
  Tokens tokens;
  auto placeHolderIndex = pattern.find(StringRepresentationPlaceHolder);
  std::size_t oldPlaceHolderIndex = 0;

  if (placeHolderIndex == std::string::npos) {
    tokens.push_back(PlaceHolder(pattern));
    return tokens;
  } else {
    tokens.push_back(PlaceHolder());
  }

  while (placeHolderIndex != std::string::npos) {

    auto placeHolder = pattern.substr(
        oldPlaceHolderIndex + StringRepresentationPlaceHolder.size(),
        placeHolderIndex - oldPlaceHolderIndex -
            StringRepresentationPlaceHolder.size());

    if (placeHolderIndex != 0) {

      tokens.push_back(PlaceHolder(std::move(placeHolder)));
      tokens.push_back(PlaceHolder());
    }

    oldPlaceHolderIndex = placeHolderIndex;

    placeHolderIndex =
        pattern.find(StringRepresentationPlaceHolder, placeHolderIndex + 1);
  }

  return tokens;
}
} // namespace

namespace Capybara {
FormattedString::PlaceHolder::PlaceHolder() : _valueWasSet(false) {}

FormattedString::PlaceHolder::PlaceHolder(const std::string &value)
    : _valueWasSet(true), _value(std::move(value)) {}

bool FormattedString::PlaceHolder::isValueWasSet() const {
  return _valueWasSet;
}
std::string FormattedString::PlaceHolder::getValue() const {
  if (!_valueWasSet) {
    return StringRepresentationPlaceHolder;
  }

  return _value;
}
void FormattedString::PlaceHolder::setValue(std::string value) {
  _value = std::move(value);
}

std::string FormattedString::tokensToString(const Tokens &tokens) {
  if (tokens.size() == 1) {
    return tokens[0].getValue();
  }

  std::size_t textSize = 0;
  for (const auto &token : tokens) {
    textSize += token.getValue().size();
  }

  std::string result;
  result.reserve(textSize);

  for (const auto &token : tokens) {
    result += token.getValue();
  }

  return result;
}

FormattedString::FormattedString(const std::string &pattern)
    : _tokens(parsePattern(pattern)) {}

FormattedString operator""_format(const char *pattern, const std::size_t /*size*/) {
  return FormattedString(pattern);
}

} // namespace Capybara
