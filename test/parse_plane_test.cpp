extern "C" {
#include "minirt.h"
#include "shape/plane.h"
}
#include "gtest/gtest.h"

TEST(parse_plane_test, basic_case)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	char		*line = (char *)"pl	0,0,20	0,0,1	255,255,255";

	parse_plane(line, &rt);
	t_hit *result = rt.world->objects[0];
	ASSERT_EQ(result->shape, PLANE);
	t_plane *plane = (t_plane *)result;
	ASSERT_EQ(plane->center.x, 0);
	ASSERT_EQ(plane->center.y, 0);
	ASSERT_EQ(plane->center.z, 20);
	ASSERT_EQ(plane->normal.x, 0);
	ASSERT_EQ(plane->normal.y, 0);
	ASSERT_EQ(plane->normal.z, 1);
	ASSERT_EQ(plane->parent.color.x, 1);
	ASSERT_EQ(plane->parent.color.y, 1);
	ASSERT_EQ(plane->parent.color.z, 1);
}

TEST(parse_plane_test, success_with_last_space)
{	t_rt 	rt;
	rt.world = init_hittable_list(10);
	char		*line = (char *)"pl	0,0,20	0,0,1	255,255,255 ";
	
	parse_plane(line, &rt);
	t_hit *result = rt.world->objects[0];
	ASSERT_EQ(result->shape, PLANE);
	t_plane *plane = (t_plane *)result;
	ASSERT_EQ(plane->center.x, 0);
	ASSERT_EQ(plane->center.y, 0);
	ASSERT_EQ(plane->center.z, 20);
	ASSERT_EQ(plane->normal.x, 0);
	ASSERT_EQ(plane->normal.y, 0);
	ASSERT_EQ(plane->normal.z, 1);
	ASSERT_EQ(plane->parent.color.x, 1);
	ASSERT_EQ(plane->parent.color.y, 1);
	ASSERT_EQ(plane->parent.color.z, 1);

}

TEST(parse_plane_test, invalid)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	char		*line;
	
	line = (char *)"pl	0,20	0,0,1	255,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255	255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255	255,";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,255	255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);
}

TEST(parse_plane_test, invalid_param)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	char		*line;
	
	line = (char *)"pl	0,0,20	0,0,1	255,255,a";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,a	255,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,a,1	255,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,a,1	255,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	a,0,1	255,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,a,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	a,255,255";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl	0,0,20	0,0,1	255,255,a";
	ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);
}

TEST(parse_plane_test, empty)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	ASSERT_THROW(parse_plane("", &rt), std::runtime_error);
}

TEST(parse_plane_test, empty_vec3)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	ASSERT_THROW(parse_plane("pl ,, 10,10,0 255,255,255", &rt), std::runtime_error);
}

TEST(parse_plane_test, 색상값이_0_미만인_경우)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	ASSERT_THROW(parse_plane("pl 0,0,20 1,2,3 255,255,-1", &rt), std::runtime_error);
}

TEST(parse_plane_test, 색상값이_255_초과인_경우)
{
	t_rt 	rt;
	rt.world = init_hittable_list(10);
	ASSERT_THROW(parse_plane("pl 0,0,20 1,2,3 255,255,256", &rt), std::runtime_error);
}

TEST(parse_plane_test, normal_vector가_범위를_벗어난_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line;
    
    
    line = (char *)"pl 0.0,0.0,-10.0 0.0,-1.1,0.0 0,0,225";
    ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);

	line = (char *)"pl 0.0,0.0,-10.0 0.0,1.1,0.0 0,0,225";
    ASSERT_THROW(parse_plane(line, &rt), std::runtime_error);
}
