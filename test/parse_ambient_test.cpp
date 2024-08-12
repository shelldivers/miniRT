extern "C" {
#include "minirt.h"
#include "reflection.h"
}
#include "gtest/gtest.h"

TEST(parse_ambient_test, 성공)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line = (char *)"A 0.5 255,255,255";

    parse_ambient(line, &rt);
    ASSERT_FLOAT_EQ(rt.ambient.ratio, 0.5);
    ASSERT_FLOAT_EQ(rt.ambient.color.x, 1);
    ASSERT_FLOAT_EQ(rt.ambient.color.y, 1);
    ASSERT_FLOAT_EQ(rt.ambient.color.z, 1);
}

TEST(parse_ambient_test, ratio가_벡터로_들어온_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line = (char *)"A 0.12,4,1 255,255,255";

    ASSERT_THROW(parse_ambient(line, &rt), std::runtime_error);
}

TEST(parse_ambient_test, color가_범위를_벗어난_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line;
    
    line = (char *)"A 0.12 255,255,256";
    ASSERT_THROW(parse_ambient(line, &rt), std::runtime_error);

    line = (char *)"A 0.12 -1,255,254";
    ASSERT_THROW(parse_ambient(line, &rt), std::runtime_error);
}

TEST(parse_ambient_test, ratio가_범위를_벗어난_경우)
{
    t_rt 	rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);
	char		*line;
    
    line = (char *)"A 1.54 255,255,234";
    ASSERT_THROW(parse_ambient(line, &rt), std::runtime_error);

    line = (char *)"A -0.001 255,255,234";
    ASSERT_THROW(parse_ambient(line, &rt), std::runtime_error);
}
