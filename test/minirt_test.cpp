#include "ft_printf.h"
#include "minirt.h"
#include "gtest/gtest.h"

TEST(MinirtTest, Test1) {
	rt_main();
	ft_printf("Hello, Libft!\n");
	EXPECT_EQ(1, 1);
}
