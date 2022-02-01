#pragma once

#include "controller/states/rounds.hpp"

namespace psr::inline v1 {
constexpr auto out_of_rounds = [](const rounds &rounds) {
  return rounds.current >= rounds.max;
};
} // namespace psr::inline v1
