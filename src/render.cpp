#include <muzzle/render.hpp>

#include <ftxui/dom/elements.hpp>

namespace muzzle {

// Create a simple document with three text elements.
ftxui::Element Overview() {
  return ftxui::hbox({
      ftxui::text("left") | ftxui::border,
      ftxui::text("middle") | ftxui::border | ftxui::flex,
      ftxui::text("right") | ftxui::border,
  });
}

}
