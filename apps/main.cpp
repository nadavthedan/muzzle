#include <muzzle/render.hpp>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

int main(int argc, char *argv[]) {
  auto document = muzzle::Overview();

  // Create a screen with full width and height fitting the document.
  auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(),       // Width
                                      ftxui::Dimension::Fit(document) // Height
  );

  // Render the document onto the screen.
  ftxui::Render(screen, document);

  // Print the screen to the console.
  screen.Print();
}
