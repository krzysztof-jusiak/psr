#pragma once

#include <string>

namespace psr::inline v1 {
enum class options { Paper, Scissors, Rock, Unknown };
struct player {
  std::string name{};
  options selection{};
  std::size_t points{};
};
} // namespace psr::inline v1
