#include "gtest/gtest.h"
#include "vec3.h"

TEST(Vec3Test, Vec3Test_vec3)
{
	t_vec3	vec = vec3(1, 2, 3);

	EXPECT_EQ(vec.x, 1);
	EXPECT_EQ(vec.y, 2);
	EXPECT_EQ(vec.z, 3);
}

TEST(Vec3Test, Vec3Test_vec3_add)
{
	t_vec3	vec1 = vec3(1, 2, 3);
	t_vec3	vec2 = vec3(4, 5, 6);
	t_vec3	vec = vec3_add(vec1, vec2);

	EXPECT_EQ(vec.x, 5);
	EXPECT_EQ(vec.y, 7);
	EXPECT_EQ(vec.z, 9);
}

TEST(Vec3Test, Vec3Test_vec3_sub)
{
	t_vec3	vec1 = vec3(1, 2, 3);
	t_vec3	vec2 = vec3(4, 5, 6);
	t_vec3	vec = vec3_sub(vec1, vec2);

	EXPECT_EQ(vec.x, -3);
	EXPECT_EQ(vec.y, -3);
	EXPECT_EQ(vec.z, -3);
}

TEST(Vec3Test, Vec3Test_vec3_dot)
{
	t_vec3	vec1 = vec3(1, 2, 3);
	t_vec3	vec2 = vec3(4, 5, 6);
	float	dot = vec3_dot(vec1, vec2);

	EXPECT_EQ(dot, 32);
}

TEST(Vec3Test, Vec3Test_vec3_mul)
{
	t_vec3	vec1 = vec3(1, 2, 3);
	float	t = 2;
	t_vec3	vec = vec3_mul(vec1, t);

	EXPECT_EQ(vec.x, 2);
	EXPECT_EQ(vec.y, 4);
	EXPECT_EQ(vec.z, 6);
}

TEST(Vec3Test, Vec3Test_vec_length)
{
	t_vec3	vec = vec3(1, 2, 3);
	float	length = vec3_length(vec);

	EXPECT_FLOAT_EQ(length, 3.7416573867739413);
}
