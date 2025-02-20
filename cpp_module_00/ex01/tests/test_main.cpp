#include "test_main.hpp"
#include "Contact.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(firstTest, firstTest) {
	std::string first_name = "Kay";
	Contact contact {first_name};
	ASSERT_STREQ(first_name.c_str(), contact.get_first_name().c_str());

	testing::internal::CaptureStdout();
	contact.display();
	std::string got = testing::internal::GetCapturedStdout();
	std::string want = "First Name: Kay\n";

	ASSERT_STREQ(want.c_str(), got.c_str());
	return;
}
