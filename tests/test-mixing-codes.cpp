//
// Created by nicegraphic on 3/27/22.
//

#include <catch2/catch.hpp>
#include <terminal_style/TerStyledText.hpp>
#include <functional>

void TestOneMixing(
  const std::string& expected,
  const std::function<std::string()>& builderCall
);

TEST_CASE("Testing format, fg and bg color.")
{
  TestOneMixing(
    "\033[1;31;42m Yes it is awful \033[0m",
    []() -> std::string {
      using namespace TStyle;
      return TerStyledText().WithFormat(Format::Bold)
      .WithFgColor(Colors::Red).WithBgColor(Colors::Green)
      .WithText(" Yes it is awful ").ToString();
  });
}

TEST_CASE("Testing with extended fg color.")
{
  TestOneMixing(
    "\033[0;38;5;94;49m Yeah \033[0m",
    []() -> std::string {
      using namespace TStyle;
      return TerStyledText().WithFgColor(94)
        .WithText(" Yeah ").ToString();
    });
}

TEST_CASE("Testing with extended bg color.")
{
  TestOneMixing(
    "\033[0;39;48;5;78m Yeah \033[0m",
    []() -> std::string {
      using namespace TStyle;
      return TerStyledText().WithBgColor(78)
        .WithText(" Yeah ").ToString();
    });
}

TEST_CASE("Testing with extended bg and fg color.")
{
  TestOneMixing(
    "\033[0;38;5;48;48;5;78m Yeah \033[0m",
    []() -> std::string {
      using namespace TStyle;
      return TerStyledText().WithBgColor(78).WithFgColor(48)
        .WithText(" Yeah ").ToString();
    });
}

TEST_CASE("Testing with extended bg and normal fg color.")
{
  TestOneMixing(
    "\033[0;31;48;5;78m Yeah \033[0m",
    []() -> std::string {
      using namespace TStyle;
      return TerStyledText().WithBgColor(78).WithFgColor(Colors::Red)
        .WithText(" Yeah ").ToString();
    });
}

TEST_CASE("Testing with normal bg, extended fg color and bold format.")
{
  TestOneMixing(
    "\033[1;38;5;145;44m Yeah \033[0m",
    []() -> std::string {
      using namespace TStyle;
      return TerStyledText().WithFgColor(145).WithBgColor(Colors::Blue)
        .WithFormat(Format::Bold).WithText(" Yeah ").ToString();
    });
}

TEST_CASE("Testing several styling to see if format, fg- and bg color are updated.")
{
  using namespace TStyle;

  TerStyledText toStyle{};

  std::string currentOutput = toStyle.WithText(" Printing ")
    .WithBgColor(Colors::Red).ToString();

  REQUIRE("\033[0;39;41m Printing \033[0m" == currentOutput);

  currentOutput = toStyle.WithText(" Printing ")
    .WithFgColor(Colors::Black).WithBgColor(Colors::Blue).ToString();

  REQUIRE("\033[0;30;44m Printing \033[0m" == currentOutput);

  // Testing with new format, extended- fg and bg color.
  currentOutput = toStyle.WithText(" Printing ").WithFormat(Format::Bold)
    .WithFgColor(104).WithBgColor(120).ToString();

  REQUIRE("\033[1;38;5;104;48;5;120m Printing \033[0m" == currentOutput);


}

TEST_CASE("Testing constructor with start text")
{
  auto styler = TStyle::TerStyledText("Start text");

  styler.WithFgColor(TStyle::Colors::Red);
  REQUIRE("\033[0;31;49mStart text\033[0m" == styler.ToString());

  // Should override start text.
  styler.WithText("New Text");

  REQUIRE("\033[0;31;49mNew Text\033[0m" == styler.ToString());
}

void TestOneMixing(
  const std::string& expected,
  const std::function<std::string()>& builderCall
)
{
  std::string actualOutput = builderCall();

  REQUIRE(expected == actualOutput);
}

