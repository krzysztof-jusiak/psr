#pragma once

namespace psr::inline v1 {
struct rounds {
  std::size_t current{};
  std::size_t max{};

  [[nodiscard]] constexpr auto done(auto points) const -> bool {
    return points > max / 2;
  }
};
} // namespace psr::inline v1
