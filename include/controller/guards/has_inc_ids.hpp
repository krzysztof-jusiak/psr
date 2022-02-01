#pragma once

#include <algorithm>
#include <array>

namespace psr::inline v1 {
template <auto... Ids>
constexpr auto has_inc_ids = [] {
  std::array ids{Ids...};
  return std::cend(ids) ==
         std::adjacent_find(
             std::cbegin(ids), std::cend(ids),
             [](const auto &lhs, const auto &rhs) { return rhs - lhs != 1; });
};
} // namespace psr::inline v1
