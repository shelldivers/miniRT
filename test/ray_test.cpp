extern "C" {
#include "ray.h"
}
#include "gtest/gtest.h"

TEST(ray_test, point_at) {
	t_ray ray = {
		.origin = {0, 0, 0},
		.direction = {1, 1, 1}
	};
	t_point3 point = point_at(&ray, 1);
	ASSERT_FLOAT_EQ(point.x, 1);
	ASSERT_FLOAT_EQ(point.y, 1);
	ASSERT_FLOAT_EQ(point.z, 1);
}
