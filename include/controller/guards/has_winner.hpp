#pragma once

#include "model/imodel.hpp"

namespace psr::inline v1 {
constexpr auto has_winner = [](const imodel &model) {
  return static_cast<bool>(model.winner());
};
} // namespace psr::inline v1
