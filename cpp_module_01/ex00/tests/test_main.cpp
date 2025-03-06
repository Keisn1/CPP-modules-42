#include "test_main.hpp"
#include "gtest/gtest.h"
#include "Zombie.hpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(ZombieTestSuite, firstTests) {
	testing::internal::CaptureStdout();
	std::string zombie_name = "Foo";
	Zombie* z = newZombie(zombie_name);
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = zombie_name + ": BraiiiiiiinnnzzzZ...\n";
	ASSERT_STREQ(want.c_str(), got.c_str());

	testing::internal::CaptureStdout();
	delete z;
	got = testing::internal::GetCapturedStdout();
	ASSERT_STREQ((zombie_name + " got destroyed\n").c_str(), got.c_str());

	testing::internal::CaptureStdout();
	randomChump(zombie_name);
	got = testing::internal::GetCapturedStdout();
	want = zombie_name + ": BraiiiiiiinnnzzzZ...\n" + zombie_name + " got destroyed\n";
	ASSERT_STREQ(want.c_str(), got.c_str());
}
