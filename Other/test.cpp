#include <gtest/gtest.h>
#include <string>
#include <variant>

TEST(new_test, test_one)
{
    int n = 1;
    int m = 2;
    EXPECT_EQ((n + m), 3);
}

TEST(play_with_variant, variant_is_string)
{
    std::variant<int, std::string, float> str = "Hello";
    EXPECT_EQ("Hello", std::get<std::string>(str));
}
