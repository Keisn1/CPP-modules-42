#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "test_main.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

struct PhoneBookTestParams {
	std::vector<ContactParams> contacts;
};

class PhoneBookTestSuite
	: public ::testing::TestWithParam<PhoneBookTestParams> {
	public:
		PhoneBook pb;
};

void contact_to_stream(struct ContactParams ct, std::stringstream& wantStream) {
		if (ct.first_name.length() < 10)
			wantStream << SADDLEBROWN << "|" << FORESTGREEN << std::string(10 - ct.first_name.length(), ' ') <<  ct.first_name;
		else
			wantStream << SADDLEBROWN << "|"  << FORESTGREEN << ct.first_name.substr(0, 9) + ".";
		if (ct.last_name.length() < 10)
			wantStream << SADDLEBROWN << "|" << FORESTGREEN << std::string(10 - ct.last_name.length(), ' ') <<  ct.last_name;
		else
			wantStream << SADDLEBROWN << "|"  << FORESTGREEN << ct.last_name.substr(0, 9) + ".";

		if (ct.nick_name.length() < 10)
			wantStream << SADDLEBROWN << "|" << FORESTGREEN << std::string(10 - ct.nick_name.length(), ' ') <<  ct.nick_name;
		else
			wantStream << SADDLEBROWN << "|"  << FORESTGREEN << ct.nick_name.substr(0, 9) + ".";

		wantStream << SADDLEBROWN << "|" << RESET << "\n";
}

TEST_P(PhoneBookTestSuite, ExampleTest) {
	PhoneBookTestParams params = GetParam();
	std::vector<ContactParams> contacts = params.contacts;
	testing::internal::CaptureStdout();

	for (size_t i = 0; i < contacts.size(); i++) {
		Contact ct (contacts[i].first_name, contacts[i].last_name, contacts[i].nick_name, contacts[i].mobile, contacts[i].secret);
		pb.add(ct);
	}
	testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	pb.display();
	std::string got = testing::internal::GetCapturedStdout();

	std::stringstream wantStream;
	wantStream << SADDLEBROWN << "|     index|first name| last name|  nickname|" << "\n"
			   << "|----------|----------|----------|----------|" << RESET << "\n";

	size_t max_size = contacts.size() >= 8 ? 8 : contacts.size();
	if (max_size == 0)
		return;
	for (size_t i = 0; i < max_size-1; i++) {
		ContactParams ct = contacts[i];
		wantStream << SADDLEBROWN << "|" << FORESTGREEN <<   "         " << i;
		contact_to_stream(ct, wantStream);
	}

	ContactParams ct = contacts[contacts.size()-1];
	wantStream << SADDLEBROWN << "|" << FORESTGREEN <<   "         " << max_size-1;
	contact_to_stream(ct, wantStream);

	std::string want = wantStream.str();
	ASSERT_STREQ(want.c_str(), got.c_str());
}

