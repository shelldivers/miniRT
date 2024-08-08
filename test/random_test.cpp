extern "C" {
#include "vec3.h"
}
#include "gtest/gtest.h"

TEST(random_test, vec3_random) {
	for (int i = 0; i < 100000; ++i) {
		t_vec3 random = vec3_random();
		EXPECT_TRUE(random.x >= 0 && random.x <= 1);
		EXPECT_TRUE(random.y >= 0 && random.y <= 1);
		EXPECT_TRUE(random.z >= 0 && random.z <= 1);
	}
}

/*
*@todo: vec3_random_range test is failed
*/
TEST(random_test, vec3_random_range) {
	for (int i = 0; i < 100000; ++i) {
		float min = rand() * 10, max = rand() * 10;
		t_vec3 random = vec3_random_range(min, max);
		EXPECT_TRUE(random.x >= min && random.x <= max);
		EXPECT_TRUE(random.y >= min && random.y <= max);
		EXPECT_TRUE(random.z >= min && random.z <= max);
	}
}
