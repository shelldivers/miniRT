extern "C" {
#include "camera.h"
}
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

TEST(CameraTest, CameraTest_viewport)
{
    t_cam camera;
    camera.view_point = (t_point3){0, 0, 0};
    t_vw *viewport = get_viewport_malloc(&camera, 4, 4);

    EXPECT_EQ(viewport->origin.x, 0);
    EXPECT_EQ(viewport->origin.y, 0);
    EXPECT_EQ(viewport->origin.z, 0);
    EXPECT_EQ(viewport->horizontal.x, 4);
    EXPECT_EQ(viewport->horizontal.y, 0);
    EXPECT_EQ(viewport->horizontal.z, 0);
    EXPECT_EQ(viewport->vertical.x, 0);
    EXPECT_EQ(viewport->vertical.y, 4);
    EXPECT_EQ(viewport->vertical.z, 0);
    EXPECT_EQ(viewport->focal_length, 1);
    EXPECT_EQ(viewport->upper_left_corner.x, -2);
    EXPECT_EQ(viewport->upper_left_corner.y, 1);
    EXPECT_EQ(viewport->upper_left_corner.z, -1);
}