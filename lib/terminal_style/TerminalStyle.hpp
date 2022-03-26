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
    class TerminalStyle {
    public:
        TerminalStyle& WithFgColor(Colors newFgColor);
        TerminalStyle& WithBgColor(Colors newBgColor);
        Formating& WithFormat(Formating newFormat);
        std::string StyleText() const;
    private:
        Colors currentFgColor = Colors::White;
        Colors currentBgColor = Colors::Black;
        Formating currentFormat = Formating::None;
    };

}

#endif //TERMINAL_STYLE_TERMINALSTYLE_HPP
