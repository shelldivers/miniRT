extern "C" {
#include "minirt.h"
#include "shape/hittable.h"
#include "mlx.h"
}
#include <fstream>
#include "gtest/gtest.h"

TEST(parse_texture_test, 성공_체커보드)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line = (char *)"255,255,255 -c 0,0,20 2 2";

	parse_texture(&rt, &obj, (char const **)&line);
    EXPECT_EQ(obj.texture.enable, CHECKER_BOARD);
    EXPECT_FLOAT_EQ(obj.texture.color.x, 0);
    EXPECT_FLOAT_EQ(obj.texture.color.y, 0);
    EXPECT_FLOAT_EQ(obj.texture.color.z, 20 / 255.0);
    EXPECT_FLOAT_EQ(obj.texture.width_count, 2);
    EXPECT_FLOAT_EQ(obj.texture.height_count, 2);
}

TEST(parse_texture_test, 성공_텍스처맵)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line = (char *)"255,255,255 -t ./resources/42.xpm";

	parse_texture(&rt, &obj, (char const **)&line);
    EXPECT_EQ(obj.texture.enable, TEXTURE_MAP);
}

TEST(parse_texture_test, 성공_범프맵)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line = (char *)"255,255,255 -b ./resources/42.xpm";

	parse_texture(&rt, &obj, (char const **)&line);
    EXPECT_EQ(obj.texture.enable, BUMP_MAP);
}

TEST(parse_texture_test, 성공_체커보드와_범프맵이_같이_들어오는_경우)
{
    t_rt 	rt;
    t_hit   obj1;
    t_hit   obj2;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,20 2 2 -b ./resources/42.xpm";
	parse_texture(&rt, &obj1, (char const **)&line);
    EXPECT_EQ(obj1.texture.enable, BUMP_MAP | CHECKER_BOARD);

    line = (char *)"255,255,255 -b ./resources/42.xpm -c 0,0,20 2 2";
	parse_texture(&rt, &obj2, (char const **)&line);
    EXPECT_EQ(obj2.texture.enable, BUMP_MAP | CHECKER_BOARD);
}

TEST(parse_texture_test, 성공_텍스처맵과_범프맵이_같이_들어오는_경우)
{
    t_rt 	rt;
    t_hit   obj1;
    t_hit   obj2;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -t ./resources/42.xpm -b ./resources/42.xpm";
	parse_texture(&rt, &obj1, (char const **)&line);
    EXPECT_EQ(obj1.texture.enable, BUMP_MAP | TEXTURE_MAP);

    line = (char *)"255,255,255 -b ./resources/42.xpm -t ./resources/42.xpm";
	parse_texture(&rt, &obj2, (char const **)&line);
    EXPECT_EQ(obj2.texture.enable, BUMP_MAP | TEXTURE_MAP);
}


/**
 * 체커보드와 텍스처맵이 같이 들어오는 경우
 * uv_color_map_adapter에서 예외처리
 * @see texture.c
 */
TEST(parse_texture_test, 성공_체커보드와_텍스처맵이_같이_들어오는_경우)
{
    t_rt 	rt;
    t_hit   obj1;
    t_hit   obj2;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,20 2 2 -t ./resources/42.xpm";
	parse_texture(&rt, &obj1, (char const **)&line);
    EXPECT_EQ(obj1.texture.enable, TEXTURE_MAP | CHECKER_BOARD);

    line = (char *)"255,255,255 -t ./resources/42.xpm -c 0,0,20 2 2";
	parse_texture(&rt, &obj2, (char const **)&line);
    EXPECT_EQ(obj2.texture.enable, TEXTURE_MAP | CHECKER_BOARD);
}

TEST(parse_texture_test, 성공_2개_이상의_같은_텍스처가_들어오는_경우)
{
    t_rt 	rt;
    t_hit   obj1;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,20 2 2 -c 0,0,20 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj1, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -t ./resources/42.xpm -t ./resources/42.xpm";
	ASSERT_THROW(parse_texture(&rt, &obj1, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -b ./resources/42.xpm -b ./resources/42.xpm";
    ASSERT_THROW(parse_texture(&rt, &obj1, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 입력_문자열에_이전_파라미터가_공백으로_들어온_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)" -c 0,0,20 2 2";
    parse_texture(&rt, &obj, (char const **)&line);
    EXPECT_EQ(obj.texture.enable, true);
    EXPECT_FLOAT_EQ(obj.texture.color.x, 0);
    EXPECT_FLOAT_EQ(obj.texture.color.y, 0);
    EXPECT_FLOAT_EQ(obj.texture.color.z, 20 / 255.0);
    EXPECT_FLOAT_EQ(obj.texture.width_count, 2);
    EXPECT_FLOAT_EQ(obj.texture.height_count, 2);
}

TEST(parse_texture_test, 입력_문자열에_이전_파라미터가_없는_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"-c 0,0,20 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 색상값이_누락된_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;

    line = (char *)"255,255,255 -c 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 색상값이_2개만_들어온_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -c 0,0, 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 색상값이_255이상인_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,256 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}


TEST(parse_texture_test, 색상값이_0미만인_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,-1 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 가로_세로_값이_누락된_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,255";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -c 0,0,255 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 가로_세로_값이_벡터로_들어온_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,255 2,3";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -c 0,0,255 2,3 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}

TEST(parse_texture_test, 가로_세로_값이_음수인_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -c 0,0,255 -2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -c 0,0,255 2 -2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -c 0,0,255 -2 -2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}


TEST(parse_texture_test, 식별자_옵션에_추가_문자가_있는_겨우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -ca 0,0,255 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -c1 0,0,255 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}


TEST(parse_texture_test, 없는_식별자인_경우)
{
    t_rt 	rt;
    t_hit   obj;
	rt.world = init_hittable_list(10);
	char		*line;
    
    line = (char *)"255,255,255 -z 0,0,255 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);

    line = (char *)"255,255,255 -a 0,0,255 2 2";
    ASSERT_THROW(parse_texture(&rt, &obj, (char const **)&line), std::runtime_error);
}
