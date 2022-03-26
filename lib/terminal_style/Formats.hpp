//
// Created by nicegraphic on 2022-03-25.
//

#ifndef TERMINAL_STYLE_FORMATS_H
#define TERMINAL_STYLE_FORMATS_H

namespace TerminalStyle {
    enum class Format
    {
        None = 0,
        Bold = 1,
        Dim = 2,
        Underlined = 4,
        Blink = 5,
        Reverse = 7,
        Hidden = 8
    };
}

#endif //TERMINAL_STYLE_FORMATS_H
