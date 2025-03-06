#include "test_main.hpp"
#include "gtest/gtest.h"
#include "Zombie.hpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(ZombieTestSuite, firstTests) {
	int N = 6;
	std::string zombie_name = "Foo";
	Zombie* zombies = zombieHorde(N, zombie_name);

	for (int i = 0; i < N; i++) {
		testing::internal::CaptureStdout();
		zombies[i].announce();
		std::string got = testing::internal::GetCapturedStdout();
		std::string want = zombie_name + ": BraiiiiiiinnnzzzZ...\n";
		ASSERT_STREQ(want.c_str(), got.c_str());
	}

	testing::internal::CaptureStdout();
	delete[] zombies;
	std::string got = testing::internal::GetCapturedStdout();
	std::string str = zombie_name + " got destroyed\n";
	std::string want = "";
	for (int i = 0; i < N ; i++ )
		want += str;
	ASSERT_STREQ(want.c_str(), got.c_str());

}
