#include "gtest/gtest.h"
extern "C" {
#include "ray.h"
}

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

TEST(RayTest, RayTest_hit_sphere_false)
{
    t_point3 center = point3(0, 0, -1);
    t_ray ray;
    
    ray.origin = point3(1, 2, 3);
    ray.direction = vec3(4, 5, 6);

    bool hit = hit_sphere(center, 0.5, &ray);

    EXPECT_EQ(hit, false);
}

TEST(RayTest, RayTest_hit_sphere_true)
{
    t_point3 center = point3(1, 2, 3);
    t_ray ray;

    ray.origin = point3(1, 2, 3);
    ray.direction = vec3(4, 5, 6);    

    bool hit = hit_sphere(center, 0.5, &ray);

    EXPECT_EQ(hit, true);
}

TEST(RayTest, RayTest_ray_color_background)
{
    t_ray ray;
    
    ray.origin = point3(1, 2, 3);
    ray.direction = vec3(4, 5, 6);

    t_color color = ray_color(&ray);

    EXPECT_FLOAT_EQ(color.r, 0.60754931);
    EXPECT_FLOAT_EQ(color.g, 0.76452958);
    EXPECT_FLOAT_EQ(color.b, 1);
}

TEST(RayTest, RayTest_ray_color_shpere)
{
    t_ray ray;
    
    ray.origin = point3(0, 0, -1);
    ray.direction = vec3(4, 5, 6);

    t_color color = ray_color(&ray);

    EXPECT_FLOAT_EQ(color.r, 1);
    EXPECT_FLOAT_EQ(color.g, 0);
    EXPECT_FLOAT_EQ(color.b, 0);
}