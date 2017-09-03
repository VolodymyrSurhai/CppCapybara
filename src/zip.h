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
      using TupleIterator = std::tuple<FirstIterator&, SecondIterator&>;

      Iterator(FirstIterator firstIterator, SecondIterator secondIterator)
          : _firstIterator(std::move(firstIterator))
          , _secondIterator(std::move(secondIterator))
      {
      }

      TupleIterator operator*()
      {
            return makeTuple();
      }

      TupleIterator& operator = (const TupleIterator& other)
      {
          _firstIterator = other.first;
          _secondIterator = other.second;
          return *this;
      }

      bool operator != (const TupleIterator& other)
      {
           return _firstIterator != other.first && _secondIterator != other.second;
      }

      TupleIterator operator ++ ()
      {
          ++_firstIterator;
          ++_secondIterator;
          return makeTuple();
      }

      TupleIterator operator ++ (int)
      {
          auto result = makeTuple();

          ++_firstIterator;
          ++_secondIterator;

          return result;
      }

  private:
      TupleIterator makeTuple()
      {
          return std::tuple<FirstIterator,SecondIterator>(_firstIterator, _secondIterator);
      }


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
