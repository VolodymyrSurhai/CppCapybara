#pragma once

#include <iterator>
#include <utility>

namespace Capybara {

template <typename FirstIterator, typename SecondIterator>
class Iterator final {

public:
  using PairIterator = std::pair<FirstIterator, SecondIterator>;

  Iterator(FirstIterator firstIterator, SecondIterator secondIterator)
      : _iterators(std::move(firstIterator), std::move(secondIterator)) {}

  Iterator(PairIterator &&other) : _iterators(std::move(other._iterators)) {}

  PairIterator operator*() { return _iterators; }

  PairIterator &operator=(const Iterator &other) {
    _iterators = other._iterators;
    return *this;
  }

  bool operator!=(const Iterator &other) {
    return _iterators.first != other._iterators.first &&
           _iterators.second != other._iterators.second;
  }

  PairIterator &operator++() {
    ++_iterators.first;
    ++_iterators.second;
    return _iterators;
  }

  PairIterator &operator++(int) {
    auto result = _iterators;

    ++_iterators.first;
    ++_iterators.second;

    return result;
  }

private:
  PairIterator _iterators;
};

template <typename FirstContainer, typename SecondContainer>
class IterablePair {
public:
  using FirstIterator = typename FirstContainer::iterator;
  using SecondIterator = typename SecondContainer::iterator;

  using FirstValueType = typename FirstContainer::value_type;
  using SecondValueType = typename SecondContainer::value_type;
  using PairValue = std::pair<FirstValueType, SecondValueType>;

  using LocalIterator = Iterator<FirstIterator, SecondIterator>;

  IterablePair(FirstContainer firstContainer, SecondContainer secondContainer)
      : _firstContainer(firstContainer), _secondContainer(secondContainer) {}

  IterablePair(const IterablePair &other)
      : _firstContainer(other._firstContainer),
        _secondContainer(other._secondContainer) {}

  LocalIterator begin() {
    return LocalIterator(std::begin(_firstContainer),
                         std::begin(_secondContainer));
  }

  LocalIterator end() {
    return LocalIterator(std::end(_firstContainer), std::end(_secondContainer));
  }

private:
  FirstContainer _firstContainer;
  SecondContainer _secondContainer;
};

template <typename FirstContainer, typename SecondContainer>
IterablePair<FirstContainer, SecondContainer>
zip(FirstContainer firstContainer, SecondContainer secondContainer) {
  return IterablePair<FirstContainer, SecondContainer>(firstContainer,
                                                       secondContainer);
}
} // namespace Capybara
