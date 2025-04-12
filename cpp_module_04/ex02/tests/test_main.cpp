#include "gtest/gtest.h"
#include "Cat.h"
#include "Dog.h"

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(BrainConstDest, constDest) {
	std::string got;
	{
		testing::internal::CaptureStdout();
		const Cat *c = new Cat();
		delete c;
		got = testing::internal::GetCapturedStdout();
	}
	std::string want = R"(Animal was constructed
Brain was constructed
Cat was constructed
Brain was destructed
Cat was destructed
Animal was destructed
)";

	{
		testing::internal::CaptureStdout();
		const Dog *d = new Dog();
		delete d;
		got = testing::internal::GetCapturedStdout();
	}
	want = R"(Animal was constructed
Brain was constructed
Dog was constructed
Brain was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	{
		testing::internal::CaptureStdout();
		const AAnimal *c = new Cat();
		delete c;
		got = testing::internal::GetCapturedStdout();
	}
	want = R"(Animal was constructed
Brain was constructed
Cat was constructed
Brain was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	{
		testing::internal::CaptureStdout();
		const AAnimal *d = new Dog();
		delete d;
		got = testing::internal::GetCapturedStdout();
	}
	want = R"(Animal was constructed
Brain was constructed
Dog was constructed
Brain was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
}

TEST(CopyingAnimals, copy) {
	std::string got;
	{
		testing::internal::CaptureStdout();
		const AAnimal* cat1 = new Cat();
		const AAnimal* cat2 = cat1;
		delete cat1;
		(void)cat2;
		got = testing::internal::GetCapturedStdout();
	}
	std::string want = R"(Animal was constructed
Brain was constructed
Cat was constructed
Brain was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	{
		testing::internal::CaptureStdout();
		const Cat cat1 = Cat();
		const Cat cat2 (cat1);
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Brain was constructed
Cat was constructed
Animal was copied
ideas were copied
Brain was copy-constructed
Cat was copy-constructed
Brain was destructed
Cat was destructed
Animal was destructed
Brain was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);


	{
		testing::internal::CaptureStdout();
		const Cat* cat1 = new Cat();
		const Cat* cat2 = new Cat(*cat1);
		delete cat1;
		delete cat2;
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Brain was constructed
Cat was constructed
Animal was copied
ideas were copied
Brain was copy-constructed
Cat was copy-constructed
Brain was destructed
Cat was destructed
Animal was destructed
Brain was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	{
		testing::internal::CaptureStdout();
		const Dog dog1 = Dog();
		const Dog dog2 (dog1);
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Brain was constructed
Dog was constructed
Animal was copied
ideas were copied
Brain was copy-constructed
Dog was copy-constructed
Brain was destructed
Dog was destructed
Animal was destructed
Brain was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	{
		testing::internal::CaptureStdout();
		const Dog* dog1 = new Dog();
		const Dog* dog2 = new Dog(*dog1);
		delete dog1;
		delete dog2;
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Brain was constructed
Dog was constructed
Animal was copied
ideas were copied
Brain was copy-constructed
Dog was copy-constructed
Brain was destructed
Dog was destructed
Animal was destructed
Brain was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	{
		testing::internal::CaptureStdout();
		Dog basic;
		{
			Dog tmp;
			tmp = basic;
		}
	}
	got = testing::internal::GetCapturedStdout();
        want = R"(Animal was constructed
Brain was constructed
Dog was constructed
Animal was constructed
Brain was constructed
Dog was constructed
ideas were copied
Brain was copy-assigned
Dog was assigned to another Dog
Brain was destructed
Dog was destructed
Animal was destructed
Brain was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
}
