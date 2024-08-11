extern "C" {
#include "minirt.h"
}
#include "gtest/gtest.h"

TEST(extension_valid_test, 성공)
{
	char const *filename = (char const *)"example.rt";

	ASSERT_NO_THROW(must_be_rt_extension(filename));
}

TEST(extension_valid_test, 경로가_추가된_경우)
{
	char const *filename = (char const *)"test/example.rt";

	ASSERT_NO_THROW(must_be_rt_extension(filename));
}

TEST(extension_valid_test, 숨김파일인_경우)
{
	char const *filename = (char const *)".rt";

	ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, rt_확장자가_아닌_경우)
{
	char const *filename = (char const *)"example.txt";

	ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, rt_확장자가_대문자인_경우)
{
	char const *filename = (char const *)"example.RT";

	ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, rt와_비슷한_확장자인_경우)
{
	char const *filename = (char const *)"example.rtt";

	ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, 확장자_뒤에_공백이_있는_경우)
{
	char const *filename = (char const *)"example.rt ";

	ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, 확장자가_중간에_있는_경우)
{
	char const *filename = (char const *)"example.rt.txt";

	ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, 확장자가_중복되어_있는_경우)
{
	char const *filename = (char const *)"example.rt.rt";

	ASSERT_NO_THROW(must_be_rt_extension(filename));
}

TEST(extension_valid_test, 경로가_있는_숨김_파일인_경우)
{
char const *filename = (char const *)"abc/.rt";

ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}

TEST(extension_valid_test, 숨김파일의_확장자가_rt인_경우)
{
char const *filename = (char const *)".rt.rt";

ASSERT_THROW(must_be_rt_extension(filename), std::runtime_error);
}
