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

MergeInsertionListParams{{}, {}},  // Empty list
MergeInsertionListParams{{5}, {5}},  // Single element (different from {0})
MergeInsertionListParams{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},  // Already sorted
MergeInsertionListParams{{5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}},  // Reverse sorted
MergeInsertionListParams{{-3, -1, -5, -2}, {-5, -3, -2, -1}},  // Negative numbers
MergeInsertionListParams{{-1, 0, 1}, {-1, 0, 1}},  // Mixed positive/negative
MergeInsertionListParams{{100, 50, 75, 25}, {25, 50, 75, 100}},  // Larger numbers
MergeInsertionListParams{{2, 2, 2, 2}, {2, 2, 2, 2}},  // All same elements
MergeInsertionListParams{{1, 3, 2, 5, 4, 7, 6}, {1, 2, 3, 4, 5, 6, 7}},  // Odd length
MergeInsertionListParams{{8, 1, 9, 2, 7, 3, 6, 4}, {1, 2, 3, 4, 6, 7, 8, 9}},  // Even length
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
