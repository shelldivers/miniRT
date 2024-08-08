extern "C" {
#include "minirt.h"
#include "shape/plane.h"
}
#include "gtest/gtest.h"

TEST(parse_plane_test, basic_case)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line = (char *)"pl	0,0,20	0,0,1	255,255,255";

	parse_plane(line, world);
	ASSERT_NE(world, nullptr);
	t_hit *result = world->objects[0];
	ASSERT_EQ(result->shape, PLANE);
	t_plane *plane = (t_plane *)result;
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

TEST(parse_plane_test, success_with_last_space)
{	t_hit_lst	*world = init_hittable_list(10);
	char		*line = (char *)"pl	0,0,20	0,0,1	255,255,255 ";
	
	parse_plane(line, world);
	ASSERT_NE(world, nullptr);
	t_hit *result = world->objects[0];
	ASSERT_EQ(result->shape, PLANE);
	t_plane *plane = (t_plane *)result;
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

TEST(parse_plane_test, invalid)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line;
	
	line = (char *)"pl	0,20	0,0,1	255,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255	255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255	255,";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255	255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);
}

TEST(parse_plane_test, invalid_param)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line;
	
	line = (char *)"pl	0,0,20	0,0,1	255,255,a";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,a	255,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,a,1	255,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,a,1	255,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	a,0,1	255,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,a,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	a,255,255";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,a";
	ASSERT_THROW(parse_plane(line, world), std::runtime_error);
}

TEST(parse_plane_test, empty)
{
	t_hit_lst	*world = init_hittable_list(10);
	ASSERT_THROW(parse_plane("", world), std::runtime_error);
}

// TEST(parse_plane_test, empty_vec3)
// {
// 	t_hit_lst	*world = init_hittable_list(10);
// 	ASSERT_THROW(parse_plane("pl ,, 10,10,0 255,255,255", world), std::runtime_error);
// }
