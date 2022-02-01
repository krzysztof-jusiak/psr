#pragma once

#include "model/imodel.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto show_results = [](iview &view, const TPlayers &...players) {
  view.show_results(
      {{boost::sml::aux::get_type_name<TPlayers>(), players.selection()}...});
};
} // namespace psr::inline v1
