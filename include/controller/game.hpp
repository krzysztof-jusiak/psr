#pragma once

#include <cassert>

#include <boost-ext/sml.hpp>

#include "controller/actions/add_points.hpp"
#include "controller/actions/make_selection.hpp"
#include "controller/actions/next_player.hpp"
#include "controller/actions/next_round.hpp"
#include "controller/actions/reset_model.hpp"
#include "controller/actions/reset_player.hpp"
#include "controller/actions/set_rounds.hpp"
#include "controller/actions/show_points.hpp"
#include "controller/actions/show_results.hpp"
#include "controller/actions/show_winner.hpp"
#include "controller/actions/update_model.hpp"
#include "controller/events/play.hpp"
#include "controller/events/select.hpp"
#include "controller/events/shoot.hpp"
#include "controller/guards/already_won.hpp"
#include "controller/guards/has_inc_ids.hpp"
#include "controller/guards/has_winner.hpp"
#include "controller/guards/is_current.hpp"
#include "controller/guards/is_last.hpp"
#include "controller/guards/out_of_rounds.hpp"

namespace psr::inline v1 {
template <class... TPlayers> struct game {
  constexpr auto operator()() const {
    assert(has_inc_ids<TPlayers::id...>());

    using namespace boost::sml;
    using namespace events;
    // clang-format off
    return make_transition_table(
      *"idle"_s      + event<play>                                 / (set_rounds)                 = "select"_s,
      ("select"_s    + event<select> [is_current<TPlayers>]        / (make_selection<TPlayers>,
                                                                      next_player))...,
      "select"_s     + event<select> [is_last<TPlayers...>]        / (update_model<TPlayers...>)  = "shoot"_s,
      "shoot"_s      + event<shoot>  [has_winner]                  / (show_results<TPlayers...>,
                                                                      show_winner<TPlayers...>,
                                                                      add_points<TPlayers...>,
                                                                      next_round)                 = "game over?"_s,
      "shoot"_s      + event<shoot>                                / (show_results<TPlayers...>,
                                                                      next_round)                 = "game over?"_s,
      "game over?"_s + event<play>   [out_of_rounds or
                                      already_won<TPlayers...>]    / (show_points<TPlayers...>)   = X,
      "game over?"_s + event<play>                                 / (show_points<TPlayers...>,
                                                                      reset_player,
                                                                      reset_model)                = "select"_s
    );
    // clang-format on
  }
};
} // namespace psr::inline v1
