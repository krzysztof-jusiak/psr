#pragma once

#include "model/imodel.hpp"

namespace psr::inline v1 {
constexpr auto reset_model = [](imodel &model) { model.reset(); };
} // namespace psr::inline v1
