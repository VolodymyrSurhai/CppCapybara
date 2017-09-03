#pragma once

#include <tuple>

namespace Capybara {

template <typename FirstContainer, typename SecondContainer>
class IterablePair {
public:
  class Iterator {
  public:
      using FirstIterator = typename FirstContainer::iterator;
      using SecondIterator = typename SecondContainer::iterator;

      Iterator(FirstIterator firstIterator, SecondIterator secondIterator)
          : _firstIterator(std::move(firstIterator))
          , _secondIterator(std::move(secondIterator))
      {
      }

      std::tuple<typename FirstContainer::value_type, typename SecondContainer::value_type> operator*()
      {
            return std::make_tuple(*_firstIterator, *_secondIterator);
      }

      std::tuple<FirstIterator, SecondIterator>& operator = (const std::tuple< FirstIterator, SecondIterator>& other)
      {
          _firstIterator = other.first;
          _secondIterator = other.second;
          return *this;
      }

      bool operator != (const std::tuple<FirstIterator, SecondIterator>& other)
      {
           return _firstIterator != other.first && _secondIterator != other.second;
      }

  private:
    FirstIterator _firstIterator;
    SecondIterator _secondIterator;
  };

  IterablePair(FirstContainer firstContainer, SecondContainer secondContainer)
      : _firstContainer(firstContainer)
      , _secondContainer(secondContainer)
  {
  }

  Iterator begin() {
      return IterablePair(std::begin(_firstContainer), std::begin(_secondContainer));
  }

  Iterator end() {
      return IterablePair(std::end(_firstContainer), std::end(_secondContainer));
  }

private:
  FirstContainer _firstContainer;
  SecondContainer _secondContainer;
};

template <typename FirstContainer, typename SecondContainer>
IterablePair<FirstContainer, SecondContainer>
zip(FirstContainer firstContainer, SecondContainer secondContainer) {
  return IterablePair<FirstContainer, SecondContainer>(
      std::move(firstContainer), std::move(secondContainer));
}

} // namespace Capybara
