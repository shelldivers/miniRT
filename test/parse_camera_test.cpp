extern "C" {
#include "minirt.h"
#include "camera.h"
}
#include "gtest/gtest.h"

TEST(parse_camera_test, 성공)
{
	t_cam	camera;
	char	*line = (char *)"C	-50.0,0,20	0,0,1	70";

	parse_camera(line, &camera);
	ASSERT_FLOAT_EQ(camera.view_point.x, -50);
	ASSERT_FLOAT_EQ(camera.view_point.y, 0);
	ASSERT_FLOAT_EQ(camera.view_point.z, 20);
	ASSERT_FLOAT_EQ(camera.normal.x, 0);
	ASSERT_FLOAT_EQ(camera.normal.y, 0);
	ASSERT_FLOAT_EQ(camera.normal.z, 1);
	ASSERT_FLOAT_EQ(camera.fov, 70);
}

TEST(parse_camera_test, 뒤에_공백이_있는_경우)
{
	t_cam	camera;
	char	*line = (char *)"C	-50.0,0,20	0,0,1	70";

	parse_camera(line, &camera);
	ASSERT_FLOAT_EQ(camera.view_point.x, -50);
	ASSERT_FLOAT_EQ(camera.view_point.y, 0);
	ASSERT_FLOAT_EQ(camera.view_point.z, 20);
	ASSERT_FLOAT_EQ(camera.normal.x, 0);
	ASSERT_FLOAT_EQ(camera.normal.y, 0);
	ASSERT_FLOAT_EQ(camera.normal.z, 1);
	ASSERT_FLOAT_EQ(camera.fov, 70);
}

TEST(parse_camera_test, 뒤에_추가_숫자가_있는_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,0,20	0,0,1	70 1";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, 뒤에_추가_벡터가_있는_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,0,20	0,0,1	70 1,2,4";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, 마지막_숫자가_벡터인_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,0,20	0,0,1	1,2,4";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, FOV가_0에서_180사이가_아닌_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,0,20	0,0,1	-1";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);

	line = (char *)"C	-50.0,0,20	0,0,1	181";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, 빈_문자열_인_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, 벡터가_빈_문자열인_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,1,20	0,0,	70";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, 음수_음수_부호가_들어오는_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,1,20	0,0,1	--70";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}

TEST(parse_camera_test, 양수_음수_부호가_들어오는_경우)
{
	t_cam	camera;
	char	*line;

	line = (char *)"C	-50.0,1,20	0,0,1	+-70";
	ASSERT_THROW(parse_camera(line, &camera), std::runtime_error);
}
