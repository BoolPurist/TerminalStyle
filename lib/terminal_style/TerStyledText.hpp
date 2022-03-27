//
// Created by nicegraphic on 2022-03-25.
//

#ifndef TERMINAL_STYLE_TERMINALSTYLE_HPP
#define TERMINAL_STYLE_TERMINALSTYLE_HPP

#include "Formats.hpp"
#include "Colors.hpp"
#include <string>
#include <ostream>

namespace TerminalStyle
{
  class TerStyledText
  {

   public:
    TerStyledText& WithFgColor(Colors newFgColor);
    TerStyledText& WithFgColor(unsigned int newFgColor);
    TerStyledText& WithBgColor(unsigned int newBgColor);
    TerStyledText& WithBgColor(Colors newBgColor);
    TerStyledText& WithFormat(Format newFormat);
    TerStyledText& WithText(const std::string& toStyle);
    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream& os, const TerStyledText& text);
   private:
    unsigned int currentFgColor = 39;
    unsigned int currentBgColor = 49;
    std::string text{};
    unsigned int currentFormat = static_cast<unsigned int>(Format::None);
    bool extendedFgColorCode{};
    bool extendedBgColorCode{};
  };

}

#endif //TERMINAL_STYLE_TERMINALSTYLE_HPP
