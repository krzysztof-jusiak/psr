#pragma once

namespace psr::inline v1 {
template <class TPlayer>
constexpr auto is_current =
    [](const id_t &next, const TPlayer &player) { return next == player.id; };
} // namespace psr::inline v1
