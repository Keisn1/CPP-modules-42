#include "test_main.hpp"
#include "replace_string.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

struct replaceStringParams {
	std::string text;
	std::string s1;
	std::string s2;
	std::string want;
};

class replaceStringTest : public::testing::TestWithParam<replaceStringParams> {};

TEST_P(replaceStringTest, firstTests) {
	replaceStringParams params = GetParam();

	replace_string(params.text, params.s1, params.s2);
	ASSERT_STREQ(params.want.c_str(), params.text.c_str());
}

INSTANTIATE_TEST_SUITE_P(replaceString, replaceStringTest,
						 testing::Values(
							 replaceStringParams{"kay", "kay", "jim", "jim"},
							 replaceStringParams{"   kay   ", "kay", "jim", "   jim   "},
							 replaceStringParams{"   kay   ", " ", "", "kay"},
							 replaceStringParams{"kay kay", "kay", "jim", "jim jim"},
							 replaceStringParams{"kay kay", "kay", "jimmy", "jimmy jimmy"},
							 replaceStringParams{"kay kay", "", "jimmy", "kay kay"},
							 replaceStringParams{"kk", "k", "j", "jj"},
							 replaceStringParams{"\n\n", "\n", "-", "--"},
							 replaceStringParams{"kay kay", "kay", "", " "},
							 replaceStringParams{"kay kay", "kay", "j j", "j j j j"}
							 )
	);
