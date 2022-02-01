#include <boost-ext/di.hpp>
#include <boost-ext/ut.hpp>
#include <cstdio>
#include <fakeit.hpp>

#include "controller/events/play.hpp"
#include "controller/events/select.hpp"
#include "controller/events/shoot.hpp"
#include "controller/game.hpp"
#include "model/model.hpp"

namespace di = boost::di;

struct fake_logger {
  template <class SM, class TEvent> void log_process_event(const TEvent &) {
    std::printf("[%s][process_event] %s\n",
                boost::sml::aux::get_type_name<SM>(),
                boost::sml::aux::get_type_name<TEvent>());
  }

  template <class SM, class TGuard, class TEvent>
  void log_guard(const TGuard &, const TEvent &, bool result) {
    std::printf("[%s][guard] %s %s %s\n", boost::sml::aux::get_type_name<SM>(),
                boost::sml::aux::get_type_name<TGuard>(),
                boost::sml::aux::get_type_name<TEvent>(),
                (result ? "[OK]" : "[Reject]"));
  }

  template <class SM, class TAction, class TEvent>
  void log_action(const TAction &, const TEvent &) {
    std::printf("[%s][action] %s %s\n", boost::sml::aux::get_type_name<SM>(),
                boost::sml::aux::get_type_name<TAction>(),
                boost::sml::aux::get_type_name<TEvent>());
  }

  template <class SM, class TSrcState, class TDstState>
  void log_state_change(const TSrcState &src, const TDstState &dst) {
    std::printf("[%s][transition] %s -> %s\n",
                boost::sml::aux::get_type_name<SM>(), src.c_str(), dst.c_str());
  }
};

template <auto Id> struct fake_player {
  auto make_selection() -> psr::options { return player.selection; }

  static constexpr auto id = Id;
  constexpr const auto &selection() const { return player.selection; }
  constexpr const auto &points() const { return player.points; }
  constexpr auto &points() { return player.points; }

  psr::player player{};
};

int main() {
  using namespace boost::ut;
  using namespace boost::ut::bdd;

  // clang-format off
  feature("Paper Rock Scissors") = [] {
    scenario("Win/Tie") = [] {
      given("I have a game") = [] {
        fakeit::Mock<psr::iview> view{};
        fake_player<0> player0{};
        fake_player<1> player1{};
        fake_logger logger{};

        auto injector = boost::di::make_injector(
            boost::di::bind<psr::imodel>.to<psr::model<2>>(),
            boost::di::bind<psr::iview>.to(view.get()),
            boost::di::bind<fake_player<0>>.to(player0),
            boost::di::bind<fake_player<1>>.to(player1),
            boost::di::bind<fake_logger>.to(logger)
        );

        using game_t = psr::game<fake_player<0>, fake_player<1>>;

        auto game = boost::di::create<
          boost::sml::sm<game_t, boost::sml::logger<fake_logger>>>(injector);

        when("I play 2 rounds");
          fakeit::Fake(Method(view, show_rounds));
          fakeit::When(Method(view, get_number)).Return(2);

          game.process_event(psr::events::play{});

        when("I select");
          player0.player.selection = psr::options::Paper;
          player1.player.selection = psr::options::Scissors;
          fakeit::Fake(Method(view, show_selection));

          game.process_event(psr::events::select{});
          game.process_event(psr::events::select{});
          game.process_event(psr::events::select{});

        when("I shoot");
          fakeit::Fake(Method(view, show_results));
          fakeit::Fake(Method(view, show_winner));
          game.process_event(psr::events::shoot{});

        when("I play");
          fakeit::Fake(Method(view, show_score));
          game.process_event(psr::events::play{});

        when("I select");
          player0.player.selection = psr::options::Paper;
          player1.player.selection = psr::options::Paper;
          fakeit::Fake(Method(view, show_selection));

          game.process_event(psr::events::select{});
          game.process_event(psr::events::select{});
          game.process_event(psr::events::select{});

        when("I shoot");
          fakeit::Fake(Method(view, show_results));
          fakeit::Fake(Method(view, show_winner));
          game.process_event(psr::events::shoot{});

          then("I should finish the game");
            fakeit::Fake(Method(view, show_score));
            game.process_event(psr::events::play{});
            expect(game.is(boost::sml::X));
      };
    };
  };
  // clang-format on
}
