extern "C" {
#include "minirt.h"
#include "shape/cone.h"
#include "parse.h"
}
#include "gtest/gtest.h"

TEST(parse_cone_test, 성공)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)"co	0,0,20	0,0,1	10	5	255,255,255";

    parse_cylinder(line, &rt);
    t_hit *result = rt.world->objects[0];
    ASSERT_EQ(result->shape, CYLINDER);
    t_cone *cone = (t_cone *)result;
    ASSERT_FLOAT_EQ(cone->center.x, 0);
    ASSERT_FLOAT_EQ(cone->center.y, 0);
    ASSERT_FLOAT_EQ(cone->center.z, 20);
    ASSERT_FLOAT_EQ(cone->normal.x, 0);
    ASSERT_FLOAT_EQ(cone->normal.y, 0);
    ASSERT_FLOAT_EQ(cone->normal.z, 1);
    ASSERT_FLOAT_EQ(cone->radius, 5);
    ASSERT_FLOAT_EQ(cone->height, 5);
    ASSERT_FLOAT_EQ(cone->parent.color.x, 1);
    ASSERT_FLOAT_EQ(cone->parent.color.y, 1);
    ASSERT_FLOAT_EQ(cone->parent.color.z, 1);
}


TEST(parse_cone_test, 식별자_앞에_문자가_있는_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)" co	0,0,20	0,0,1	10	5	255,255,255";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}

TEST(parse_cone_test, 식별자_뒤에_구분자가_없는_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    char		*line = (char *)" co0,0,20	0,0,1	10	5	255,255,255";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}

TEST(parse_cone_test, 법선_벡터가_범위를_벗어난_경우)
{
    t_rt 	rt;
    rt.world = init_hittable_list(10);
    char *line = (char *)"co	0,0,20	0,0,1.1	10	5	255,255,255";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}

TEST(parse_cone_test, 반지름이_음수인_경우)
{
    t_rt 	rt;
    rt.world = init_hittable_list(10);
    char *line = (char *)"co	0,0,20	0,0,1	-10	5	255,255,255";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}

TEST(parse_cone_test, 높이가_음수인_경우)
{
    t_rt 	rt;
    rt.world = init_hittable_list(10);
    char		*line = (char *)"co	0,0,20	0,0,1	10	-5	255,255,255";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}

TEST(parse_cone_test, 색상이_255를_벗어난_경우)
{
    t_rt 	rt;
    rt.world = init_hittable_list(10);
    char *line = (char *)"co	0,0,20	0,0,1	10	5	255,255,256";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}

TEST(parse_cone_test, 색상이_음수인_경우)
{
    t_rt 	rt;
    rt.world = init_hittable_list(10);
    char *line = (char *)"co	0,0,20	0,0,1	10	5	255,255,-1";

    ASSERT_THROW(parse_cone(line, &rt), std::runtime_error);
}
