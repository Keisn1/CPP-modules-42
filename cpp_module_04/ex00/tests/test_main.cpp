#include "gtest/gtest.h"
#include "Animal.h"
#include "Dog.h"

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(TestAnimal, AnimalTests) {
	testing::internal::CaptureStdout();
	{
		Animal a1;
	}
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = R"(Animal was constructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	testing::internal::CaptureStdout();
	{
		Animal a1;
		Animal a2 (a1);
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Animal was copied: type = Animal
Animal was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	testing::internal::CaptureStdout();
	{
		Animal a1;
		Animal a2 = a1;
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Animal was copied
Animal was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	testing::internal::CaptureStdout();
	{
		Animal a1;
		Animal a2;
		a2 = a1;
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Animal was constructed
Animal was assigned to another Animal
Animal was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
}

// Dog tests
TEST(TestDog, DogTests) {
	testing::internal::CaptureStdout();
	{
		Dog d1;
	}
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = R"(Animal was constructed
Dog was constructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	testing::internal::CaptureStdout();
	{
		Dog d1;
		Dog d2 (d1);
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Animal was copied
Dog was copied
Dog was destructed
Animal was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	testing::internal::CaptureStdout();
	{
		Dog d1;
		Dog d2 = d1;
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Animal was copied
Dog was copied
Dog was destructed
Animal was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	testing::internal::CaptureStdout();
	{
		Dog d1;
		Dog d2;
		d2 = d1;
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Animal was constructed
Dog was constructed
Dog was assigned to another Dog
Dog was destructed
Animal was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
}
