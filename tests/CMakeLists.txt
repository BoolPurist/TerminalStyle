include(FetchContent)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG 216713a4066b79d9803d374f261ccb30c0fb451f # release v.2.13.8
)

FetchContent_MakeAvailable(catch2)

add_executable(testing
        tests-entry.cpp
        test-standard-codes-format-fgColor-bgColor.cpp
        test-cases.cpp
        test-cases.hpp
        test-mixing-codes.cpp
)
target_link_libraries(testing PRIVATE Catch2::Catch2 terminal_style_lib)