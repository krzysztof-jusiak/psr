#include <boost-ext/ut.hpp>

#include "controller/guards/has_inc_ids.hpp"

int main() {
  using namespace boost::ut;

  "guard - has_inc_ids"_test = [] {
    expect(psr::has_inc_ids<0>());
    expect(psr::has_inc_ids<0, 1>());
    expect(psr::has_inc_ids<0, 1, 2>());
    expect(psr::has_inc_ids<0, 1, 2, 3>());

    expect(not psr::has_inc_ids<1, 0>());
    expect(not psr::has_inc_ids<0, 2>());
    expect(not psr::has_inc_ids<0, 2, 3>());
    expect(not psr::has_inc_ids<0, 1, 42>());
    expect(not psr::has_inc_ids<0, 2, 1>());
  };
}
