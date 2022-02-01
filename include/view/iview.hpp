#pragma once

#include <string>
#include <vector>

#include "controller/players/player.hpp"

namespace psr::inline v1 {
class iview {
public:
  virtual ~iview() noexcept = default;
  virtual auto show_rounds() -> void = 0;
  virtual auto show_selection(const std::string &) -> void = 0;
  virtual auto
  show_results(const std::vector<std::pair<std::string, options>> &)
      -> void = 0;
  virtual auto show_winner(const std::string &) -> void = 0;
  virtual auto
  show_score(const std::vector<std::pair<std::string, std::size_t>> &)
      -> void = 0;

  [[nodiscard]] virtual auto get_number() -> std::size_t = 0;
  [[nodiscard]] virtual auto get_character() -> char = 0;
};

} // namespace psr::inline v1
