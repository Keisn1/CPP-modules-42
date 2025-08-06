#include "test_main.h"
#include "gtest/gtest.h"

struct MergeInsertionDequeParams {
    std::deque< int > values;
    std::deque< int > want;
};

class MergeInsertDequeSuite : public ::testing::TestWithParam< MergeInsertionDequeParams > {};

TEST_P(MergeInsertDequeSuite, MergeInstertionDequeTest) {
    MergeInsertionDequeParams params = GetParam();
    std::deque< int > got = mergeInsertionDeque(params.values);
    compareDeque(params.want, got);
}

INSTANTIATE_TEST_SUITE_P(
    withDeque, MergeInsertDequeSuite,
    testing::Values(

        MergeInsertionDequeParams{{}, {}},                                       // Empty deque
        MergeInsertionDequeParams{{5}, {5}},                                     // Single element (different from {0})
        MergeInsertionDequeParams{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},             // Already sorted
        MergeInsertionDequeParams{{5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}},             // Reverse sorted
        MergeInsertionDequeParams{{-3, -1, -5, -2}, {-5, -3, -2, -1}},           // Negative numbers
        MergeInsertionDequeParams{{-1, 0, 1}, {-1, 0, 1}},                       // Mixed positive/negative
        MergeInsertionDequeParams{{100, 50, 75, 25}, {25, 50, 75, 100}},         // Larger numbers
        MergeInsertionDequeParams{{2, 2, 2, 2}, {2, 2, 2, 2}},                   // All same elements
        MergeInsertionDequeParams{{1, 3, 2, 5, 4, 7, 6}, {1, 2, 3, 4, 5, 6, 7}}, // Odd length
        MergeInsertionDequeParams{{8, 1, 9, 2, 7, 3, 6, 4}, {1, 2, 3, 4, 6, 7, 8, 9}}, // Even length
        MergeInsertionDequeParams{{7, 6, 5, 4, 3, 2, 1}, {1, 2, 3, 4, 5, 6, 7}},
        MergeInsertionDequeParams{{3, 5, 1, 2, 3, 4}, {1, 2, 3, 3, 4, 5}},
        MergeInsertionDequeParams{{3, 5, 1, 2, 3}, {1, 2, 3, 3, 5}},
        MergeInsertionDequeParams{{3, 5, 1, 2, 3}, {1, 2, 3, 3, 5}},
        MergeInsertionDequeParams{{4, 3, 5, 1, 2}, {1, 2, 3, 4, 5}},
        MergeInsertionDequeParams{{2, 2, 1, 1}, {1, 1, 2, 2}}, MergeInsertionDequeParams{{3, 0, 1, 2}, {0, 1, 2, 3}},
        MergeInsertionDequeParams{{3, 1, 1}, {1, 1, 3}}, MergeInsertionDequeParams{{3, 0, 1}, {0, 1, 3}},
        MergeInsertionDequeParams{{1, 3, 0}, {0, 1, 3}}, MergeInsertionDequeParams{{1, 0}, {0, 1}},
        MergeInsertionDequeParams{{1, 1}, {1, 1}}, MergeInsertionDequeParams{{0}, {0}}));
