#include "gtest/gtest.h"
#include "ray.h"

TEST(RayTest, RayTest_ray)
{
    t_ray ray;
    
    ray.origin = point3(1, 2, 3);
    ray.direction = vec3(4, 5, 6);

    EXPECT_EQ(ray.origin.x, 1);
    EXPECT_EQ(ray.origin.y, 2);
    EXPECT_EQ(ray.origin.z, 3);
    EXPECT_EQ(ray.direction.x, 4);
    EXPECT_EQ(ray.direction.y, 5);
    EXPECT_EQ(ray.direction.z, 6);
}

TEST(RayTest, RayTest_point_at)
{
    t_ray ray;
    
    ray.origin = point3(1, 2, 3);
    ray.direction = vec3(4, 5, 6);

    t_point3 point = point_at(&ray, 2);

    EXPECT_EQ(point.x, 9);
    EXPECT_EQ(point.y, 12);
    EXPECT_EQ(point.z, 15);
}

TEST(RayTest, RayTest_point3_to_vec3)
{
    t_point3 point = point3(1, 2, 3);
    t_vec3 vec = point3_to_vec3(point);

    EXPECT_EQ(vec.x, 1);
    EXPECT_EQ(vec.y, 2);
    EXPECT_EQ(vec.z, 3);
}

TEST(RayTest, RayTest_vec3_to_point3)
{
    t_vec3 vec = vec3(1, 2, 3);
    t_point3 point = vec3_to_point3(vec);

    EXPECT_EQ(point.x, 1);
    EXPECT_EQ(point.y, 2);
    EXPECT_EQ(point.z, 3);
}
