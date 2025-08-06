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

INSTANTIATE_TEST_SUITE_P(withList, MergeInsertListSuite,
                         testing::Values(
                             MergeInsertionListParams{{7, 6, 5, 4, 3, 2, 1}, {1, 2, 3, 4, 5, 6, 7}},
                                         MergeInsertionListParams{{3, 5, 1, 2, 3, 4}, {1, 2, 3, 3, 4, 5}},
                                         MergeInsertionListParams{{3, 5, 1, 2, 3}, {1, 2, 3, 3, 5}},
                                         MergeInsertionListParams{{3, 5, 1, 2, 3}, {1, 2, 3, 3, 5}},
                                         MergeInsertionListParams{{4, 3, 5, 1, 2}, {1, 2, 3, 4, 5}},
                                         MergeInsertionListParams{{2, 2, 1, 1}, {1, 1, 2, 2}},
                                         MergeInsertionListParams{{3, 0, 1, 2}, {0, 1, 2, 3}},
                                         MergeInsertionListParams{{3, 1, 1}, {1, 1, 3}},
                                         MergeInsertionListParams{{3, 0, 1}, {0, 1, 3}},
                                         MergeInsertionListParams{{1, 3, 0}, {0, 1, 3}},
                                         MergeInsertionListParams{{1, 0}, {0, 1}},
                                         MergeInsertionListParams{{1, 1}, {1, 1}},
                             MergeInsertionListParams{{0}, {0}}));
