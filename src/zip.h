#pragma once

#include <iterator>

namespace Capybara {

template <typename FirstContainer, typename SecondContainer>
class IterablePair {
public:
  using FirstIterator = typename FirstContainer::iterator;
  using SecondIterator = typename SecondContainer::iterator;
  using PairIterator = std::pair<FirstIterator, SecondIterator>;

  using FirstValueType = typename FirstContainer::value_type;
  using SecondValueType = typename SecondContainer::value_type;
  using PairValue = std::pair<FirstValueType, SecondValueType>;

  class Iterator final {

  public:
    Iterator(FirstIterator firstIterator, SecondIterator secondIterator)
        : _firstIterator(std::move(firstIterator)),
          _secondIterator(std::move(secondIterator)) {}

    Iterator(PairIterator &&other)
        : _firstIterator(std::move(other._firstIterator)),
          _secondIterator(std::move(other._secondIterator)) {}

    PairValue operator*() {
      return PairValue(*_firstIterator, *_secondIterator);
    }

    PairIterator &operator=(const Iterator &other) {
      _firstIterator = other.first;
      _secondIterator = other.second;
      return *this;
    }

    bool operator!=(const Iterator &other) {
      return _firstIterator != other._firstIterator &&
             _secondIterator != other._secondIterator;
    }

    PairIterator operator++() {
      ++_firstIterator;
      ++_secondIterator;
      return makePair();
    }

    PairIterator operator++(int) {
      auto result = makePair();

      ++_firstIterator;
      ++_secondIterator;

      return result;
    }

  private:
    PairIterator makePair() {
      return PairIterator(_firstIterator, _secondIterator);
    }

    FirstIterator _firstIterator;
    SecondIterator _secondIterator;
  };

  IterablePair(FirstContainer firstContainer, SecondContainer secondContainer)
      : _firstContainer(firstContainer), _secondContainer(secondContainer) {}

  IterablePair(const IterablePair &other)
      : _firstContainer(other._firstContainer),
        _secondContainer(other._secondContainer) {}

  Iterator begin() {
    return Iterator(std::begin(_firstContainer), std::begin(_secondContainer));
  }

  Iterator end() {
    return Iterator(std::end(_firstContainer), std::end(_secondContainer));
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
