extern "C" {
#include "get_next_line.h"
}
#include "gtest/gtest.h"

extern "C" void error_exit(char *message) {
	std::string msg(message);
	throw std::runtime_error("Error code: " + msg);
}

void clear_get_next_line_buffer(int fd) {
	char *line;
	while ((line = get_next_line(fd))) {
		free(line);
	}
}

extern "C" void	*mlx_xpm_file_to_image(void *xvar,char *file,int *width,int *height)
{
	(void)xvar;
	(void)file;
	*width = 42;
	*height = 42;
	return ((void *)42);
}

extern "C" void *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian) {
	(void)img_ptr;
	*bits_per_pixel = 42;
	*size_line = 42;
	*endian = 42;
	return ((void *)42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
