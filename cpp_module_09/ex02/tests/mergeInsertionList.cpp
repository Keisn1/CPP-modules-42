#include "test_main.h"
#include "gtest/gtest.h"

struct MergeInsertionListParams {
    std::list< int > values;
    std::list< int > want;
};

class MergeInsertListSuite : public ::testing::TestWithParam< MergeInsertionListParams > {};

TEST_P(MergeInsertListSuite, MergeInstertionListTest) {
    MergeInsertionListParams params = GetParam();
    std::list< int > got = mergeInsertionList(params.values);
    compareList(params.want, got);
}


INSTANTIATE_TEST_SUITE_P(
	withList,
	MergeInsertListSuite,
	testing::Values(
		MergeInsertionListParams { {1, 3, 0}, {0, 1, 3} },
		MergeInsertionListParams { {1, 0}, {0, 1} },
		MergeInsertionListParams { {0}, {0} }
		));
