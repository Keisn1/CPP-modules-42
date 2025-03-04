#include "test_main.hpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(PhoneBookTest, FirstTest) {
	PhoneBook pb ;
	testing::internal::CaptureStdout();
	pb.display();
	std::string got = testing::internal::GetCapturedStdout();

	std::string want = R"(|     index|first name| last name|  nickname|
|----------|----------|----------|----------|
)";
	ASSERT_STREQ(want.c_str(), got.c_str());

	// 1st Contact
	pb.add(Contact("kay", "freyer", "keisn", "11111", "my secret"));
	testing::internal::CaptureStdout();
	pb.display();
	got = testing::internal::GetCapturedStdout();

	want = R"(|     index|first name| last name|  nickname|
|----------|----------|----------|----------|
|         0|       kay|    freyer|     keisn|
)";
	ASSERT_STREQ(want.c_str(), got.c_str());
	
	// 2nd Contact
	pb.add(Contact("karl", "freyer", "keisn", "11111", "my secret"));
	testing::internal::CaptureStdout();
	pb.display();
	got = testing::internal::GetCapturedStdout();
	want = R"(|     index|first name| last name|  nickname|
|----------|----------|----------|----------|
|         0|       kay|    freyer|     keisn|
|         1|      karl|    freyer|     keisn|
)";
	ASSERT_STREQ(want.c_str(), got.c_str());

	// 3rd Contact
	pb.add(Contact("christopher", "freyer", "keisn", "11111", "my secret"));
	testing::internal::CaptureStdout();
	pb.display();
	got = testing::internal::GetCapturedStdout();

	want = R"(|     index|first name| last name|  nickname|
|----------|----------|----------|----------|
|         0|       kay|    freyer|     keisn|
|         1|      karl|    freyer|     keisn|
|         2|christoph.|    freyer|     keisn|
)";
	ASSERT_STREQ(want.c_str(), got.c_str());


	// adding contact 3, 4, 5, 6, 7
	pb.add(Contact("kay", "freyer", "||||||||||||||||", "11111", "my secret"));
	pb.add(Contact("kay", "))))))))))))))))", "keisn", "11111", "my secret"));
	pb.add(Contact("*&^%$%#_)(*#$)", "freyer", "keisn", "11111", "my secret"));
	pb.add(Contact("..............", "freyer", "keisn", "11111", "my secret"));
	pb.add(Contact("kay", " 😋😛😜🤪😝🤑", "keisn", "11111", "my secret"));

	testing::internal::CaptureStdout();
	pb.display();
	got = testing::internal::GetCapturedStdout();

	want = R"(|     index|first name| last name|  nickname|
|----------|----------|----------|----------|
|         0|       kay|    freyer|     keisn|
|         1|      karl|    freyer|     keisn|
|         2|christoph.|    freyer|     keisn|
|         3|       kay|    freyer||||||||||.|
|         4|       kay|))))))))).|     keisn|
|         5|*&^%$%#_).|    freyer|     keisn|
|         6|..........|    freyer|     keisn|
|         7|       kay| 😋😛.|     keisn|
)";
	ASSERT_STREQ(want.c_str(), got.c_str());

	// replace last one
	pb.add(Contact("kay", "kay", "||||||||||||||||", "11111", "my secret"));
	want = R"(|     index|first name| last name|  nickname|
|----------|----------|----------|----------|
|         0|       kay|    freyer|     keisn|
|         1|      karl|    freyer|     keisn|
|         2|christoph.|    freyer|     keisn|
|         3|       kay|    freyer||||||||||.|
|         4|       kay|))))))))).|     keisn|
|         5|*&^%$%#_).|    freyer|     keisn|
|         6|..........|    freyer|     keisn|
|         7|       kay|       kay|     keisn|
)";
}
