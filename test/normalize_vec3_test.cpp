extern "C" {
#include "minirt.h"
}
#include "gtest/gtest.h"

TEST(normalize_vec3_test, 성공)
{
    t_vec3 vec = {1, 0, 1};
    normalize_vec3(&vec);
    float length = vec3_length(vec);
    ASSERT_FLOAT_EQ(length, 1);
}

TEST(normalize_vec3_test, 법선_벡터가_범위를_벗어난_경우)
{
    t_vec3 vec = {1, 0, 1.1};
    ASSERT_THROW(normalize_vec3(&vec), std::runtime_error);
}

TEST(normalize_vec3_test, 제로_벡터인_경우)
{
    t_vec3 vec = {0, 0, 0};

    ASSERT_THROW(normalize_vec3(&vec), std::runtime_error);
}