extern "C" {
#include "minirt.h"
#include "shape/hittable.h"
}
#include "gtest/gtest.h"

TEST(QuadraticTest, 해가_없는_경우)
{
    t_quadratic var;
    var.a = 1;
    var.b = 1;
    var.c = 1;
    t_coll t = {0, 100};
    float root;
    EXPECT_FALSE(quadratic_equation(var, t, &root));
}

TEST(QuadraticTest, 해가_1개인_경우)
{
    t_quadratic var;
    var.a = 1;
    var.b = -3;
    var.c = -2;
    t_coll t = {0, 100};
    float root;
    EXPECT_TRUE(quadratic_equation(var, t, &root));
}

TEST(QuadraticTest, 해가_2개인_경우)
{
    t_quadratic var;
    var.a = 1;
    var.b = -4;
    var.c = 4;
    t_coll t = {0, 100};
    float root;
    EXPECT_TRUE(quadratic_equation(var, t, &root));
}