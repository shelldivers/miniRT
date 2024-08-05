extern "C" {
#include "ray.h"
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

TEST(color_test, rgb_to_color) {
    unsigned int r = 0;
    unsigned int g = 255;
    unsigned int b = 255;
    t_color color = rgb_to_color(r, g, b);
    EXPECT_FLOAT_EQ(color.x, 0);
    EXPECT_FLOAT_EQ(color.y, 1);
    EXPECT_FLOAT_EQ(color.z, 1);
}
