#pragma once

#include "controller/states/rounds.hpp"
#include "view/iview.hpp"

namespace psr::inline v1 {
constexpr auto set_rounds = [](iview &view, rounds &rounds) {
  view.show_rounds();
  rounds.max = view.get_number();
};
} // namespace psr::inline v1
