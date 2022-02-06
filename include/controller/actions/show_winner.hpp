#pragma once

#include <array>
#include <cassert>
#include <string>

#include "model/imodel.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto show_winner = [](const imodel &model, iview &view,
                                const TPlayers &...players) {
  assert(model.winner().has_value());
  view.show_winner(std::array{players.name()...}[*model.winner()]);
};
} // namespace psr::inline v1
