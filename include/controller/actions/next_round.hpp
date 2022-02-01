#pragma once

#include "controller/states/rounds.hpp"

namespace psr::inline v1 {
constexpr auto next_round = [](rounds &rounds) { ++rounds.current; };
} // namespace psr::inline v1
