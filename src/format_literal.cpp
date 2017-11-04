#include "format_literal.h"

namespace {
using Tokens = Capybara::FormattedString::Tokens;
using PlaceHolder = Capybara::Impl::PlaceHolder;

const auto StringRepresentationPlaceHolder = "{}";

Tokens parsePattern(const std::string &pattern) {
  static const auto stringRepresentationPlaceHolder =
      std::string(StringRepresentationPlaceHolder);
  Tokens tokens;
  auto oldPlaceHolderIndex = pattern.find(stringRepresentationPlaceHolder);

  if (oldPlaceHolderIndex == std::string::npos) {
    tokens.emplace_back(PlaceHolder(pattern));
    return tokens;
  }
  if (oldPlaceHolderIndex > 0) {
    tokens.emplace_back(PlaceHolder(pattern.substr(0, oldPlaceHolderIndex)));
  }

  tokens.emplace_back(PlaceHolder());

  auto placeHolderIndex =
      pattern.find(stringRepresentationPlaceHolder, oldPlaceHolderIndex);

  while (placeHolderIndex != std::string::npos) {
    if (placeHolderIndex != 0 && oldPlaceHolderIndex < placeHolderIndex) {
      auto placeHolder = pattern.substr(
          oldPlaceHolderIndex + stringRepresentationPlaceHolder.size(),
          placeHolderIndex - oldPlaceHolderIndex -
              stringRepresentationPlaceHolder.size());

      tokens.emplace_back(PlaceHolder(placeHolder));
      tokens.emplace_back(PlaceHolder());
    }

    oldPlaceHolderIndex = placeHolderIndex;

    placeHolderIndex =
        pattern.find(stringRepresentationPlaceHolder, placeHolderIndex + 1);
  }

  tokens.emplace_back(PlaceHolder(pattern.substr(
      oldPlaceHolderIndex + stringRepresentationPlaceHolder.size())));

  return tokens;
}
} // namespace

namespace Capybara {
namespace Impl {

PlaceHolder::PlaceHolder() : _valueWasSet(false) {}

PlaceHolder::PlaceHolder(std::string value)
    : _valueWasSet(true), _value(std::move(value)) {}

bool PlaceHolder::isValueWasSet() const { return _valueWasSet; }
std::string PlaceHolder::getValue() const {
  if (!_valueWasSet) {
    return StringRepresentationPlaceHolder;
  }

  return _value;
}
void PlaceHolder::setValue(std::string value) {
  _valueWasSet = true;
  _value = std::move(value);
}

std::string tokensToString(const Tokens &tokens) {
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

std::string toString(const char *text) { return std::string(text); }

std::string toString(std::string text) { return text; }

} // namespace Impl

FormattedString::FormattedString(const std::string &pattern)
    : _tokens(parsePattern(pattern)) {}

FormattedString operator""_format(const char *pattern,
                                  const std::size_t /*size*/) {
  return FormattedString(pattern);
}

} // namespace Capybara
