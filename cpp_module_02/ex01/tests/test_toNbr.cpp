#include "Fixed.hpp"
#include "gtest/gtest.h"

struct IntToIntParams {
	int in_val;
	int want;
};

class TestIntToIntSuite : public::testing::TestWithParam<IntToIntParams>{};

TEST_P(TestIntToIntSuite, tests) {
	IntToIntParams params = GetParam();
	Fixed a (params.in_val);
	int got = a.toInt();
	ASSERT_EQ(params.want, got);
}

INSTANTIATE_TEST_SUITE_P(
	nbrConv,
	TestIntToIntSuite, testing::Values(
		IntToIntParams{0, 0},
		IntToIntParams{-1, -1},
		IntToIntParams{1, 1},
		IntToIntParams{8388608, -8388608}
		));


struct IntToFloatParams {
	int in_val;
	float want;
};

class TestIntToFloatSuite : public::testing::TestWithParam<IntToFloatParams>{};

TEST_P(TestIntToFloatSuite, tests) {
	IntToFloatParams params = GetParam();
	Fixed a (params.in_val);
	int got = a.toFloat();
	ASSERT_EQ(params.want, got);
}

INSTANTIATE_TEST_SUITE_P(
	nbrConv,
	TestIntToFloatSuite, testing::Values(
		IntToFloatParams{0, 0},
		IntToFloatParams{1, 1}
		// IntToIntParams{-1, -1},
		// IntToIntParams{1, 1},
		// IntToIntParams{8388608, -8388608}
		));
