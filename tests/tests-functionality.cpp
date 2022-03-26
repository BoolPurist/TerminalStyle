//
// Created by nicegraphic on 3/26/22.
//

#include <catch2/catch.hpp>
#include <terminal_style/TerStyledText.hpp>
#include "test-cases.hpp"

TEST_CASE("Testing")
{
  using namespace TerminalStyle;

  auto testCase = GENERATE(
    CreateTestCaseFgColor(Colors::Black, 30),
    CreateTestCaseFgColor(Colors::Red, 31),
    CreateTestCaseFgColor(Colors::Green, 32),
    CreateTestCaseFgColor(Colors::Yellow, 33),
    CreateTestCaseFgColor(Colors::Blue, 34),
    CreateTestCaseFgColor(Colors::Magenta, 35),
    CreateTestCaseFgColor(Colors::Cyan, 36),
    CreateTestCaseFgColor(Colors::LightGray, 37),
    CreateTestCaseFgColor(Colors::DarkGray, 90),
    CreateTestCaseFgColor(Colors::LightRed, 91),
    CreateTestCaseFgColor(Colors::LightGreen, 92),
    CreateTestCaseFgColor(Colors::LightYellow, 93),
    CreateTestCaseFgColor(Colors::LightBlue, 94),
    CreateTestCaseFgColor(Colors::LightMagenta, 95),
    CreateTestCaseFgColor(Colors::LightCyan, 96),
    CreateTestCaseFgColor(Colors::White, 97)
  );

  const auto& givenColor = testCase.first;
  const auto& expectedOutput = testCase.second;

  const auto actualOutput = TerStyledText().WithFgColor(givenColor).WithText(k_ContentString).ToString();

  REQUIRE(expectedOutput == actualOutput);
}

TEST_CASE("Testing format, fg and bg color.")
{
  using namespace TerminalStyle;

  std::string expectedOutput{"\033[1;31;42m Yes it is awful \033[0m"};
  std::string actualOutput = TerStyledText().WithFormat(Format::Bold)
    .WithFgColor(Colors::Red).WithBgColor(Colors::Green)
    .WithText(" Yes it is awful ").ToString();

  REQUIRE(expectedOutput == actualOutput);
}