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
    auto givenColorCode = static_cast<unsigned int>(newBgColor);

    givenColorCode += 10U;

    currentBgColor = givenColorCode;
    return *this;
  }
  TStyler& TStyler::WithFormat(Formating newFormat)
  {

    currentFormat = static_cast<unsigned int>(newFormat);
    return *this;
  }
  std::string TStyler::StyleText(const std::string& toStyle) const
  {
    return "\033[" +
    std::to_string(currentFormat) + ";" +
    std::to_string(currentFgColor) + ";" +
    std::to_string(currentBgColor) + "m" +
    toStyle + "\033[0m";
  }
}