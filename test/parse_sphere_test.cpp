extern "C" {
#include "minirt.h"
#include "shape/sphere.h"
}
#include "gtest/gtest.h"

TEST(parse_sphere_test, basic_case)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line = (char *)"sp	0,0,20	10	255,255,255";

	parse_sphere(line, world);
	ASSERT_NE(world, nullptr);
	t_hit *result = world->objects[0];
	ASSERT_EQ(result->shape, SPHERE);
	t_sphere *sphere = (t_sphere *)result;
	ASSERT_EQ(sphere->center.x, 0);
	ASSERT_EQ(sphere->center.y, 0);
	ASSERT_EQ(sphere->center.z, 20);
	ASSERT_EQ(sphere->radius, 5);
	ASSERT_EQ(sphere->color.x, 255);
	ASSERT_EQ(sphere->color.y, 255);
	ASSERT_EQ(sphere->color.z, 255);
}

TEST(parse_sphere_test, invalid)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line;
	
	line = (char *)"sp	0,20	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,20	10,10,10	255,255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255	255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255	255,";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255	255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);
}

TEST(parse_sphere_test, success_with_last_space)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line = (char *)"sp	0,0,20	10	255,255,255 ";

	parse_sphere(line, world);
	ASSERT_NE(world, nullptr);
	t_hit *result = world->objects[0];
	ASSERT_EQ(result->shape, SPHERE);
	t_sphere *sphere = (t_sphere *)result;
	ASSERT_EQ(sphere->center.x, 0);
	ASSERT_EQ(sphere->center.y, 0);
	ASSERT_EQ(sphere->center.z, 20);
	ASSERT_EQ(sphere->radius, 5);
	ASSERT_EQ(sphere->color.x, 255);
	ASSERT_EQ(sphere->color.y, 255);
	ASSERT_EQ(sphere->color.z, 255);
}

TEST(parse_sphere_test, invalid_param)
{
	t_hit_lst	*world = init_hittable_list(10);
	char		*line;
	
	line = (char *)"sp	0,a,20	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	0,0,a	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);

	line = (char *)"sp	a,0,20	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, world), std::runtime_error);
}
