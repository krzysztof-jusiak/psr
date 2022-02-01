#pragma once

#include "controller/states/rounds.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto already_won =
    [](const rounds &rounds, const TPlayers &...players) {
      return (rounds.done(players.points()) or ...);
    };

} // namespace psr::inline v1
