#pragma once

#include <tuple>

namespace Capybara {

template <typename FirstContainer, typename SecondContainer>
class IterablePair {
public:
  class Iterator {
  public:
      Iterator()
      {

      }

  private:

  };

  IterablePair(FirstContainer firstContainer, SecondContainer secondContainer) {

  }

  Iterator begin() {}

  Iterator end() {}

private:
};

template <typename FirstContainer, typename SecondContainer> class ZipWrapper {
public:



  ZipWrapper(FirstContainer firstContainer, SecondContainer secondContainer)
      : _iterablePair(std::move(firstContainer), std::move(secondContainer)) {}

  IterablePair begin() {
    return _iterablePair.begin();
  }


  IterablePair end() {
    return _iterablePair.end();
  }

private:
  IterablePair _iterablePair;
};

template <typename FirstContainer, typename SecondContainer>
ZipWrapper<FirstContainer, SecondContainer>
zip(FirstContainer firstContainer, SecondContainer secondContainer) {
  return ZipWrapper<FirstContainer, SecondContainer>(
      std::move(firstContainer), std::move(secondContainer));
}

} // namespace Capybara
