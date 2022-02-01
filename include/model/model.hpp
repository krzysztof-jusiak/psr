#pragma once

#include <array>
#include <cassert>
#include <optional>
#include <vector>

#include "controller/players/player.hpp"
#include "model/imodel.hpp"

namespace psr::inline v1 {
template <auto> class model;
template <> class model<2> final : public imodel {
public:
  auto update(id_t id, options selection) -> void override {
    data_.push_back({id, selection});
    assert(std::size(data_) <= 2);
  }

  [[nodiscard]] auto winner() const -> std::optional<id_t> override {
    assert(std::size(data_) == 2);

    // clang-format off
    const auto &[id0, option0] = data_[0];
    const auto &[id1, option1] = data_[1];
    const auto win0 = rules[static_cast<std::size_t>(option1)][static_cast<std::size_t>(option0)];
    const auto win1 = rules[static_cast<std::size_t>(option0)][static_cast<std::size_t>(option1)];

    return win0 ? std::optional{id0}
         : win1 ? std::optional{id1}
                : std::optional<id_t>{};
    // clang-format oon
  }

  auto reset() -> void override {
    data_ = {};
  }

private:
  // clang-format off
  static constexpr std::array<std::array<bool, 3>, 3> rules = {
    //         paper  scissors rock
    std::array{false, true,    false}, // paper
    std::array{false, false,   true},  // scissors
    std::array{true,  false,   false}  // rock
  };
  // clang-format on
  std::vector<std::pair<id_t, options>> data_{};
};
} // namespace psr::inline v1
