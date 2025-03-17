#include "test_main.hpp"
#include "gtest/gtest.h"
#include <sstream>

struct ContactTestParams {
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string mobile;
	std::string secret;
	std::string want_out;
};

class ContactTestSuite : public::testing::TestWithParam<ContactTestParams> {};

TEST(ContactTestSuite, emptyContact) {
	Contact contact {};
	ASSERT_STREQ("", contact.get_first_name().c_str());
	ASSERT_STREQ("", contact.get_last_name().c_str());
	ASSERT_STREQ("", contact.get_nick_name().c_str());
	ASSERT_STREQ("", contact.get_mobile().c_str());
	ASSERT_STREQ("", contact.get_secret().c_str());
}

TEST_P(ContactTestSuite, firstTests) {
	ContactTestParams p = GetParam();

	Contact contact {p.first_name, p.last_name, p.nick_name, p.mobile, p.secret};
	ASSERT_STREQ(p.first_name.c_str(), contact.get_first_name().c_str());
	ASSERT_STREQ(p.last_name.c_str(), contact.get_last_name().c_str());
	ASSERT_STREQ(p.nick_name.c_str(), contact.get_nick_name().c_str());
	ASSERT_STREQ(p.mobile.c_str(), contact.get_mobile().c_str());
	ASSERT_STREQ(p.secret.c_str(), contact.get_secret().c_str());

	testing::internal::CaptureStdout();
	contact.display();
	std::string got = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(p.want_out.c_str(), got.c_str());
	return;
};

INSTANTIATE_TEST_SUITE_P(ContactTests, ContactTestSuite,
                         testing::Values(ContactTestParams{
							 "Santa", "Klaus", "NickiMinaj", "+960 3537", "Mein Reigntier ist ein Esel",
							 R"(First Name: Santa
Last Name: Klaus
Nickname: NickiMinaj
Mobile: +960 3537
Darkest Secret: Mein Reigntier ist ein Esel
)"}
						 ));

TEST(ContactStreamTest, firstTests) {
	std::string first_name = "Christian";
	std::string last_name = "Jedermann";
	std::string nick_name = "bobo";
	std::string mobile = "012937492";
	std::string secret = "my darkest secret";

	// std::istream is an abstract base class and cannot be instantiated directly because it does not have a constructor you can call
	// Instead, it is meant to be used polymorphically, typically through its derived classes
	// like std::ifstream (for file input), std::istringstream (for string input), or by using standard input streams like std::cin.
	std::istringstream in(first_name + "\n" + last_name +"\n" +  nick_name +"\n" + mobile +   "\n" + secret + "\n");

	testing::internal::CaptureStdout();
	Contact ct = Contact(in);
	std::string got = testing::internal::GetCapturedStdout();

	std::stringstream wantStream;
	wantStream << DARKSALMON << "First name?" << RESET << "\n"
			   << DARKSALMON << "Last name?" << RESET << "\n"
			   << DARKSALMON << "Nickname?" << RESET << "\n"
			   << DARKSALMON << "Phone number?" << RESET << "\n"
			   << DARKSALMON << "Darkest Secret?" << RESET << "\n";
	std::string want = wantStream.str();

	ASSERT_STREQ(first_name.c_str(), ct.get_first_name().c_str());
	ASSERT_STREQ(last_name.c_str(), ct.get_last_name().c_str());
	ASSERT_STREQ(nick_name.c_str(), ct.get_nick_name().c_str());
	ASSERT_STREQ(mobile.c_str(), ct.get_mobile().c_str());
	ASSERT_STREQ(secret.c_str(), ct.get_secret().c_str());
	ASSERT_STREQ(want.c_str(), got.c_str());
}
