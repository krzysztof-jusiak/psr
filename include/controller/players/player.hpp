#pragma once

namespace psr::inline v1 {
enum class options { Paper, Scissors, Rock, Unknown };
struct player {
  options selection{};
  std::size_t points{};
};
} // namespace psr::inline v1
