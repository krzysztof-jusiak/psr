#pragma once

#include <optional>

#include "controller/players/player.hpp"

namespace psr::inline v1 {
class imodel {
public:
  virtual ~imodel() noexcept = default;
  virtual auto update(id_t id, options selection) -> void = 0;
  [[nodiscard]] virtual auto winner() const -> std::optional<id_t> = 0;
  virtual auto reset() -> void = 0;
};
} // namespace psr::inline v1
