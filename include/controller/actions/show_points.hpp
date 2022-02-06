#pragma once

#include "view/iview.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto show_points = [](iview &view, const TPlayers &...players) {
  view.show_score({{players.name(), players.points()}...});
};
} // namespace psr::inline v1
