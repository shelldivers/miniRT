#include "gtest/gtest.h"
extern "C" {
#include "ray.h"
}

TEST(RayTest, RayTest_ray)
{
	t_ray		ray;
	t_point3	orig = point3(1, 2, 3);
	t_vec3		dir = vec3(4, 5, 6);

	ray.orig = orig;
	ray.dir = dir;
	EXPECT_EQ(ray.orig.pos.x, 1);
	EXPECT_EQ(ray.orig.pos.y, 2);
	EXPECT_EQ(ray.orig.pos.z, 3);
	EXPECT_EQ(ray.dir.x, 4);
	EXPECT_EQ(ray.dir.y, 5);
	EXPECT_EQ(ray.dir.z, 6);
}

TEST(RayTest, RayTest_point_at)
{
	t_ray		ray;
	t_point3	point;
	t_point3	orig = point3(1, 2, 3);
	t_vec3		dir = vec3(4, 5, 6);

	ray.orig = orig;
	ray.dir = dir;
	point = point_at(&ray, 3);
	EXPECT_EQ(point.pos.x, 13);
	EXPECT_EQ(point.pos.y, 17);
	EXPECT_EQ(point.pos.z, 21);
}