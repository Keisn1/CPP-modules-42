#include "test_main.hpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "*ContactStreamTest*";
	return RUN_ALL_TESTS();
}

