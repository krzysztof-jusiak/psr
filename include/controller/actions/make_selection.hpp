#pragma once

#include <boost-ext/sml.hpp>
#include <cassert>

#include "view/iview.hpp"

namespace psr::inline v1 {
template <class TPlayer>
constexpr auto make_selection = [](iview &view, TPlayer &player) {
  view.show_selection(boost::sml::aux::get_type_name<TPlayer>());
  [[maybe_unused]] const auto selection = player.make_selection();
  assert(selection != options::Unknown);
};
} // namespace psr::inline v1
