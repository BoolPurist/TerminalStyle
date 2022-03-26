//
// Created by nicegraphic on 2022-03-25.
//

#include "TStyler.hpp"
namespace TerminalStyle
{
  TStyler& TStyler::WithFgColor(Colors newFgColor)
  {
    currentFgColor = static_cast<unsigned int>(newFgColor);
    return *this;
  }
  TStyler& TStyler::WithBgColor(Colors newBgColor)
  {
    const static unsigned int k_offset_fg_bg_color{10U};

    auto givenColorCode = static_cast<unsigned int>(newBgColor);
    givenColorCode += k_offset_fg_bg_color;
    currentBgColor = givenColorCode;

    return *this;
  }
  TStyler& TStyler::WithFormat(Format newFormat)
  {

    currentFormat = static_cast<unsigned int>(newFormat);
    return *this;
  }
  std::string TStyler::StyleText(const std::string& toStyle) const
  {
    const static std::string k_left_start_delimiter{"\033["};
    const static std::string k_right_delimiter{"\033[0m"};
    const static char k_value_delimiter{';'};
    const static char k_left_end_delimiter{'m'};

    return k_left_start_delimiter +
    std::to_string(currentFormat) + k_value_delimiter +
    std::to_string(currentFgColor) + k_value_delimiter +
    std::to_string(currentBgColor) + k_left_end_delimiter +
    toStyle + k_right_delimiter;
  }
}