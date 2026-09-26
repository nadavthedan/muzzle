#include <ftxui/dom/elements.hpp>
#include <muzzle/render.hpp>

using namespace ftxui;

namespace muzzle {

Element Overview() {
  return vbox({
             text("GETTING STARTED") | bold | center,
             separator(),
             hbox({
                 text("left pannel") | border,
                 vbox({
                     text("Main Content Area") | flex,
                     separator(),
                     text("Footer Information") | dim,
                 }) | border |
                     flex,
             }) | border |
                 flex,
         }) |
         flex;
}

} // namespace muzzle
