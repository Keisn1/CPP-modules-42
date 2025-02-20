#include "test_main.hpp"
#include "Contact.hpp"
#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(firstTest, firstTest) {
	std::string first_name = "kay";
	Contact contact {first_name};
	std::string got = contact.get_first_name();
	ASSERT_STREQ(first_name.c_str(), got.c_str());
	return;
}
