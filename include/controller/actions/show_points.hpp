#pragma once

#include "view/iview.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto show_points = [](iview &view, const TPlayers &...players) {
  view.show_score(
      {{boost::sml::aux::get_type_name<TPlayers>(), players.points()}...});
};
} // namespace psr::inline v1
