#pragma once

#include "model/imodel.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto update_model = [](imodel &model, const TPlayers &...players) {
  (model.update(players.id, players.selection()), ...);
};
} // namespace psr::inline v1
