#include <boost-ext/ut.hpp>
#include <fakeit.hpp>

#include "controller/players/human.hpp"
#include "view/iview.hpp"

int main() {
  using namespace boost::ut;

  "human"_test = [] {
    fakeit::Mock<psr::iview> view{};

    psr::human<42u> h{view.get()};
    expect(constant<42_u == h.id>);
    expect(0_u == h.points());

    fakeit::When(Method(view, get_character)).Return(0);
    h.make_selection();
    expect(psr::options::Unknown == h.selection());

    fakeit::When(Method(view, get_character)).Return('p');
    h.make_selection();
    expect(psr::options::Paper == h.selection());

    fakeit::When(Method(view, get_character)).Return('r');
    h.make_selection();
    expect(psr::options::Rock == h.selection());

    fakeit::When(Method(view, get_character)).Return('s');
    h.make_selection();
    expect(psr::options::Scissors == h.selection());
  };
}
