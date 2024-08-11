#include "gtest/gtest.h"

extern "C" void error_exit(char *message) {
	std::string msg(message);
	throw std::runtime_error("Error code: " + msg);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
