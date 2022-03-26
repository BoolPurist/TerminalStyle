//
// Created by nicegraphic on 3/26/22.
//

#include "test-cases.hpp"

std::string CreateExpectedFgColor(unsigned int expectedFgColor);

std::string CreateExpectedFgColor(unsigned int expectedFgColor)
{
  return "\033[0;" + std::to_string(expectedFgColor) + ";49mText\033[0m";
}
std::pair<TerminalStyle::Colors,std::string> CreateTestCaseFgColor(
  TerminalStyle::Colors givenColor,
  unsigned int expectedFgColor
)
{
  return {givenColor, CreateExpectedFgColor(expectedFgColor)};
}
