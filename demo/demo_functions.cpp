//
// Created by nicegraphic on 3/26/22.
//



#include "demo_functions.hpp"

void ShowBasicFgColors()
{
  using namespace TStyle;

  PrintAnnouncement("Foreground Colors");

  PrintInFgColor("Colors::Black", Colors::Black);
  PrintInFgColor ("Colors::Red", Colors::Red);
  PrintInFgColor ("Colors::Green", Colors::Green);
  PrintInFgColor ("Colors::Yellow", Colors::Yellow);
  PrintInFgColor ("Colors::Blue", Colors::Blue);
  PrintInFgColor ("Colors::Magenta", Colors::Magenta);
  PrintInFgColor ("Colors::Cyan", Colors::Cyan);
  PrintInFgColor ("Colors::LightGray", Colors::LightGray);
  PrintInFgColor ("Colors::DarkGray", Colors::DarkGray);
  PrintInFgColor ("Colors::LightRed", Colors::LightRed);
  PrintInFgColor ("Colors::LightGreen", Colors::LightGreen);
  PrintInFgColor ("Colors::LightYellow", Colors::LightYellow);
  PrintInFgColor ("Colors::LightBlue", Colors::LightBlue);
  PrintInFgColor ("Colors::LightMagenta", Colors::LightMagenta);
  PrintInFgColor ("Colors::LightCyan", Colors::LightCyan);
  PrintInFgColor ("Colors::White", Colors::White);

  std::cout << std::endl;
}

void ShowBasicBgColors()
{
  using namespace TStyle;

  PrintAnnouncement("Background Colors");

  PrintInBgColor("Colors::Black", Colors::Black);
  PrintInBgColor("Colors::Red", Colors::Red);
  PrintInBgColor("Colors::Green", Colors::Green);
  PrintInBgColor("Colors::Yellow", Colors::Yellow);
  PrintInBgColor("Colors::Blue", Colors::Blue);
  PrintInBgColor("Colors::Magenta", Colors::Magenta);
  PrintInBgColor("Colors::Cyan", Colors::Cyan);
  PrintInBgColor("Colors::LightGray", Colors::LightGray);
  PrintInBgColor("Colors::DarkGray", Colors::DarkGray);
  PrintInBgColor("Colors::LightRed", Colors::LightRed);
  PrintInBgColor("Colors::LightGreen", Colors::LightGreen);
  PrintInBgColor("Colors::LightYellow", Colors::LightYellow);
  PrintInBgColor("Colors::LightBlue", Colors::LightBlue);
  PrintInBgColor("Colors::LightMagenta", Colors::LightMagenta);
  PrintInBgColor("Colors::LightCyan", Colors::LightCyan);
  PrintInBgColor("Colors::White", Colors::White);

  std::cout << std::endl;
}

void ShowFormats()
{
  using namespace TStyle;

  PrintAnnouncement("Formats");

  PrintInFormat("Format::Bold", Format::Bold);
  PrintInFormat("Format::Dim",Format::Dim);
  PrintInFormat("Format::Underlined",Format::Underlined);
  PrintInFormat("Format::Blink",Format::Blink);
  PrintInFormat("Format::Reverse",Format::Reverse);
  PrintInFormat("Format::Hidden",Format::Hidden);

  std::cout << std::endl;
}

void PrintAnnouncement(const std::string& title)
{
  std::cout << title << std::endl;
  std::cout << std::string(50, '=') << '\n' << std::endl;
}

void PrintInFgColor(const std::string& toPrint, TStyle::Colors fgColor)
{
  using namespace TStyle;
  TerStyledText style{};

  std::cout << style.WithFgColor(fgColor)
    .WithText(toPrint) << std::endl;
}

void PrintInBgColor(const std::string& toPrint, TStyle::Colors bgColor)
{
  using namespace TStyle;
  TerStyledText style{};

  std::cout << style.WithBgColor(bgColor)
    .WithText(toPrint) << std::endl;
}

void PrintInFormat(const std::string& toPrint, TStyle::Format format)
{
  using namespace TStyle;
  TerStyledText style{};

  std::cout << style.WithFormat(format)
    .WithText(toPrint) << std::endl;
}
void Show256FgColors()
{
  Print256Colors("Printing 256 fg colors", Print256FgColor);
}
void Show256BgColors()
{
  Print256Colors("Printing 256 bg colors", Print256BgColor);
}
void Print256FgColor(unsigned int number)
{
  using namespace TStyle;
  TerStyledText style{};

  const std::string textNumber{std::to_string(number)};

  size_t paddingSize{static_cast<size_t>(8U - textNumber.size())};
  std::cout << style.WithFgColor(number)
    .WithText(std::string(paddingSize, ' ') + textNumber);
}
void Print256BgColor(unsigned int number)
{
  using namespace TStyle;
  TerStyledText style{};

  const std::string textNumber{std::to_string(number)};

  size_t paddingSize{static_cast<size_t>(8U - textNumber.size())};
  std::cout << style.WithBgColor(number)
    .WithText(std::string(paddingSize, ' ') + textNumber);
}
void Print256Colors(
  const std::string& title,
  std::function<void(unsigned int)> printColorFunc
)
{
  PrintAnnouncement(title);

  for (unsigned int i{0}, j{1}; i < 256; i++, j++)
  {
    printColorFunc(i);
    if (j / 10 >= 1)
    {
      j = 0;
      std::cout << std::endl;
    }
  }

  std::cout << '\n' << std::endl;
}
