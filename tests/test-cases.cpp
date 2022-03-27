//
// Created by nicegraphic on 3/26/22.
//

#include "test-cases.hpp"

std::string CreateExpectedFgColor(unsigned int expectedFgColor);
std::string CreateExpectedBgColor(unsigned int expectedFgColor);
std::string CreateExpectedFormat(unsigned int expectedFormat);

std::string CreateExpectedFormat(unsigned int expectedFormat)
{
  return "\033[" + std::to_string(expectedFormat)  + ";39" +
    ";49m" + k_ContentString + "\033[0m";
}

std::string CreateExpectedFgColor(unsigned int expectedFgColor)
{
  return "\033[0;" + std::to_string(expectedFgColor) +
  ";49m" + k_ContentString + "\033[0m";
}

std::string CreateExpectedBgColor(unsigned int expectedFgColor)
{
  using namespace std::string_literals;
  return "\033[0;"s + "39"s + ";"s + std::to_string(expectedFgColor) + "m"s + k_ContentString + "\033[0m"s;
}

std::pair<TStyle::Colors, std::string> CreateTestCaseBgColor(
  TStyle::Colors givenColor,
  unsigned int expectedBgColor
)
{
  return std::make_pair(givenColor, CreateExpectedBgColor(expectedBgColor));
}

std::pair<TStyle::Colors, std::string> CreateTestCaseFgColor(
  TStyle::Colors givenColor,
  unsigned int expectedFgColor
)
{
  return std::make_pair(givenColor, CreateExpectedFgColor(expectedFgColor));
}

std::pair<TStyle::Format, std::string> CreateTestCaseFormat(
  TStyle::Format givenFormat,
  unsigned int expectedFormat
)
{
  return std::make_pair(givenFormat, CreateExpectedFormat(expectedFormat));
}