INSTANTIATE_TEST_SUITE_P(
	PhoneBook, PhoneBookTestSuite,
	testing::Values(
		PhoneBookTestParams{std::vector<ContactParams>{}},
		PhoneBookTestParams{std::vector<ContactParams>{
				ContactParams{"kay", "freyer", "keisn", "111", "my secret"}}},
		PhoneBookTestParams{std::vector<ContactParams>{
				ContactParams{"kay", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"}}},
		PhoneBookTestParams{std::vector<ContactParams>{
				ContactParams{"kay", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"christophe", "freyer", "keisn", "111",
						"my secret"}}},
		PhoneBookTestParams{std::vector<ContactParams>{
				ContactParams{"kay", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"christophe", "freyer", "keisn", "111",
						"my secret"}}},
		PhoneBookTestParams{std::vector<ContactParams>{
				ContactParams{"kay", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"christophe", "freyer", "keisn", "111",
						"my secret"}}},

        PhoneBookTestParams{std::vector<ContactParams>{
				ContactParams{"kay", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"},
					ContactParams{"christophe", "freyer", "keisn", "111", "my secret"},
					ContactParams{"karl", "freyer", "keisn", "111", "my secret"}}}
	));

TEST(PhoneBookDisplayCtct, someTests) {
	PhoneBook pb;
	testing::internal::CaptureStdout();
	std::istringstream in ("-1");
	int got_index = pb.get_index(in);
	int want_index = -1;
	std::string got_out = testing::internal::GetCapturedStdout();
	std::string want_out = "";
	ASSERT_EQ(want_index, got_index);
	ASSERT_STREQ(want_out.c_str(), got_out.c_str());

	// adding a contact
	pb.add(Contact("kay", "freyer", "Keisn", "111", "secret"));

	testing::internal::CaptureStdout();
	in.clear();
	in.str("0");
	pb.get_index(in);
	got_out = testing::internal::GetCapturedStdout();
	std::stringstream wantStream;
	wantStream << DARKSALMON << "Which contact do you want to be displayed. Give me an index between 0 and 0 (or -1 to continue): " << RESET;
	ASSERT_STREQ(wantStream.str().c_str(), got_out.c_str());

	testing::internal::CaptureStdout();
	in.clear();
	in.str("1\n0");
	pb.get_index(in);
	got_out = testing::internal::GetCapturedStdout();
	wantStream.str("");
	wantStream << DARKSALMON << "Which contact do you want to be displayed. Give me an index between 0 and 0 (or -1 to continue): " << RESET
			   << RED << "Invalid input. Please enter an integer between 0 and 0 (or -1 to continue): " << RESET ;
	ASSERT_STREQ(wantStream.str().c_str(), got_out.c_str());

	testing::internal::CaptureStdout();
	in.clear();
	in.str("11\n0");
	pb.get_index(in);
	got_out = testing::internal::GetCapturedStdout();
	wantStream.str("");
	wantStream << DARKSALMON << "Which contact do you want to be displayed. Give me an index between 0 and 0 (or -1 to continue): " << RESET
			   << RED << "Invalid input. Please enter an integer between 0 and 0 (or -1 to continue): " << RESET ;
	ASSERT_STREQ(wantStream.str().c_str(), got_out.c_str());
}

struct getCmdParams {
	std::string input;
	std::string want_str ;
	std::vector<std::string> wantOutElems;
};

class getCmdTest : public::testing::TestWithParam<getCmdParams>{};

TEST_P(getCmdTest, someTests) {
	struct getCmdParams params = GetParam();
	std::istringstream in;
	std::stringstream wantStream;
	for (auto s : params.wantOutElems)
		wantStream << s;

	testing::internal::CaptureStdout();
	in.str(params.input);
	std::string got_str = get_cmd(in);
	std::string got_out = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(params.want_str.c_str(), got_str.c_str());
	ASSERT_STREQ(wantStream.str().c_str(), got_out.c_str());
}

INSTANTIATE_TEST_SUITE_P(getCmdTests, getCmdTest,
						 testing::Values(
							 getCmdParams{"ADD", "add", {DARKSALMON, "What do you want to do? ADD, SEARCH or EXIT?", RESET, "\n"}},
							 getCmdParams{"add", "add", {DARKSALMON, "What do you want to do? ADD, SEARCH or EXIT?", RESET, "\n"}},
							 getCmdParams{"EXIT", "exit", {DARKSALMON, "What do you want to do? ADD, SEARCH or EXIT?", RESET, "\n"}},
							 getCmdParams{"exit", "exit", {DARKSALMON, "What do you want to do? ADD, SEARCH or EXIT?", RESET, "\n"}},
							 getCmdParams{"SEARCH", "search", {DARKSALMON, "What do you want to do? ADD, SEARCH or EXIT?", RESET, "\n"}},
							 getCmdParams{"search", "search", {DARKSALMON, "What do you want to do? ADD, SEARCH or EXIT?", RESET, "\n"}},
							 getCmdParams{"asdf\nsearch", "search", {DARKSALMON , "What do you want to do? ADD, SEARCH or EXIT?" , RESET , "\n" , RED , "You can choose between: ADD, SEARCH and EXIT" , RESET , "\n"}}
						 ));


