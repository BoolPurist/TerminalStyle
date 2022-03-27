#include "demo_functions.hpp"

int main() {

  TStyle::TerStyledText formatter{"Start text"};

  std::cout << formatter
  .WithFgColor(TStyle::Colors::Red)
  << std::endl;
//  ShowBasicFgColors();
//  ShowBasicBgColors();
//  ShowFormats();
//  Show256FgColors();
//  Show256BgColors();
  return 0;
}

