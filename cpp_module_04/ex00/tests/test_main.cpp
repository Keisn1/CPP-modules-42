#include "gtest/gtest.h"
#include "Animal.h"

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestAnimal, Animal) {
	testing::internal::CaptureStdout();
	{
		Animal a1;
	}
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = R"(Animal of type "" was constructed
Animal of type "" was destructed
)";
	ASSERT_EQ(want, got);
}
