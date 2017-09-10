#pragma once

#include <iterator>

namespace std {
template <class C>
constexpr auto cbegin(const C &c) noexcept -> decltype(std::begin(c)) {
  return c.cbegin();
}

template <class C>
constexpr auto cend(const C &c) noexcept -> decltype(std::end(c)) {
  return c.cend();
}

} // namespace std
