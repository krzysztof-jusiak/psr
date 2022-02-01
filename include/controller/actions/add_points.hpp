#pragma once

#include <array>
#include <cassert>

#include "model/imodel.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto add_points = [](const imodel &model, TPlayers &...players) {
  assert(model.winner().has_value());
  const auto points = std::array{&players.points()...};
  ++*points[*model.winner()];
};
} // namespace psr::inline v1
