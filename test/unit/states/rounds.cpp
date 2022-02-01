#include <boost-ext/ut.hpp>

#include "controller/states/rounds.hpp"

int main() {
  using namespace boost::ut;

  "rounds"_test = [] {
    "out of 1"_test = [] {
      psr::rounds r{{}, 1u};
      expect(not r.done(0u));
      expect(r.done(1u));
    };

    "out of 4"_test = [] {
      psr::rounds r{{}, 4u};
      expect(not r.done(0u));
      expect(not r.done(1u));
      expect(not r.done(2u));
      expect(r.done(3u));
      expect(r.done(4u));
    };
  };
}
