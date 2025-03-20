#include "Fixed.hpp"
#include "gtest/gtest.h"


struct IntToIntParams {
	int in_val;
	int want;
};

class TestIntToIntSuite : public::testing::TestWithParam<IntToIntParams>{};


TEST_P(TestIntToIntSuite, tests) {
	IntToIntParams params = GetParam();
	testing::internal::CaptureStdout();
	Fixed a (params.in_val);
	int got = a.toInt();
	testing::internal::GetCapturedStdout();
	ASSERT_EQ(params.want, got);
}

INSTANTIATE_TEST_SUITE_P(
	nbrConv,
	TestIntToIntSuite, testing::Values(
		IntToIntParams{0, 0}
		));
