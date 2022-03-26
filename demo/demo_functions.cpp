//
// Created by nicegraphic on 3/26/22.
//


#include "demo_functions.hpp"

void ShowBasicFgColors()
{
  using namespace TerminalStyle;
  PrintInFgColor("Colored text", Colors::Black);
  PrintInFgColor("Colored text", Colors::Red);
  PrintInFgColor("Colored text", Colors::Green);
  PrintInFgColor("Colored text", Colors::Yellow);
  PrintInFgColor("Colored text", Colors::Blue);
  PrintInFgColor("Colored text", Colors::Magenta);
  PrintInFgColor("Colored text", Colors::LightGray);
  PrintInFgColor("Colored text", Colors::DarkGray);
  PrintInFgColor("Colored text", Colors::LightRed);
  PrintInFgColor("Colored text", Colors::LightGreen);
  PrintInFgColor("Colored text", Colors::LightYellow);
  PrintInFgColor("Colored text", Colors::LightBlue);
  PrintInFgColor("Colored text", Colors::LightMagenta);
  PrintInFgColor("Colored text", Colors::LightCyan);
  PrintInFgColor("Colored text", Colors::White);

}

void ShowBasicBgColors()
{
  using namespace TerminalStyle;
  PrintInBgColor("Colored Background", Colors::Black);
  PrintInBgColor("Colored Background", Colors::Red);
  PrintInBgColor("Colored Background", Colors::Green);
  PrintInBgColor("Colored Background", Colors::Yellow);
  PrintInBgColor("Colored Background", Colors::Blue);
  PrintInBgColor("Colored Background", Colors::Magenta);
  PrintInBgColor("Colored Background", Colors::LightGray);
  PrintInBgColor("Colored Background", Colors::DarkGray);
  PrintInBgColor("Colored Background", Colors::LightRed);
  PrintInBgColor("Colored Background", Colors::LightGreen);
  PrintInBgColor("Colored Background", Colors::LightYellow);
  PrintInBgColor("Colored Background", Colors::LightBlue);
  PrintInBgColor("Colored Background", Colors::LightMagenta);
  PrintInBgColor("Colored Background", Colors::LightCyan);
  PrintInBgColor("Colored Background", Colors::White);
}

void ShowFormats()
{
  using namespace TerminalStyle;
  PrintInFormat("Bold", Formating::Bold);
  PrintInFormat("Bold",Formating::Dim);
  PrintInFormat("Bold",Formating::Underlined);
  PrintInFormat("Bold",Formating::Blink);
  PrintInFormat("Bold",Formating::Reverse);
  PrintInFormat("Bold",Formating::Hidden);
}

void PrintInFgColor(const std::string& toPrint, TerminalStyle::Colors fgColor)
{
  using namespace TerminalStyle;
  TStyler style{};

  std::cout << style.WithFgColor(fgColor)
    .StyleText(toPrint) << std::endl;
}

void PrintInBgColor(const std::string& toPrint, TerminalStyle::Colors bgColor)
{
  using namespace TerminalStyle;
  TStyler style{};

  std::cout << style.WithBgColor(bgColor)
    .StyleText(toPrint) << std::endl;
}

void PrintInFormat(const std::string& toPrint, TerminalStyle::Formating format)
{
  using namespace TerminalStyle;
  TStyler style{};

  std::cout << style.WithFormat(format)
    .StyleText(toPrint) << std::endl;
}
