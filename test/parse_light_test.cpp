extern "C" {
#include "minirt.h"
#include "reflection.h"
}
#include "gtest/gtest.h"

TEST(parse_light_test, 성공)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line = (char *)"L 0,0,0 0.5 255,255,255";

    parse_light(line, &rt);
    t_light *result = rt.lights->objects[0];
    ASSERT_FLOAT_EQ(result->center.x, 0);
    ASSERT_FLOAT_EQ(result->center.y, 0);
    ASSERT_FLOAT_EQ(result->center.z, 0);
    ASSERT_FLOAT_EQ(result->ratio, 0.5);
    ASSERT_FLOAT_EQ(result->color.x, 1);
    ASSERT_FLOAT_EQ(result->color.y, 1);
    ASSERT_FLOAT_EQ(result->color.z, 1);
}

TEST(parse_light_test, ratio가_벡터로_들어온_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line = (char *)"L 0,0,0 0.12,4,1 255,255,255";

    ASSERT_THROW(parse_light(line, &rt), std::runtime_error);
}

TEST(parse_light_test, color가_범위를_벗어난_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line;
    
    line = (char *)"L 0,0,0 0.12 255,255,256";
    ASSERT_THROW(parse_light(line, &rt), std::runtime_error);

    line = (char *)"L 0,0,0 0.12 -1,255,254";
    ASSERT_THROW(parse_light(line, &rt), std::runtime_error);
}

TEST(parse_light_test, ratio가_범위를_벗어난_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line;
    
    line = (char *)"L 0,0,0 1.54 255,255,234";
    ASSERT_THROW(parse_light(line, &rt), std::runtime_error);

    line = (char *)"L 0,0,0 -0.001 255,255,234";
    ASSERT_THROW(parse_light(line, &rt), std::runtime_error);
}
