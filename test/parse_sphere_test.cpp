extern "C" {
#include "minirt.h"
#include "shape/sphere.h"
}
#include "gtest/gtest.h"

TEST(parse_sphere_test, basic_case)
{
	t_hit_lst	*world = (t_hit_lst *)malloc(sizeof(t_hit_lst));
	char		*line = (char *)"sp	0,0,20	10	255,255,255";

	world = NULL;
	parse_sphere(line, &world);
	ASSERT_NE(world, nullptr);
	t_hit *result = world->objects[0];
	ASSERT_EQ(result->shape, SPHERE);
	t_sphere *sphere = (t_sphere *)result->hit;
	ASSERT_EQ(sphere->center.x, 0);
	ASSERT_EQ(sphere->center.y, 0);
	ASSERT_EQ(sphere->center.z, 20);
	ASSERT_EQ(sphere->radius, 5);
	ASSERT_EQ(sphere->color.x, 255);
	ASSERT_EQ(sphere->color.y, 255);
	ASSERT_EQ(sphere->color.z, 255);
}
