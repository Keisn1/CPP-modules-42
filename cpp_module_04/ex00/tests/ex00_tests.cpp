#include "gtest/gtest.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

TEST(TestAnimal, AnimalTests) {
	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Animal a1;
		a1.printType();
	}
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = R"(Animal was constructed
type: Animal
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Animal a1;
		Animal a2 (a1);
		a2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Animal was copied
type: Animal
Animal was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Animal a1;
		Animal a2 = a1;
		a2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Animal was copied
type: Animal
Animal was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
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
		d1.printType();
	}
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = R"(Animal was constructed
Dog was constructed
type: Dog
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Animal* ap = new Dog;
		delete(ap);
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Dog d1;
		Dog d2 (d1);
		d2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Animal was copied
Dog was copied
type: Dog
Dog was destructed
Animal was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Dog d1;
		Dog d2 = d1;
		d2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Animal was copied
Dog was copied
type: Dog
Dog was destructed
Animal was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Dog d1;
		Dog d2;
		d2.printType();
		d2 = d1;
		d2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Dog was constructed
Animal was constructed
Dog was constructed
type: Dog
Dog was assigned to another Dog
type: Dog
Dog was destructed
Animal was destructed
Dog was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
}

// Cat tests
TEST(TestCat, CatTests) {
	testing::internal::CaptureStdout();
	{
		Cat d1;
		d1.printType();
	}
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = R"(Animal was constructed
Cat was constructed
type: Cat
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Animal* ap = new Cat;
		delete(ap);
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Cat was constructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Cat d1;
		Cat d2 (d1);
		d2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Cat was constructed
Animal was copied
Cat was copied
type: Cat
Cat was destructed
Animal was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Cat d1;
		Cat d2 = d1;
		d2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Cat was constructed
Animal was copied
Cat was copied
type: Cat
Cat was destructed
Animal was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);

	// ##########################################################################################
	testing::internal::CaptureStdout();
	{
		Cat d1;
		Cat d2;
		d2.printType();
		d2 = d1;
		d2.printType();
	}
	got = testing::internal::GetCapturedStdout();
	want = R"(Animal was constructed
Cat was constructed
Animal was constructed
Cat was constructed
type: Cat
Cat was assigned to another Cat
type: Cat
Cat was destructed
Animal was destructed
Cat was destructed
Animal was destructed
)";
	ASSERT_EQ(want, got);
}

TEST(MakeSounds, sounds) {
	std::string got;
	{
		Animal a1;
		testing::internal::CaptureStdout();
		a1.makeSound();
		got = testing::internal::GetCapturedStdout();
	}
	std::string want =  "Animal makes an animal sound\n";
	ASSERT_EQ(want, got);

	{
		Dog d1;
		testing::internal::CaptureStdout();
		d1.makeSound();
		got = testing::internal::GetCapturedStdout();
	}
	want = "Dog makes a Dog sound: Wuff Wuff\n";
	ASSERT_EQ(want, got);

// 	testing::internal::CaptureStdout();
// 	{
// 		Dog d1;
// 		d1.makeSound();
// 	}
// 	got = testing::internal::GetCapturedStdout();
// 	want = R"(Dog was constructed
//
// Dog was destructed
// )";
// 	ASSERT_EQ(want, got);

}
