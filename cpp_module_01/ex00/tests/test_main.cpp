#include "test_main.hpp"
#include "gtest/gtest.h"
#include "Zombie.hpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(ZombieTestSuite, firstTests) {
	std::string zombie_name = "Foo";

	// Test 1
	testing::internal::CaptureStdout();
	Zombie z (zombie_name);
	z.announce();
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = zombie_name + ": BraiiiiiiinnnzzzZ...\n";
	ASSERT_STREQ(want.c_str(), got.c_str());

	// Test 2
	testing::internal::CaptureStdout();
	Zombie* zp = newZombie(zombie_name);
	got = testing::internal::GetCapturedStdout();
	want = "";
	ASSERT_STREQ(want.c_str(), got.c_str());

	// Test 3
	testing::internal::CaptureStdout();
	delete zp;
	got = testing::internal::GetCapturedStdout();
	ASSERT_STREQ((zombie_name + " got destroyed\n").c_str(), got.c_str());

	// Test 4
	testing::internal::CaptureStdout();
	randomChump(zombie_name);
	got = testing::internal::GetCapturedStdout();
	want = zombie_name + ": BraiiiiiiinnnzzzZ...\n" + zombie_name + " got destroyed\n";
	ASSERT_STREQ(want.c_str(), got.c_str());
}
