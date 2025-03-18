#include "test_main.hpp"
#include "Harl.hpp"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(harlTests, firstTests) {
	Harl harl;
	testing::internal::CaptureStdout();
	harl.complain("DEBUG");
	std::string got = testing::internal::GetCapturedStdout();
	std::string want =  "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
	ASSERT_STREQ(want.c_str(), got.c_str());

	testing::internal::CaptureStdout();
	harl.complain("INFO");
	got = testing::internal::GetCapturedStdout();
	want = "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	ASSERT_STREQ(want.c_str(), got.c_str());

	testing::internal::CaptureStdout();
	harl.complain("WARNING");
	got = testing::internal::GetCapturedStdout();
	want = "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
	ASSERT_STREQ(want.c_str(), got.c_str());

	testing::internal::CaptureStdout();
	harl.complain("ERROR");
	got = testing::internal::GetCapturedStdout();
	want = "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
	ASSERT_STREQ(want.c_str(), got.c_str());

	testing::internal::CaptureStdout();
	harl.complain("something else");
	got = testing::internal::GetCapturedStdout();
	want = "[ Probably complaining about insignificant problems ]\n";
	ASSERT_STREQ(want.c_str(), got.c_str());
}
