//
// Created by nicegraphic on 2022-03-25.
//

#ifndef TERMINAL_STYLE_TERMINALSTYLE_HPP
#define TERMINAL_STYLE_TERMINALSTYLE_HPP

#include "Formats.hpp"
#include "Colors.hpp"
#include <string>

namespace TerminalStyle
{
  class TStyler
  {
   public:
    TStyler& WithFgColor(Colors newFgColor);
    TStyler& WithBgColor(Colors newBgColor);
    TStyler& WithFormat(Format newFormat);
    std::string StyleText(const std::string& toStyle) const;
   private:
    unsigned int currentFgColor = 39;
    unsigned int currentBgColor = 49;
    unsigned int currentFormat = static_cast<unsigned int>(Format::None);
  };

}

#endif //TERMINAL_STYLE_TERMINALSTYLE_HPP
