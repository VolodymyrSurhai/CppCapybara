#pragma once

#include <vector>
#include <iterator>

namespace Capybara {
template <typename Container> struct ReversedContainer {
  ReversedContainer(Container container) : _container(container) {}

  std::reverse_iterator<typename Container::iterator> begin() {
    return _container.rbegin();
  }

  std::reverse_iterator<typename Container::const_iterator> begin() const {
    return _container.rbegin();
  }

  std::reverse_iterator<typename Container::iterator> end() {
    return _container.rend();
  }

  std::reverse_iterator<typename Container::const_iterator> end() const {
    return _container.rend();
  }

private:
  Container _container;
};

template <typename Container>
ReversedContainer<Container> reversed(Container container) {
  return ReversedContainer<Container>(container);
}
} // namespace Capybara
