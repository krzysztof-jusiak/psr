#pragma once

#include "controller/players/player.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto is_last =
    [](const id_t &next) { return next >= sizeof...(TPlayers); };
} // namespace psr::inline v1
