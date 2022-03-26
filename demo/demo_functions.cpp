//
// Created by nicegraphic on 3/26/22.
//


#include "demo_functions.hpp"

void ShowBasicFgColors()
{
  using namespace TerminalStyle;

  PrintAnnouncement("Foreground Colors");

  PrintInFgColor("Black", Colors::Black);
  PrintInFgColor("Red", Colors::Red);
  PrintInFgColor("Green", Colors::Green);
  PrintInFgColor("Yellow", Colors::Yellow);
  PrintInFgColor("Blue", Colors::Blue);
  PrintInFgColor("Magenta", Colors::Magenta);
  PrintInFgColor("Cyan", Colors::Cyan);
  PrintInFgColor("Light Gray", Colors::LightGray);
  PrintInFgColor("Dark Gray", Colors::DarkGray);
  PrintInFgColor("Light Red", Colors::LightRed);
  PrintInFgColor("Light Green", Colors::LightGreen);
  PrintInFgColor("Light Yellow", Colors::LightYellow);
  PrintInFgColor("Light Blue", Colors::LightBlue);
  PrintInFgColor("Light Magenta", Colors::LightMagenta);
  PrintInFgColor("Light Cyan", Colors::LightCyan);
  PrintInFgColor("White", Colors::White);

  std::cout << std::endl;
}

void ShowBasicBgColors()
{
  using namespace TerminalStyle;

  PrintAnnouncement("Background Colors");

  PrintInBgColor("Black", Colors::Black);
  PrintInBgColor("Red", Colors::Red);
  PrintInBgColor("Green", Colors::Green);
  PrintInBgColor("Yellow", Colors::Yellow);
  PrintInBgColor("Blue", Colors::Blue);
  PrintInBgColor("Magenta", Colors::Magenta);
  PrintInBgColor("Cyan", Colors::Cyan);
  PrintInBgColor("Light Gray", Colors::LightGray);
  PrintInBgColor("Dark Gray", Colors::DarkGray);
  PrintInBgColor("Light Red", Colors::LightRed);
  PrintInBgColor("Light Green", Colors::LightGreen);
  PrintInBgColor("Light Yellow", Colors::LightYellow);
  PrintInBgColor("Light Blue", Colors::LightBlue);
  PrintInBgColor("Light Magenta", Colors::LightMagenta);
  PrintInBgColor("Light Cyan", Colors::LightCyan);
  PrintInBgColor("White", Colors::White);

  std::cout << std::endl;
}

void ShowFormats()
{
  using namespace TerminalStyle;

  PrintAnnouncement("Formats");

  PrintInFormat("Bold", Format::Bold);
  PrintInFormat("Bold",Format::Dim);
  PrintInFormat("Bold",Format::Underlined);
  PrintInFormat("Bold",Format::Blink);
  PrintInFormat("Bold",Format::Reverse);
  PrintInFormat("Bold",Format::Hidden);

  std::cout << std::endl;
}

void PrintAnnouncement(const std::string& title)
{
  std::cout << title << std::endl;
  std::cout << std::string(50, '=') << '\n' << std::endl;
}

void PrintInFgColor(const std::string& toPrint, TerminalStyle::Colors fgColor)
{
  using namespace TerminalStyle;
  TerStyledText style{};

  std::cout << style.WithFgColor(fgColor)
    .WithText(toPrint) << std::endl;
}

void PrintInBgColor(const std::string& toPrint, TerminalStyle::Colors bgColor)
{
  using namespace TerminalStyle;
  TerStyledText style{};

  std::cout << style.WithBgColor(bgColor)
    .WithText(toPrint) << std::endl;
}

void PrintInFormat(const std::string& toPrint, TerminalStyle::Format format)
{
  using namespace TerminalStyle;
  TerStyledText style{};

  std::cout << style.WithFormat(format)
    .WithText(toPrint) << std::endl;
}
