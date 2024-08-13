extern "C" {
#include "vec3.h"
}
#include "gtest/gtest.h"

TEST(vec3_random_test, vec3_random) {
    for (int i = 0; i < 1000000; ++i) {
		t_vec3 random = vec3_random();
		EXPECT_TRUE(random.x >= -1 && random.x <= 1);
		EXPECT_TRUE(random.y >= -1 && random.y <= 1);
		EXPECT_TRUE(random.z >= -1 && random.z <= 1);
	}
}

TEST(vec3_random_range_test, vec3_random_range) {
	int min = -10;
	int max = 10;
    for (int i = 0; i < 1000000; ++i) {
		t_vec3 random = vec3_random_range(min, max);
		EXPECT_TRUE(random.x >= min && random.x <= max);
		EXPECT_TRUE(random.y >= min && random.y <= max);
		EXPECT_TRUE(random.z >= min && random.z <= max);
	}
}
