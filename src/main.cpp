#include <boost-ext/di.hpp>
#include <boost-ext/sml.hpp>

#include "controller/events/play.hpp"
#include "controller/events/select.hpp"
#include "controller/events/shoot.hpp"
#include "controller/game.hpp"
#include "controller/players/computer.hpp"
#include "controller/players/human.hpp"
#include "model/model.hpp"
#include "view/view.hpp"

int main() {
  // clang-format off
  static constexpr auto players_size = 2;

  auto injector = boost::di::make_injector(
    boost::di::bind<psr::imodel>.to<psr::model<players_size>>(),
    boost::di::bind<psr::iview>.to<psr::view>()
  );

  /**
   * human vs human       - psr::human<0>,    psr::human<1>
   * computer vs computer - psr::computer<0>, psr::computer<1>
   * human first          - psr::human<0>,    psr::computer<1>
   * computer first       - psr::computer<0>, psr::human<1>
   */
  using game_t = psr::game<
    psr::human<0>,
    psr::computer<1>
  >;

  auto game = boost::di::create<
    boost::sml::sm<game_t>
  >(injector);
  // clang-format on

  while (not game.is(boost::sml::X)) {
    game.process_event(psr::events::play{});
    game.process_event(psr::events::select{});
    game.process_event(psr::events::shoot{});
  }
}
