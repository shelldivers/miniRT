extern "C" {
#include "minirt.h"
#include "get_next_line.h"
#include "parse.h"
}
#include "gtest/gtest.h"
#include <fstream>
#include <fcntl.h>

void clear_get_next_line_buffer(int fd);    // from test/main.cpp

TEST(parse_light_test, 실패)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "L0,0,0 0.5 255,255,255\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file << "abc 0,0,0 0.5 255,255,255";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);

	ASSERT_THROW(parse_rtfile(fd, &rt), std::runtime_error);
    
    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 성공)
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
    
    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 식별자_뒤에_공백이_없는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "L0,0,0 0.5 255,255,255\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);
    rt.lights = init_light_list(10);

	ASSERT_THROW(parse_rtfile(fd, &rt), std::runtime_error);

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 허용되지_않는_식별자)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
		file << "abc 0,0,0 0,0,1 255,255,255";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_THROW(parse_rtfile(fd, &rt), std::runtime_error);

	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 마지막_개행이_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 추가_개행이_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
		file << "\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
    t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 추가_개행이_많은_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
		file << "\n\n\n\n\n\n\n\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
    t_rt rt;
	rt.world = init_hittable_list(10);
	
    ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 중간에_개행이_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << "\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 중간에_개행이_많은_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
		file << "\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << "\n";
		file << "\n";
		file << "\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
		file << "\n\n\n\n\n\n\n\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 공백_줄이_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
		file << "\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << " \n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
		file << "\n\n\n\n\n\n\n\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 들여쓰기_줄이_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
		file << "\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << "\t\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
		file << "\n\n\n\n\n\n\n\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_NO_THROW(parse_rtfile(fd, &rt));

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 식별자_앞에_공백이_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
		file << "\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << "\n";
        file << " cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
		file << "\n\n\n\n\n\n\n\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_THROW(parse_rtfile(fd, &rt), std::runtime_error);

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 식별자_앞에_들여쓰기가_있는_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
		file << "\n";
        file << "C 0,0,0 0,0,1 70\n";
		file << "\n";
        file << "\tcy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
		file << "\n\n\n\n\n\n\n\n";
        file << "pl 0,0,0 0,0,1 255,255,255\n";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_THROW(parse_rtfile(fd, &rt), std::runtime_error);

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}

TEST(parse_rtfile_test, 혀용된_식별자_뒤에_문자가_추가된_경우)
{
    std::string filename = "example.rt";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file << "A 0.1 255,255,255\n";
        file << "C 0,0,0 0,0,1 70\n";
        file << "cy 0,0,0 0,0,1 1 1 255,255,255\n";
        file << "sp 0,0,0 1 255,255,255\n";
        file << "Ab 0,0,0 0,0,1 255,255,255";
        file.close();
    } else {
        std::cout << "Unable to open test file" << std::endl;
    }

	int fd = open(filename.c_str(), O_RDONLY);
	t_rt rt;
	rt.world = init_hittable_list(10);

	ASSERT_THROW(parse_rtfile(fd, &rt), std::runtime_error);

    clear_get_next_line_buffer(fd);
	close(fd);
	remove(filename.c_str());
}
