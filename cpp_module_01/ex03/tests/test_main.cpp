#include "test_main.hpp"
#include "gtest/gtest.h"
#include "Weapon.hpp"
#include "HumanA.hpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(WeaponTestSuite, firstTests) {
	Weapon club = Weapon("crude spiked club");
	HumanA bob ("Bob", club);
	testing::internal::CaptureStdout();
	bob.attack();
	std::string got  = testing::internal::GetCapturedStdout();
	ASSERT_STREQ("Bob attacks with their crude spiked club\n", got.c_str());

	club.setType("some other type of club");

	testing::internal::CaptureStdout();
	bob.attack();
	got = testing::internal::GetCapturedStdout();
	ASSERT_STREQ("Bob attacks with their some other type of club\n", got.c_str());
}
