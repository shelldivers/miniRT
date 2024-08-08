extern "C" {
#include "minirt.h"
}
#include "gtest/gtest.h"
#include <string>
#include <random>

TEST(parse_vec3_test, basic_case)
{
	std::random_device rd;  // 랜덤한 시드를 생성합니다.
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 난수 생성기를 초기화합니다.
	std::uniform_real_distribution<> dis(0.0, 1.0); // 0.0과 1.0 사이의 균일 분포를 정의합니다.
	std::ostringstream out;

	for (int i = 0; i < 1000; i++) {
		out.str("");
		float flt_x = dis(gen); // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_x;
		std::string str_x = out.str();

		out.str("");
		float flt_y = dis(gen); // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_y;
		std::string str_y = out.str();

		out.str("");
		float flt_z = dis(gen); // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_z;
		std::string str_z = out.str();

		std::string str = str_x + "," + str_y + "," + str_z;
		const char *nbr = str.c_str();

		t_vec3 vec = parse_vec3(nbr);
		ASSERT_NEAR(vec.x, flt_x, 0.0000001);
		ASSERT_NEAR(vec.y, flt_y, 0.0000001);
		ASSERT_NEAR(vec.z, flt_z, 0.0000001);
	}
}

TEST(parse_vec3_test, min_max)
{
	std::random_device rd;  // 랜덤한 시드를 생성합니다.
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 난수 생성기를 초기화합니다.
	std::uniform_real_distribution<> dis(FLT_MIN, FLT_MAX); // 0.0과 1.0 사이의 균일 분포를 정의합니다.
	std::ostringstream out;

	for (int i = 0; i < 1000; i++) {
		out.str("");
		float flt_x = dis(gen); // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_x;
		std::string str_x = out.str();

		out.str("");
		float flt_y = dis(gen); // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_y;
		std::string str_y = out.str();

		out.str("");
		float flt_z = dis(gen); // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_z;
		std::string str_z = out.str();

		std::string str = str_x + "," + str_y + "," + str_z;
		const char *nbr = str.c_str();

		t_vec3 vec = parse_vec3(nbr);
		ASSERT_NEAR(vec.x, flt_x, 0.0000001);
		ASSERT_NEAR(vec.y, flt_y, 0.0000001);
		ASSERT_NEAR(vec.z, flt_z, 0.0000001);
	}
}

TEST(parse_vec3_test, negative)
{
	std::random_device rd;  // 랜덤한 시드를 생성합니다.
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 난수 생성기를 초기화합니다.
	std::uniform_real_distribution<> dis(FLT_MIN, FLT_MAX); // 0.0과 1.0 사이의 균일 분포를 정의합니다.
	std::ostringstream out;

	for (int i = 0; i < 1000; i++) {
		out.str("");
		float flt_x = dis(gen) * -1; // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_x;
		std::string str_x = out.str();

		out.str("");
		float flt_y = dis(gen) * -1; // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_y;
		std::string str_y = out.str();

		out.str("");
		float flt_z = dis(gen) * -1; // 랜덤한 float 값을 생성합니다.
		out << std::fixed << std::setprecision(9) << flt_z;
		std::string str_z = out.str();

		std::string str = str_x + "," + str_y + "," + str_z;
		const char *nbr = str.c_str();

		t_vec3 vec = parse_vec3(nbr);
		ASSERT_NEAR(vec.x, flt_x, 0.0000001);
		ASSERT_NEAR(vec.y, flt_y, 0.0000001);
		ASSERT_NEAR(vec.z, flt_z, 0.0000001);
	}
}

TEST(parse_vec3_test, more_than_3)
{
	ASSERT_THROW(parse_vec3("1,2,3,4,5"), std::runtime_error);
}

TEST(parse_vec3_test, no_num)
{
	t_vec3 vec = parse_vec3(",,");
	ASSERT_FLOAT_EQ(vec.x, 0);
	ASSERT_FLOAT_EQ(vec.y, 0);
	ASSERT_FLOAT_EQ(vec.z, 0);

	vec = parse_vec3("a,b,c");
	ASSERT_FLOAT_EQ(vec.x, 0);
	ASSERT_FLOAT_EQ(vec.y, 0);
	ASSERT_FLOAT_EQ(vec.z, 0);
}

TEST(parse_vec3_test, invalid_param)
{
	t_vec3 vec = parse_vec3("1,a,3");
	ASSERT_FLOAT_EQ(vec.x, 1);
	ASSERT_FLOAT_EQ(vec.y, 0);
	ASSERT_FLOAT_EQ(vec.z, 3);
}

TEST(parse_vec3_test, no_comma)
{
	ASSERT_THROW(parse_vec3("1a3"), std::runtime_error);
	ASSERT_THROW(parse_vec3("..."), std::runtime_error);
}

TEST(parse_vec3_test, one_comma)
{
	ASSERT_THROW(parse_vec3("1.3,"), std::runtime_error);
	ASSERT_THROW(parse_vec3(",1.3"), std::runtime_error);
}

TEST(parse_vec3_test, two_comma)
{
	t_vec3 vec = parse_vec3("1a3,,");
	ASSERT_FLOAT_EQ(vec.x, 1);
	ASSERT_FLOAT_EQ(vec.y, 0);
	ASSERT_FLOAT_EQ(vec.z, 0);

	vec = parse_vec3(",1a3,");
	ASSERT_FLOAT_EQ(vec.x, 0);
	ASSERT_FLOAT_EQ(vec.y, 1);
	ASSERT_FLOAT_EQ(vec.z, 0);

	vec = parse_vec3(",,1a3");
	ASSERT_FLOAT_EQ(vec.x, 0);
	ASSERT_FLOAT_EQ(vec.y, 0);
	ASSERT_FLOAT_EQ(vec.z, 1);
}

TEST(parse_vec3_test, empty)
{
	ASSERT_THROW(parse_vec3(""), std::runtime_error);
}