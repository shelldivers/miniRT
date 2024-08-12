extern "C" {
#include "minirt.h"
#include "reflection.h"
}
#include "gtest/gtest.h"
#include <fstream>
#include <fcntl.h>

TEST(parse_light_test, basic_case)
{
	std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << "L 0,0,0 0.5 255,255,255\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);
	rt.lights = init_light_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

	close(fd);
	remove(filename.c_str());

}