#pragma once

#include <ftxui/dom/node.hpp>

namespace muzzle {

// Builds the top-level document that the application renders to the terminal.
// Owning the element tree here keeps the library independent of terminal I/O,
// so callers decide how the result is drawn.
ftxui::Element Overview();

}
