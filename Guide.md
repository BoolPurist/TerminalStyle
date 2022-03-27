# How to use it

This library provides its functionality in the namespace TStyle.
To use it include the following header.

```cpp
#include <terminal_style/TerStyledText.hpp>
```

The library provides a class called **TerStyledText**. This class works like builder object via 
method chaining to configure the output of text.

The printing of a text can be altered in 3 areas. 

- In format: text is printed in bold or with underline
- In foreground color: Color of text
- In background color: Color behind the text.

To print out a text in certain color or format:

1. Construct a TerStyledText object.
2. Call the needed setter method to set foreground/background color, format and text to print.
3. Write this configured object to std::cout via the << operator.

## Example: Print a text with underlining and in red foreground color.

```c++
  using namespace  TStyle;
  std::cout << TerStyledText()
    .WithFormat(Format::Underlined)
    .WithFgColor(Colors::Red)
    .WithText(" Some text ") << std::endl;
```

The output will be

![underlined_red_text](./pictures/underlined_red_text.png)


## Changing Format
The format of text can be changed by the method **WithFormat(Colors newFgColor)**.

The enum **Format** contains all possible options like bold or underlining.

## Changing foreground Color or background via enum value

The foreground color of text can be changed via method **WithFgColor(Colors newFgColor)**.
The background color of text can be changed via method **WithBgColor(Colors newBgColor)**.

The enum **Colors** indicates with its constants values like Red or Blue in which color a text can
be printed.

## Changing foreground Color or background via unsigned numbers.

Text can be printed in extended color range.

### All possible colors for foreground

![all_foreground_colors](./pictures/all_foreground_colors.png)

### All possible colors for background

![all_background_colors](./pictures/all_background_colors.png)

The foreground color of text can be changed via method **WithFgColor(unsigned int newFgColor)**.
The background color of text can be changed via method **WithBgColor(unsigned int newBgColor)**.

These methods expect values between 0 and 255. These methods allow to set the foreground and 
background color in 256 different colors. Note: not all unix terminals support this color range. 

## Example using extended color range for foreground and background.

```c++
  using namespace  TStyle;
    std::cout << TerStyledText()
    .WithFgColor(88)
    .WithBgColor(6)
    .WithText(" Some text ") << std::endl;
```

Output will be:

![lightblue_red_text](./pictures/lightblue_red_text.png)

