#include <boost-ext/ut.hpp>

#include "controller/players/player.hpp"
#include "model/model.hpp"

int main() {
  using namespace boost::ut;

  "model"_test = [] {
    psr::model<2> m{};

    "tie"_test = [=] {
      mut(m).update(0, psr::options::Paper);
      mut(m).update(1, psr::options::Paper);
      expect(not m.winner().has_value());
    };

    "paper beats (wraps) rock"_test = [m] {
      mut(m).update(0, psr::options::Paper);
      mut(m).update(1, psr::options::Rock);
      expect(m.winner().has_value());
      expect(0 == m.winner());
    };

    "paper beats (wraps) rock"_test = [m] {
      mut(m).update(0, psr::options::Rock);
      mut(m).update(1, psr::options::Paper);
      expect(m.winner().has_value());
      expect(1 == m.winner());
    };

    "rock beats (blunts) scissors"_test = [m] {
      mut(m).update(0, psr::options::Rock);
      mut(m).update(1, psr::options::Scissors);
      expect(m.winner().has_value());
      expect(0 == m.winner());
    };

    "rock beats (blunts) scissors"_test = [m] {
      mut(m).update(0, psr::options::Scissors);
      mut(m).update(1, psr::options::Rock);
      expect(m.winner().has_value());
      expect(1 == m.winner());
    };

    "scissors beats (cuts) Paper"_test = [m] {
      mut(m).update(0, psr::options::Scissors);
      mut(m).update(1, psr::options::Paper);
      expect(m.winner().has_value());
      expect(0 == m.winner());
    };

    "scissors beats (cuts) Paper"_test = [m] {
      mut(m).update(0, psr::options::Paper);
      mut(m).update(1, psr::options::Scissors);
      expect(m.winner().has_value());
      expect(1 == m.winner());
    };
  };
}
