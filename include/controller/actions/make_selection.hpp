#pragma once

#include <cassert>

#include "view/iview.hpp"

namespace psr::inline v1 {
template <class TPlayer>
constexpr auto make_selection = [](iview &view, TPlayer &player) {
  view.show_selection(player.name());
  [[maybe_unused]] const auto selection = player.make_selection();
  assert(selection != options::Unknown);
};
} // namespace psr::inline v1
