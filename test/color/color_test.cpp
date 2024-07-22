extern "C" {
#include "color.h"
}
#include "gtest/gtest.h"

TEST(ColorTest, ColorTest_color)
{
    t_color color;

    color.r = 1;
    color.g = 2;
    color.b = 3;

    EXPECT_EQ(color.r, 1);
    EXPECT_EQ(color.g, 2);
    EXPECT_EQ(color.b, 3);
}

TEST(ColorTest, ColorTest_color_to_vec3)
{
    t_color color;

    color.r = 1;
    color.g = 2;
    color.b = 3;

    t_vec3 vec = color_to_vec3(color);

    EXPECT_EQ(vec.x, 1);
    EXPECT_EQ(vec.y, 2);
    EXPECT_EQ(vec.z, 3);
}

TEST(ColorTest, ColorTest_vec3_to_color)
{
    t_vec3 vec;

    vec.x = 1;
    vec.y = 2;
    vec.z = 3;

    t_color color = vec3_to_color(vec);

    EXPECT_EQ(color.r, 1);
    EXPECT_EQ(color.g, 2);
    EXPECT_EQ(color.b, 3);
}