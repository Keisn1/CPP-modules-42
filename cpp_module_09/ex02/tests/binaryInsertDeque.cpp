#include "PMergeMe.hpp"
#include "test_main.h"
#include "gtest/gtest.h"

struct BinaryInsertDequeTestParams {
    std::deque< int > got;
    int value;
    std::deque< int > want;
};

class BinaryInsertDequeSuite : public ::testing::TestWithParam< BinaryInsertDequeTestParams > {};

TEST_P(BinaryInsertDequeSuite, BinaryInsertVectorTest) {
    BinaryInsertDequeTestParams params = GetParam();
    binaryInsertDeque(params.got, params.value);
    compareDeque(params.want, params.got);
}

INSTANTIATE_TEST_SUITE_P(
    withDeque, BinaryInsertDequeSuite,

    testing::Values(

        BinaryInsertDequeTestParams{{2, 4, 6, 8, 10, 12}, 1, {1, 2, 4, 6, 8, 10, 12}},
        BinaryInsertDequeTestParams{{2, 4, 6, 8, 10, 12}, 3, {2, 3, 4, 6, 8, 10, 12}},
        BinaryInsertDequeTestParams{{2, 4, 6, 8, 10, 12}, 7, {2, 4, 6, 7, 8, 10, 12}},
        BinaryInsertDequeTestParams{{2, 4, 6, 8, 10, 12}, 11, {2, 4, 6, 8, 10, 11, 12}},
        BinaryInsertDequeTestParams{{2, 4, 6, 8, 10, 12}, 15, {2, 4, 6, 8, 10, 12, 15}},
        BinaryInsertDequeTestParams{{1, 3, 5, 7, 9, 11, 13}, 0, {0, 1, 3, 5, 7, 9, 11, 13}},
        BinaryInsertDequeTestParams{{1, 3, 5, 7, 9, 11, 13}, 4, {1, 3, 4, 5, 7, 9, 11, 13}},
        BinaryInsertDequeTestParams{{1, 3, 5, 7, 9, 11, 13}, 8, {1, 3, 5, 7, 8, 9, 11, 13}},
        BinaryInsertDequeTestParams{{1, 3, 5, 7, 9, 11, 13}, 12, {1, 3, 5, 7, 9, 11, 12, 13}},
        BinaryInsertDequeTestParams{{1, 3, 5, 7, 9, 11, 13}, 15, {1, 3, 5, 7, 9, 11, 13, 15}},
        BinaryInsertDequeTestParams{{}, 1, {1}}, BinaryInsertDequeTestParams{{}, 5, {5}},
        BinaryInsertDequeTestParams{{2}, 1, {1, 2}}, BinaryInsertDequeTestParams{{2}, 3, {2, 3}},
        BinaryInsertDequeTestParams{{1, 2, 3}, 0, {0, 1, 2, 3}},
        BinaryInsertDequeTestParams{{1, 2, 3}, 4, {1, 2, 3, 4}},
        BinaryInsertDequeTestParams{{1, 2, 3}, 2, {1, 2, 2, 3}},
        BinaryInsertDequeTestParams{{1, 3, 5}, 2, {1, 2, 3, 5}},
        BinaryInsertDequeTestParams{{1, 3, 5}, 4, {1, 3, 4, 5}},
        BinaryInsertDequeTestParams{{1, 3, 5}, 6, {1, 3, 5, 6}},
        BinaryInsertDequeTestParams{{2, 4, 6}, 1, {1, 2, 4, 6}},
        BinaryInsertDequeTestParams{{2, 4, 6}, 3, {2, 3, 4, 6}},
        BinaryInsertDequeTestParams{{2, 4, 6}, 5, {2, 4, 5, 6}},
        BinaryInsertDequeTestParams{{1, 2, 4, 5}, 3, {1, 2, 3, 4, 5}},
        BinaryInsertDequeTestParams{{10, 20, 30}, 15, {10, 15, 20, 30}},
        BinaryInsertDequeTestParams{{10, 20, 30}, 25, {10, 20, 25, 30}},
        BinaryInsertDequeTestParams{{5, 5, 5}, 5, {5, 5, 5, 5}}, BinaryInsertDequeTestParams{{1, 5}, 3, {1, 3, 5}},
        BinaryInsertDequeTestParams{{1, 2, 4}, 3, {1, 2, 3, 4}}, BinaryInsertDequeTestParams{{1, 3}, 2, {1, 2, 3}},
        BinaryInsertDequeTestParams{{1, 2}, 3, {1, 2, 3}}, BinaryInsertDequeTestParams{{1, 2}, 0, {0, 1, 2}},
        BinaryInsertDequeTestParams{{1, 3}, 4, {1, 3, 4}}, BinaryInsertDequeTestParams{{1, 3}, 2, {1, 2, 3}},
        BinaryInsertDequeTestParams{{1, 3}, 0, {0, 1, 3}}, BinaryInsertDequeTestParams{{1}, 2, {1, 2}},
        BinaryInsertDequeTestParams{{1}, 0, {0, 1}}, BinaryInsertDequeTestParams{{}, 0, {0}}));
