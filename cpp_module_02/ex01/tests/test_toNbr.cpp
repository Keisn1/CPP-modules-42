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
		IntToFloatParams{1, 1},
		IntToFloatParams{-1, -1},
		IntToFloatParams{8388608, -8388608}
		));

struct FloatToFloatParams {
	float in_val;
	float want;
};

class TestFloatToFloatSuite : public::testing::TestWithParam<FloatToFloatParams>{};

TEST_P(TestFloatToFloatSuite, tests) {
	FloatToFloatParams params = GetParam();
	Fixed a (params.in_val);
	float got = a.toFloat();
	ASSERT_EQ(params.want, got);
}

INSTANTIATE_TEST_SUITE_P(
	nbrConv,
	// the smallest that you can add is 2^-8 = 0.390625
	TestFloatToFloatSuite, testing::Values(
		FloatToFloatParams{0, 0},
		FloatToFloatParams{0.5, 0.5},
		FloatToFloatParams{1.5, 1.5},
		FloatToFloatParams{-0.5, -0.5},
		FloatToFloatParams{-1.5, -1.5},
		FloatToFloatParams{-8388607.5, -8388607.5},
		FloatToFloatParams{-8388608.5, -8388608.5},
		FloatToFloatParams{0.75, 0.75},
		FloatToFloatParams{-1.75, -1.75},
		FloatToFloatParams{13.999999, 13.99609375},
		FloatToFloatParams{-13.999999, -13.99609375},
		FloatToFloatParams{-8388607.63, -8388607.62890625},
		FloatToFloatParams{-42.42, -42.421875},
		FloatToFloatParams{42.42, 42.421875}
		));
