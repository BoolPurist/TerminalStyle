add_library(
        terminal_style_lib
        terminal_style/Colors.hpp
        terminal_style/Formats.hpp
        terminal_style/TStyler.cpp
        terminal_style/TStyler.hpp
)

target_include_directories(terminal_style_lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})