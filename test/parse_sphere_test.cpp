extern "C" {
#include "minirt.h"
#include "shape/sphere.h"
}
#include "gtest/gtest.h"

TEST(parse_sphere_test, basic_case)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	char		*line = (char *)"sp	0,0,20	10	255,255,255";

	parse_sphere(line, &cam, world);
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
	t_cam		cam;
	char		*line;
	
	line = (char *)"sp	0,20	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,20	10,10,10	255,255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255	255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255	255,";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,0,20	10	255,255,255	255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);
}

TEST(parse_sphere_test, success_with_last_space)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	char		*line = (char *)"sp	0,0,20	10	255,255,255 ";

	parse_sphere(line, &cam, world);
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
	t_cam		cam;
	char		*line;
	
	line = (char *)"sp	0,a,20	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	0,0,a	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);

	line = (char *)"sp	a,0,20	10	255,255,255";
	ASSERT_THROW(parse_sphere(line, &cam, world), std::runtime_error);
}

TEST(parse_sphere_test, empty)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	ASSERT_THROW(parse_sphere("", &cam, world), std::runtime_error);
}

TEST(parse_sphere_test, empty_vec3)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	ASSERT_THROW(parse_sphere("sp ,, 10 255,255,255", &cam, world), std::runtime_error);
}

TEST(parse_sphere_test, empty_color)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	ASSERT_THROW(parse_sphere("sp 0,0,20 10", &cam, world), std::runtime_error);
}

TEST(parse_sphere_test, empty_param)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	ASSERT_THROW(parse_sphere("sp", &cam, world), std::runtime_error);
}

TEST(parse_sphere_test, 색상값이_0_255범위를_벗어난_경우)
{
	t_hit_lst	*world = init_hittable_list(10);
	t_cam		cam;
	ASSERT_THROW(parse_sphere("sp 0,0,20 10 256,255,255", &cam, world), std::runtime_error);
	ASSERT_THROW(parse_sphere("sp 0,0,20 10 255,256,255", &cam, world), std::runtime_error);
	ASSERT_THROW(parse_sphere("sp 0,0,20 10 255,255,256", &cam, world), std::runtime_error);
	ASSERT_THROW(parse_sphere("sp 0,0,20 10 -1,255,255", &cam, world), std::runtime_error);
	ASSERT_THROW(parse_sphere("sp 0,0,20 10 255,-1,255", &cam, world), std::runtime_error);
	ASSERT_THROW(parse_sphere("sp 0,0,20 10 255,255,-1", &cam, world), std::runtime_error);
}