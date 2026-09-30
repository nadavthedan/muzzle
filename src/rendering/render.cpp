#include <ftxui/dom/elements.hpp>
#include <muzzle/render.hpp>

using namespace ftxui;

namespace muzzle {

Element Overview() {
  return vbox({
             text("GETTING STARTED") | bold | center,
             separator(),
         }) |
         flex;
}

} // namespace muzzle
