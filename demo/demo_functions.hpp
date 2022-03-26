//
// Created by nicegraphic on 3/26/22.
//

#ifndef TERMINAL_STYLE_3538CC6FCDB14DF9A4F8CB08DD05C730_DEMO_FUNCTIONS_H_
#define TERMINAL_STYLE_3538CC6FCDB14DF9A4F8CB08DD05C730_DEMO_FUNCTIONS_H_

#include <string>
#include <terminal_style/TerStyledText.hpp>
#include <iostream>
#include <iomanip>

void ShowBasicFgColors();
void ShowBasicBgColors();
void ShowFormats();
void Show256FgColors();
void Show256BgColors();
void PrintAnnouncement(const std::string& title);
void PrintInFgColor(const std::string& toPrint, TerminalStyle::Colors fgColor);
void PrintInBgColor(const std::string& toPrint, TerminalStyle::Colors bgColor);
void PrintInFormat(const std::string& toPrint, TerminalStyle::Format format);
void Print256FgColor(unsigned int number);
void Print256BgColor(unsigned int number);


#endif //TERMINAL_STYLE_3538CC6FCDB14DF9A4F8CB08DD05C730_DEMO_FUNCTIONS_H_
