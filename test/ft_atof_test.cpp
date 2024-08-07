extern "C" {
#include "libft.h"
}
#include "gtest/gtest.h"
#include <string>
#include <random>

TEST(ft_atof_test, ft_atof_test)
{
	std::random_device rd;  // 랜덤한 시드를 생성합니다.
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 난수 생성기를 초기화합니다.
	std::uniform_real_distribution<> dis(FLT_MIN, FLT_MAX); // 0.0과 1.0 사이의 균일 분포를 정의합니다.

	for (int i = 0; i < 10000; i++) {
		float random_float = dis(gen); // 랜덤한 float 값을 생성합니다.
		std::string str = std::to_string(random_float);
		const char *nbr = str.c_str();
		float a = ft_atof(nbr);
		float b = atof(nbr);
		ASSERT_FLOAT_EQ(a, b);
	}
}

TEST(ft_atof_test, negative)
{
	std::random_device rd;  // 랜덤한 시드를 생성합니다.
	std::mt19937 gen(rd()); // Mersenne Twister 알고리즘을 사용하는 난수 생성기를 초기화합니다.
	std::uniform_real_distribution<> dis(FLT_MIN, FLT_MAX); // 0.0과 1.0 사이의 균일 분포를 정의합니다.

	for (int i = 0; i < 10000; i++) {
		float random_float = dis(gen); // 랜덤한 float 값을 생성합니다.
		std::string str = std::to_string(random_float * -1);
		const char *nbr = str.c_str();
		float a = ft_atof(nbr);
		float b = atof(nbr);
		ASSERT_FLOAT_EQ(a, b);
	}
}

TEST(ft_atof_test, no_num)
{
	float a = ft_atof("10.");
	float b = atof("10.");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof(".");
	b = atof(".");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof(".01");
	b = atof(".01");
	ASSERT_FLOAT_EQ(a, b);
}

TEST(ft_atof_test, no_decimal)
{
	float a = ft_atof("10");
	float b = atof("10");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof("");
	b = atof("");
	ASSERT_FLOAT_EQ(a, b);
}

TEST(ft_atof_test, invalid)
{
	float a = ft_atof("10a");
	float b = atof("10a");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof("10.1.1");
	b = atof("10.1.1");
	ASSERT_FLOAT_EQ(a, b);
}

TEST(ft_atof_test, invalid2)
{
	float a = ft_atof("A110");
	float b = atof("A110");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof("B10.1.1");
	b = atof("B10.1.1");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof("1123..");
	b = atof("1123..");
	ASSERT_FLOAT_EQ(a, b);
}

TEST(ft_atof_test, invalid3)
{
	float a = ft_atof("--110");
	float b = atof("--110");
	ASSERT_FLOAT_EQ(a, b);

	a = ft_atof("++10.1.1");
	b = atof("++10.1.1");
	ASSERT_FLOAT_EQ(a, b);
}
