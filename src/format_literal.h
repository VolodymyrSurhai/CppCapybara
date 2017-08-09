#pragma once

#include <vector>
#include <iterator>
#include <string>
#include <tuple>

namespace Capybara {

class FormattedString {
public:
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
  static std::string tokensToString(const Tokens &tokens);

  FormattedString(const std::string &pattern);

  template <class T>
  void fill(Tokens::iterator iterator, Tokens::iterator end,
            std::size_t argsIndex, T arg) {
    if (iterator == end) {
      return;
    }

    if (!iterator->isValueWasSet()) {
      iterator->setValue(std::to_string(arg));
    }
  }

  template <typename T, typename... Args>
  void fill(Tokens::iterator iterator, Tokens::iterator end,
            std::size_t argsIndex, T arg, Args... args) {
    if (iterator == end) {
      return;
    }

    if (!iterator->isValueWasSet()) {
      iterator->setValue(std::to_string(arg));
      fill(++iterator, end, argsIndex + 1, args...);
    }
  }

  template <typename... Args> std::string operator()(Args... args) const {
    Tokens result(_tokens);

    fill(result.begin(), result.end(), 0, args...);

    return tokensToString(result);
  }

private:
  const Tokens _tokens;
};

FormattedString operator""_format(const char *pattern, std::size_t);

} // namespace Capybara
