#include "demo_functions.hpp"

int main() {

  TStyle::TerStyledText formatter{};

  std::cout << formatter.WithText("Foreground Color")
  .WithFgColor(TStyle::Colors::Green)
  << std::endl;
//  ShowBasicFgColors();
//  ShowBasicBgColors();
//  ShowFormats();
//  Show256FgColors();
//  Show256BgColors();
  return 0;
}

