#include "ftxui/component/app.hpp"            // for Component, App
#include "ftxui/component/captured_mouse.hpp" // for ftxui
#include "ftxui/component/component.hpp" // for Menu, Renderer, Horizontal, Vertical
#include "ftxui/component/component_base.hpp" // for ComponentBase
#include "ftxui/dom/elements.hpp" // for text, Element, operator|, window, flex, vbox
#include <memory>                 // for allocator, __shared_ptr_access
#include <stdlib.h>               // for EXIT_SUCCESS
#include <string> // for string, operator+, basic_string, to_string, char_traits
#include <vector> // for vector, __alloc_traits<>::value_type

using namespace ftxui;

Component Window(std::string title, Component component) {
  return Renderer(component, [component, title] { //
    return window(text(title), component->Render()) | flex;
  });
}

int main() {
  int selected_packet = 0;
  std::vector<std::string> menu_entries = {
      "0.124: 3472 bytes",
      "0.239: 120 bytes",
      "0.323: 23 bytes",
      // "0.336: 1237 bytes", "1.126: 124 bytes",  "0.124: 3472 bytes",
      // "0.239: 120 bytes",  "0.323: 23 bytes",   "0.336: 1237 bytes",
      // "1.126: 124 bytes",  "0.124: 3472 bytes", "0.239: 120 bytes",
  };

  auto packets_menu = Menu(&menu_entries, &selected_packet);
  auto packets_render = Renderer(packets_menu, [&] {
    return packets_menu->Render() | vscroll_indicator | frame |
           size(HEIGHT, LESS_THAN, 60) | border;
  });

  auto info = Renderer([&] {
    std::string value = menu_entries[selected_packet];
    return window(text("Content"), //
                  vbox({
                      text("menu_selected[0]     = " +
                           std::to_string(selected_packet)),
                      text("Value                = " + value),
                  })) |
           flex;
  });

  auto global = Container::Horizontal({
      packets_render,
      info,
  });

  auto screen = App::Fullscreen();
  screen.Loop(global);
  return EXIT_SUCCESS;
}
