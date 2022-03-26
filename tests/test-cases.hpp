//
// Created by nicegraphic on 3/26/22.
//

#ifndef TERMINAL_STYLE_A317DBFF22A940EF9EA1591D92F855B3_TEST_CASES_H_
#define TERMINAL_STYLE_A317DBFF22A940EF9EA1591D92F855B3_TEST_CASES_H_

#include <string>
#include <terminal_style/Colors.hpp>

const std::string k_ContentString{"Text"};

std::pair<TerminalStyle::Colors, std::string> CreateTestCaseFgColor(
  TerminalStyle::Colors givenColor,
  unsigned int expectedFgColor
);

#endif //TERMINAL_STYLE_A317DBFF22A940EF9EA1591D92F855B3_TEST_CASES_H_
