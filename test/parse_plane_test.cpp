extern "C" {
#include "minirt.h"
#include "shape/plane.h"
}
#include "gtest/gtest.h"

TEST(parse_sphere_test, basic_case)
{
	t_hit_lst	*world = (t_hit_lst *)malloc(sizeof(t_hit_lst));
	char		*line = (char *)"pl	0,0,20	0,0,1	255,255,255";

	world = NULL;
	parse_plane(line, &world);
	ASSERT_NE(world, nullptr);
	t_hit *result = world->objects[0];
	ASSERT_EQ(result->shape, SPHERE);
	t_plane *plane = (t_plane *)result->hit;
	ASSERT_EQ(plane->center.x, 0);
	ASSERT_EQ(plane->center.y, 0);
	ASSERT_EQ(plane->center.z, 20);
	ASSERT_EQ(plane->normal.x, 0);
	ASSERT_EQ(plane->normal.y, 0);
	ASSERT_EQ(plane->normal.z, 1);
	ASSERT_EQ(plane->color.x, 255);
	ASSERT_EQ(plane->color.y, 255);
	ASSERT_EQ(plane->color.z, 255);
}
