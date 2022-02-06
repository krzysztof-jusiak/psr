#pragma once

#include <boost-ext/sml.hpp>
#include <random>

#include "controller/players/player.hpp"

namespace psr::inline v1 {
template <auto Id> class computer {
public:
  auto make_selection() -> options {
    std::random_device rd{};
    std::default_random_engine re{rd()};
    std::uniform_int_distribution<std::size_t> uniform_dist(
        0, static_cast<std::size_t>(options::Unknown) - 1);
    return player_.selection = static_cast<options>(uniform_dist(re));
  }

  static constexpr auto id = Id;
  constexpr auto name() const { return player_.name; }
  constexpr const auto &selection() const { return player_.selection; }
  constexpr const auto &points() const { return player_.points; }
  constexpr auto &points() { return player_.points; }

private:
  player player_{.name = boost::sml::aux::get_type_name<computer<Id>>()};
};
} // namespace psr::inline v1
