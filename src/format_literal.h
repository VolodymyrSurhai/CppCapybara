#pragma once

#include <vector>
#include <string>

namespace Capybara {
namespace Impl {

class PlaceHolder {
public:
  PlaceHolder();
  explicit PlaceHolder(const std::string &value);

  bool isValueWasSet() const;
  std::string getValue() const;
  void setValue(std::string value);

private:
  bool _valueWasSet;
  std::string _value;
};

using Tokens = std::vector<PlaceHolder>;
std::string tokensToString(const Tokens &tokens);

std::string toString(const char *text);

std::string toString(std::string text);

template <typename T,
          typename = std::enable_if<!std::is_same<std::string, T>::value ||
                                    !std::is_same<const char *, T>::value>>
std::string toString(T item) {
  return std::to_string(item);
}

template <class T>
Tokens::iterator fillTokens(Tokens::iterator iterator,
                            const Tokens::iterator end,
                            const std::size_t argIndex, const T arg) {
  while (iterator < end) {
        if (!iterator->isValueWasSet()) {
          iterator->setValue(toString(arg));
          break;
        }
    ++iterator;
  }

  return iterator;
}

template <typename T, typename... Args>
Tokens::iterator
fillTokens(Tokens::iterator iterator, const Tokens::iterator end,
           const std::size_t argIndex, const T arg, Args... args) {
  while (iterator != end) {
    if (!iterator->isValueWasSet() ) {
        iterator->setValue(toString(arg));
      iterator = fillTokens(++iterator, end, argIndex + 1, args...);
      break;
    }
    ++iterator;
  }

  return iterator;
}
} // namespace Impl

class FormattedString {
public:
  using Tokens = Impl::Tokens;

  FormattedString(const std::string &pattern);

  template <typename... Args> std::string operator()(Args... args) const {
    Tokens result(_tokens);

    fillTokens(result.begin(), result.end(), 0, args...);

    return tokensToString(result);
  }

private:
  const Tokens _tokens;
};

FormattedString operator""_format(const char *pattern, std::size_t);

} // namespace Capybara
