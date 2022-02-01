#pragma once

#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "controller/players/player.hpp"
#include "view/iview.hpp"

namespace psr::inline v1 {
class view final : public iview {
  auto show_rounds() -> void override { show("[game] How many rounds?\n"); }

  auto show_selection(const std::string &player) -> void override {
    show("[%s] What's your selection [psr]?\n", player.c_str());
  }

  auto show_results(const std::vector<std::pair<std::string, options>> &results)
      -> void override {
    for (const auto &[player, option] : results) {
      show("[game] %s %s\n", player.c_str(), [option = option] {
        switch (option) {
        default:
          return "Unknown";
        case options::Paper:
          return "Paper";
        case options::Scissors:
          return "Scissors";
        case options::Rock:
          return "Rock";
        }
      }());
    }
  }

  auto show_winner(const std::string &player) -> void override {
    show("[game] Winner is %s\n", player.c_str());
  }

  auto
  show_score(const std::vector<std::pair<std::string, std::size_t>> &scores)
      -> void override {
    show("[game] Score:");
    for (const auto &[player, score] : scores) {
      show(" %s:%d", player.c_str(), score);
    }
    show("\n\n");
  }

  [[nodiscard]] auto get_number() -> std::size_t override {
    std::size_t option;
    std::cin >> option;
    return option;
  }

  [[nodiscard]] auto get_character() -> char override {
    char option;
    std::cin >> option;
    return option;
  }

private:
  auto show(const char *format, ...) -> void {
    va_list args{};
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
  }
};
} // namespace psr::inline v1
