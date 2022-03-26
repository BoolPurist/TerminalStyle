//
// Created by nicegraphic on 2022-03-25.
//

#include "TerStyledText.hpp"
namespace TerminalStyle
{
  TerStyledText& TerStyledText::WithFgColor(Colors newFgColor)
  {
    currentFgColor = static_cast<unsigned int>(newFgColor);
    return *this;
  }

  TerStyledText& TerStyledText::WithBgColor(Colors newBgColor)
  {
    const static unsigned int k_offset_fg_bg_color{10U};

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

    return k_left_start_delimiter +
      std::to_string(currentFormat) + k_value_delimiter +
      std::to_string(currentFgColor) + k_value_delimiter +
      std::to_string(currentBgColor) + k_left_end_delimiter +
      text + k_right_delimiter;
  }
  std::ostream& operator<<(std::ostream& os, const TerStyledText& text)
  {
    return os << text.ToString();
  }

  TerStyledText& TerStyledText::WithFgColor(unsigned int newFgColor)
  {
    currentBgColor = static_cast<unsigned int>(newFgColor);
    currentFgColor = 5U;
    currentFormat = 38U;
    return *this;
  }
  TerStyledText& TerStyledText::WithBgColor(unsigned int newBgColor)
  {
    currentBgColor = static_cast<unsigned int>(newBgColor);
    currentFgColor = 5U;
    currentFormat = 48U;
    return *this;
  }
}