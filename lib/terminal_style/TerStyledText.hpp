//
// Created by nicegraphic on 2022-03-25.
//

#ifndef TERMINAL_STYLE_TERMINALSTYLE_HPP
#define TERMINAL_STYLE_TERMINALSTYLE_HPP

#include "Formats.hpp"
#include "Colors.hpp"
#include <string>
#include <ostream>

namespace TStyle
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
    std::string ToString();

    friend std::ostream& operator<<(std::ostream& os, TerStyledText text);
   private:
    unsigned int currentFgColor = 39;
    unsigned int currentBgColor = 49;
    unsigned int currentFormat = static_cast<unsigned int>(Format::None);
    std::string text{};
    bool extendedFgColorCode{};
    bool extendedBgColorCode{};
    std::string prefix{};
    bool isPrefixUpToDate{};

    void CreatePrefixIfNeeded();
  };

}

#endif //TERMINAL_STYLE_TERMINALSTYLE_HPP
