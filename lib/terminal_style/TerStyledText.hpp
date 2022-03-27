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
    TerStyledText() = default;
    explicit TerStyledText(const std::string& startText);
    /// Sets the text color according to the enum value newFgColor
    TerStyledText& WithFgColor(Colors newFgColor);
    /// Sets the background color according to the enum value newBgColor
    TerStyledText& WithBgColor(Colors newBgColor);
    /// Sets the text color according to the a number between 0 and 255.
    TerStyledText& WithFgColor(unsigned int newFgColor);
    /// Sets the background color according to the a number between 0 and 255.
    TerStyledText& WithBgColor(unsigned int newBgColor);
    /// Sets the formats for text according to the enum value newFormat .
    TerStyledText& WithFormat(Format newFormat);
    /// Sets the text to printed with a certain format, fg and bg color.
    TerStyledText& WithText(const std::string& toStyle);
    /// Returns the text surrounded by the left and right encoding for the terminal
    /// to know which in color or format the text should be printed.
    std::string ToString();

    friend std::ostream& operator<<(std::ostream& os, TerStyledText text);
   private:
    unsigned int currentFgColor = static_cast<unsigned int>(Colors::Default);
    unsigned int currentBgColor = static_cast<unsigned int>(Colors::Default) + 10U;
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
