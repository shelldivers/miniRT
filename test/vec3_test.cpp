extern "C" {
#include "vec3.h"
}
#include "gtest/gtest.h"

TEST(vec3_test, vec3_unit) {
    t_vec3 vec = {1, 2, 3};
    t_vec3 unit = vec3_unit(vec);
    ASSERT_FLOAT_EQ(unit.x, 0.26726124);
    ASSERT_FLOAT_EQ(unit.y, 0.53452248);
    ASSERT_FLOAT_EQ(unit.z, 0.80178373);
}

TEST(vec3_test, vec3_length) {
    t_vec3 vec = {1, 2, 3};
    float length = vec3_length(vec);
    ASSERT_FLOAT_EQ(length, 3.7416574);
}

TEST(vec3_test, vec3_length_squred) {
    t_vec3 vec = {1, 2, 3};
    float length_squred = vec3_length_squred(vec);
    ASSERT_FLOAT_EQ(length_squred, 14);
}

TEST(vec3_test, vec3_add) {
    t_vec3 a = {1, 2, 3};
    t_vec3 b = {4, 5, 6};
    t_vec3 sum = vec3_add(a, b);
    ASSERT_FLOAT_EQ(sum.x, 5);
    ASSERT_FLOAT_EQ(sum.y, 7);
    ASSERT_FLOAT_EQ(sum.z, 9);
}

TEST(vec3_test, vec3_sub) {
    t_vec3 a = {1, 2, 3};
    t_vec3 b = {4, 5, 6};
    t_vec3 sub = vec3_sub(a, b);
    ASSERT_FLOAT_EQ(sub.x, -3);
    ASSERT_FLOAT_EQ(sub.y, -3);
    ASSERT_FLOAT_EQ(sub.z, -3);
}

TEST(vec3_test, vec3_mul) {
    t_vec3 a = {1, 2, 3};
    float t = 2;
    t_vec3 mul = vec3_mul(a, t);
    ASSERT_FLOAT_EQ(mul.x, 2);
    ASSERT_FLOAT_EQ(mul.y, 4);
    ASSERT_FLOAT_EQ(mul.z, 6);
}

TEST(vec3_test, vec3_div) {
    t_vec3 a = {1, 2, 3};
    float t = 2;
    t_vec3 div = vec3_div(a, t);
    ASSERT_FLOAT_EQ(div.x, 0.5);
    ASSERT_FLOAT_EQ(div.y, 1);
    ASSERT_FLOAT_EQ(div.z, 1.5);
}

TEST(vec3_test, vec3_dot) {
    t_vec3 a = {1, 2, 3};
    t_vec3 b = {4, 5, 6};
    float dot = vec3_dot(a, b);
    ASSERT_FLOAT_EQ(dot, 32);
}

TEST(vec3_test, vec3_cross) {
    t_vec3 a = {1, 2, 3};
    t_vec3 b = {1, 5, 7};
    t_vec3 cross = vec3_cross(a, b);
    ASSERT_FLOAT_EQ(cross.x, -1);
    ASSERT_FLOAT_EQ(cross.y, -4);
    ASSERT_FLOAT_EQ(cross.z, 3);
}