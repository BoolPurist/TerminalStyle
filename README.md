# Terminal Style

Servers as a library to allow print messages with a chosen foreground/background color, format 
in a linux terminal.

## Limitation

The functionality will work only in unix terminals like XFCE4 Terminal or xTerm for example.

## How to integrate this library in a project

The library can be integrated via cmake.

1. Add this respo as submodule to your respo.
2. Include this library into pipeline via 

```cmake
add_subdirectory({path to folder submodule})
```

Now the library is included in your cmake build process. 
This library exposes a target called **terminal_style_lib** .

You can link against this target to use this library via.

```cmake
target_include_directories({name of target to use this lib} PRIVATE terminal_style_lib)
```

This target also adds an include-path to the folder terminal_style with all the files for this library.

### Build options

By default, only the library is build. You can also build the unit tests and the demo app.
To enable building more, add an option parameter to the cmake command:

- Add the parameter -DPROJECTS_TESTS=ON for the unit tests.
- Add the parameter -DPROJECTS_DEMO=ON for the demo app.

The demo app is an executable which prints out text with all different colors and 
formatting provided by this library.

## How to use it

See the [Guide](./Guide.md)

## How does it work

Whenever a TerStyle instance is written to an output stream, the given text
is inserted with a special encoding. This encoding has 2 parts, left one and right one.

The right part is always in the form ( \033[0m ) and all other text written to the output stream
is not interpreted with a format or color of a previous operation.

The left part has the following syntax 
\033[|*number for format*|;|*number of fg color*|;|*number of bg color*|m
This part determines which in which format and colors the surrounded text is printed in the terminal.

### Example: 
```cpp
  using namespace  TStyle;
  std::cout << TerStyledText()
    .WithFormat(Format::Bold)
    .WithFgColor(Colors::Red).WithBgColor(Colors::Blue)
    .WithText(" Some text ") << std::endl;
```
Will write a content ( \033[1;31;44m Some text \033[0m ) . The left part
is ( \033[1;31;44m ) and the right part is ( \033[0m ) . ( Some text ) is the text 
surrounded by the left and right part.

Link for [Additional reading](https://misc.flogisoft.com/bash/tip_colors_and_formatting)