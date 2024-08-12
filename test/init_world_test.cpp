extern "C" {
#include "minirt.h"
}
#include "gtest/gtest.h"
#include <fstream>
#include <fcntl.h>

TEST(init_world_test, 성공)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(init_world(&rt, filename.c_str()));

	remove(filename.c_str());
}

TEST(init_world_test, 파일이_없는_경우)
{
    std::string filename = "example.rt";

    t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_THROW(init_world(&rt, filename.c_str()), std::runtime_error);

	remove(filename.c_str());
}