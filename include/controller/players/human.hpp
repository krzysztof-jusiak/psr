#pragma once

#include <boost-ext/sml.hpp>
#include <cassert>

#include "controller/players/player.hpp"
#include "view/iview.hpp"

namespace psr::inline v1 {
template <auto Id> class human {
public:
  constexpr explicit(true) human(iview &view) : view_{view} {}

  constexpr auto make_selection() -> options {
    return player_.selection = [&] {
      switch (view_.get_character()) {
      default:
        assert("Unknown selection!");
        return options::Unknown;
      case 'p':
        return options::Paper;
      case 's':
        return options::Scissors;
      case 'r':
        return options::Rock;
      }
    }();
  }

  static constexpr auto id = Id;
  constexpr auto name() const { return player_.name; }
  constexpr const auto &selection() const { return player_.selection; }
  constexpr const auto &points() const { return player_.points; }
  constexpr auto &points() { return player_.points; }

private:
  iview &view_;
  player player_{.name = boost::sml::aux::get_type_name<human<Id>>()};
};
} // namespace psr::inline v1
