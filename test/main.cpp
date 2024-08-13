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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
