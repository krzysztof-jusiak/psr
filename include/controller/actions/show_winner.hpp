#pragma once

#include <array>
#include <cassert>
#include <string>

#include "model/imodel.hpp"

namespace psr::inline v1 {
template <class... TPlayers>
constexpr auto show_winner =
    [](const imodel &model, iview &view, const TPlayers &...) {
      assert(model.winner().has_value());
      view.show_winner(std::string{std::array{
          boost::sml::aux::get_type_name<TPlayers>()...}[*model.winner()]});
    };
} // namespace psr::inline v1
