#include "test_main.hpp"

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
