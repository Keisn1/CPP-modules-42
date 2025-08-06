#include "test_main.h"
#include "gtest/gtest.h"

struct BinaryInsertListTestParams {
    std::list< int > got;
    int value;
    std::list< int > want;
};

class BinaryInsertListSuite : public ::testing::TestWithParam< BinaryInsertListTestParams > {};

TEST_P(BinaryInsertListSuite, BinaryInsertVectorTest) {
    BinaryInsertListTestParams params = GetParam();
    binaryInsertList(params.got, params.value);
    compareList(params.want, params.got);
}

INSTANTIATE_TEST_SUITE_P(
    withList, BinaryInsertListSuite,

    testing::Values(

        BinaryInsertListTestParams{{2, 4, 6, 8, 10, 12}, 1, {1, 2, 4, 6, 8, 10, 12}},
        BinaryInsertListTestParams{{2, 4, 6, 8, 10, 12}, 3, {2, 3, 4, 6, 8, 10, 12}},
        BinaryInsertListTestParams{{2, 4, 6, 8, 10, 12}, 7, {2, 4, 6, 7, 8, 10, 12}},
        BinaryInsertListTestParams{{2, 4, 6, 8, 10, 12}, 11, {2, 4, 6, 8, 10, 11, 12}},
        BinaryInsertListTestParams{{2, 4, 6, 8, 10, 12}, 15, {2, 4, 6, 8, 10, 12, 15}},
        BinaryInsertListTestParams{{1, 3, 5, 7, 9, 11, 13}, 0, {0, 1, 3, 5, 7, 9, 11, 13}},
        BinaryInsertListTestParams{{1, 3, 5, 7, 9, 11, 13}, 4, {1, 3, 4, 5, 7, 9, 11, 13}},
        BinaryInsertListTestParams{{1, 3, 5, 7, 9, 11, 13}, 8, {1, 3, 5, 7, 8, 9, 11, 13}},
        BinaryInsertListTestParams{{1, 3, 5, 7, 9, 11, 13}, 12, {1, 3, 5, 7, 9, 11, 12, 13}},
        BinaryInsertListTestParams{{1, 3, 5, 7, 9, 11, 13}, 15, {1, 3, 5, 7, 9, 11, 13, 15}},
        BinaryInsertListTestParams{{}, 1, {1}}, BinaryInsertListTestParams{{}, 5, {5}},
        BinaryInsertListTestParams{{2}, 1, {1, 2}}, BinaryInsertListTestParams{{2}, 3, {2, 3}},
        BinaryInsertListTestParams{{1, 2, 3}, 0, {0, 1, 2, 3}}, BinaryInsertListTestParams{{1, 2, 3}, 4, {1, 2, 3, 4}},
        BinaryInsertListTestParams{{1, 2, 3}, 2, {1, 2, 2, 3}}, BinaryInsertListTestParams{{1, 3, 5}, 2, {1, 2, 3, 5}},
        BinaryInsertListTestParams{{1, 3, 5}, 4, {1, 3, 4, 5}}, BinaryInsertListTestParams{{1, 3, 5}, 6, {1, 3, 5, 6}},
        BinaryInsertListTestParams{{2, 4, 6}, 1, {1, 2, 4, 6}}, BinaryInsertListTestParams{{2, 4, 6}, 3, {2, 3, 4, 6}},
        BinaryInsertListTestParams{{2, 4, 6}, 5, {2, 4, 5, 6}},
        BinaryInsertListTestParams{{1, 2, 4, 5}, 3, {1, 2, 3, 4, 5}},
        BinaryInsertListTestParams{{10, 20, 30}, 15, {10, 15, 20, 30}},
        BinaryInsertListTestParams{{10, 20, 30}, 25, {10, 20, 25, 30}},
        BinaryInsertListTestParams{{5, 5, 5}, 5, {5, 5, 5, 5}}, BinaryInsertListTestParams{{1, 5}, 3, {1, 3, 5}},
        BinaryInsertListTestParams{{1, 2, 4}, 3, {1, 2, 3, 4}}, BinaryInsertListTestParams{{1, 3}, 2, {1, 2, 3}},
        BinaryInsertListTestParams{{1, 2}, 3, {1, 2, 3}}, BinaryInsertListTestParams{{1, 2}, 0, {0, 1, 2}},
        BinaryInsertListTestParams{{1, 3}, 4, {1, 3, 4}}, BinaryInsertListTestParams{{1, 3}, 2, {1, 2, 3}},
        BinaryInsertListTestParams{{1, 3}, 0, {0, 1, 3}}, BinaryInsertListTestParams{{1}, 2, {1, 2}},
        BinaryInsertListTestParams{{1}, 0, {0, 1}}, BinaryInsertListTestParams{{}, 0, {0}}));
