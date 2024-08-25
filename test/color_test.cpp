extern "C" {
#include "ray.h"
#include "minirt.h"
#include "parse.h"
}
#include "gtest/gtest.h"

TEST(color_test, color_to_int) {
    float r = 255 / 255.0;
    float g = 165 / 255.0;
    float b = 0 / 255.0;
    t_color color = {r, g, b};
    unsigned int int_color = color_to_int(color);
    EXPECT_FLOAT_EQ(int_color, 0xFFA500);
}

TEST(color_test, 성공) {
    t_color color = {181, 129, 112};
    normalize_color_value(&color);
    EXPECT_FLOAT_EQ(color.x, 181 / 255.0);
    EXPECT_FLOAT_EQ(color.y, 129 / 255.0);
    EXPECT_FLOAT_EQ(color.z, 112 / 255.0);
}

TEST(color_test, 값이_255보다_큰_경우) {
    t_color color = {181, 129, 256};
    ASSERT_THROW(normalize_color_value(&color), std::runtime_error);
}

TEST(color_test, 값이_음수인_경우) {
    t_color color = {-1, 129, 0};
    ASSERT_THROW(normalize_color_value(&color), std::runtime_error);
}