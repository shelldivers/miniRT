extern "C" {
#include "minirt.h"
#include "shape/cylinder.h"
}
#include "gtest/gtest.h"


TEST(parse_cylinder_test, basic_case)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255";

    parse_cylinder(line, &rt);
    t_hit *result = rt.world->objects[0];
    ASSERT_EQ(result->shape, CYLINDER);
    t_cylinder *cylinder = (t_cylinder *)result;
    ASSERT_EQ(cylinder->center.x, 0);
    ASSERT_EQ(cylinder->center.y, 0);
    ASSERT_EQ(cylinder->center.z, 20);
    ASSERT_EQ(cylinder->normal.x, 0);
    ASSERT_EQ(cylinder->normal.y, 0);
    ASSERT_EQ(cylinder->normal.z, 1);
    ASSERT_EQ(cylinder->radius, 5);
    ASSERT_EQ(cylinder->height, 5);
    ASSERT_EQ(cylinder->color.x, 1);
    ASSERT_EQ(cylinder->color.y, 1);
    ASSERT_EQ(cylinder->color.z, 1);
}

TEST(parse_cylinder_test, success_with_last_space)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255 ";

    parse_cylinder(line, &rt);
    t_hit *result = rt.world->objects[0];
    ASSERT_EQ(result->shape, CYLINDER);
    t_cylinder *cylinder = (t_cylinder *)result;
    ASSERT_EQ(cylinder->center.x, 0);
    ASSERT_EQ(cylinder->center.y, 0);
    ASSERT_EQ(cylinder->center.z, 20);
    ASSERT_EQ(cylinder->normal.x, 0);
    ASSERT_EQ(cylinder->normal.y, 0);
    ASSERT_EQ(cylinder->normal.z, 1);
    ASSERT_EQ(cylinder->radius, 5);
    ASSERT_EQ(cylinder->height, 5);
    ASSERT_EQ(cylinder->color.x, 1);
    ASSERT_EQ(cylinder->color.y, 1);
    ASSERT_EQ(cylinder->color.z, 1);
}

TEST(parse_cylinder_test, invalid)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line;

    line = (char *)"cy	0,20	0,0,1	10	5	255,255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5,5	255,255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255	255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255	255,";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255	255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}

TEST(parse_cylinder_test, no_nums_in_vec)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char *line = (char *)"cy	0,0,20	,,	10	5	255,255,255	255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}

TEST(parse_cylinder_test, invalid_param)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"cy	0,0	0,0,1	10.2	10.4	255,255,255";

    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}

TEST(parse_cylinder_test, invalid_param2)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"cy	0,0	0,0,1	10.2	10,4,0	255,255,255";

    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}

TEST(parse_cylinder_test, 색상값이_0_미만인_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	-1,255,255";

    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}

TEST(parse_cylinder_test, 색상값이_255_초과인_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	256,255,255";

    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}

TEST(parse_cylinder_test, normal_vector가_범위를_벗어난_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line;
    
    
    line = (char *)"cy	0,0,20	0,0,-1.1	10	5	254,255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);

    line = (char *)"cy	0,0,20	1.0,1.1,-0	10	5	254,255,255";
    ASSERT_THROW(parse_cylinder(line, &rt), std::runtime_error);
}
