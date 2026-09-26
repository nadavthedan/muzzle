#include <muzzle/render.hpp>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

int main(int argc, char *argv[]) {
  auto document = muzzle::Overview();

  auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), // Width
                                      ftxui::Dimension::Full()  // Height
  );

  ftxui::Render(screen, document);

  screen.Print();
}
