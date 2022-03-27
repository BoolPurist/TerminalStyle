//
// Created by nicegraphic on 2022-03-25.
//

#include "TerStyledText.hpp"
namespace TerminalStyle
{
  TerStyledText& TerStyledText::WithFgColor(Colors newFgColor)
  {
    extendedFgColorCode = false;

    currentFgColor = static_cast<unsigned int>(newFgColor);
    return *this;
  }

  TerStyledText& TerStyledText::WithBgColor(Colors newBgColor)
  {
    const static unsigned int k_offset_fg_bg_color{10U};

    extendedBgColorCode = false;

    auto givenColorCode = static_cast<unsigned int>(newBgColor);
    givenColorCode += k_offset_fg_bg_color;
    currentBgColor = givenColorCode;

    return *this;
  }
  TerStyledText& TerStyledText::WithFormat(Format newFormat)
  {

    currentFormat = static_cast<unsigned int>(newFormat);
    return *this;
  }
  TerStyledText& TerStyledText::WithText(const std::string& toStyle)
  {
    text = toStyle;
    return *this;
  }
  std::string TerStyledText::ToString() const
  {
    const static std::string k_left_start_delimiter{"\033["};
    const static std::string k_right_delimiter{"\033[0m"};
    const static char k_value_delimiter{';'};
    const static char k_left_end_delimiter{'m'};

    std::string fgColor{std::to_string(currentFgColor)};
    std::string bgColor{std::to_string(currentBgColor)};

    if (extendedFgColorCode) fgColor = "38;5;" + fgColor;
    if (extendedBgColorCode) bgColor = "48;5;" + bgColor;

    return k_left_start_delimiter +
      std::to_string(currentFormat) + k_value_delimiter +
      fgColor + k_value_delimiter +
      bgColor + k_left_end_delimiter +
      text + k_right_delimiter;
  }
  std::ostream& operator<<(std::ostream& os, const TerStyledText& text)
  {
    return os << text.ToString();
  }

  TerStyledText& TerStyledText::WithFgColor(unsigned int newFgColor)
  {
    extendedFgColorCode = true;
    currentFgColor = static_cast<unsigned int>(newFgColor);
    return *this;
  }
  TerStyledText& TerStyledText::WithBgColor(unsigned int newBgColor)
  {
    extendedBgColorCode = true;
    currentBgColor = static_cast<unsigned int>(newBgColor);
    return *this;
  }
}