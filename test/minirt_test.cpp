#include "ft_printf.h"
#include "gtest/gtest.h"

TEST(MinirtTest, Test1) {
	ft_printf("Hello, world!\n");
	EXPECT_EQ(1, 1);
}
