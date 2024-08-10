extern "C" {
#include "minirt.h"
#include "shape/cylinder.h"
}
#include "gtest/gtest.h"


TEST(parse_cylinder_test, basic_case)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255";

    parse_cylinder(line, &cam, world);
    ASSERT_NE(world, nullptr);
    t_hit *result = world->objects[0];
    ASSERT_EQ(result->shape, CYLINDER);
    t_cylinder *cylinder = (t_cylinder *)result;
    ASSERT_EQ(cylinder->center.x, 0);
    ASSERT_EQ(cylinder->center.y, 0);
    ASSERT_EQ(cylinder->center.z, 20);
    ASSERT_EQ(cylinder->normal.x, 0);
    ASSERT_EQ(cylinder->normal.y, 0);
    ASSERT_EQ(cylinder->normal.z, 1);
    ASSERT_EQ(cylinder->diameter, 10);
    ASSERT_EQ(cylinder->height, 5);
    ASSERT_EQ(cylinder->color.x, 255);
    ASSERT_EQ(cylinder->color.y, 255);
    ASSERT_EQ(cylinder->color.z, 255);
}

TEST(parse_cylinder_test, success_with_last_space)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255 ";

    parse_cylinder(line, &cam, world);
    ASSERT_NE(world, nullptr);
    t_hit *result = world->objects[0];
    ASSERT_EQ(result->shape, CYLINDER);
    t_cylinder *cylinder = (t_cylinder *)result;
    ASSERT_EQ(cylinder->center.x, 0);
    ASSERT_EQ(cylinder->center.y, 0);
    ASSERT_EQ(cylinder->center.z, 20);
    ASSERT_EQ(cylinder->normal.x, 0);
    ASSERT_EQ(cylinder->normal.y, 0);
    ASSERT_EQ(cylinder->normal.z, 1);
    ASSERT_EQ(cylinder->diameter, 10);
    ASSERT_EQ(cylinder->height, 5);
    ASSERT_EQ(cylinder->color.x, 255);
    ASSERT_EQ(cylinder->color.y, 255);
    ASSERT_EQ(cylinder->color.z, 255);
}

TEST(parse_cylinder_test, invalid)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam        cam;
    char		*line;

    line = (char *)"cy	0,20	0,0,1	10	5	255,255,255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5,5	255,255,255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255,255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255	255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255	255,";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);

    line = (char *)"cy	0,0,20	0,0,1	10	5	255,255,255	255,255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);
}

TEST(parse_cylinder_test, no_nums_in_vec)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char *line = (char *)"cy	0,0,20	,,	10	5	255,255,255	255,255";
    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);
}

TEST(parse_cylinder_test, invalid_param)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char		*line = (char *)"cy	0,0	0,0,1	10.2	10.4	255,255,255";

    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);
}

TEST(parse_cylinder_test, invalid_param2)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char		*line = (char *)"cy	0,0	0,0,1	10.2	10,4,0	255,255,255";

    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);
}

TEST(parse_cylinder_test, 색상값이_0_미만인_경우)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	-1,255,255";

    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);
}

TEST(parse_cylinder_test, 색상값이_255_초과인_경우)
{
    t_hit_lst	*world = init_hittable_list(10);
    t_cam       cam;
    char		*line = (char *)"cy	0,0,20	0,0,1	10	5	256,255,255";

    ASSERT_THROW(parse_cylinder(line, &cam, world), std::runtime_error);
}