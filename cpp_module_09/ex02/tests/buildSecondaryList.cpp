#include "PMergeMe.hpp"
#include "test_main.h"

struct BuildSecondaryListTestParams {
    std::list< int > main;
    std::list< std::pair< int, int > > secondaryPairs;
    std::list< int > want;
};

class BuildSecondaryListSuite : public ::testing::TestWithParam< BuildSecondaryListTestParams > {};

TEST_P(BuildSecondaryListSuite, BuildSecondaryListTest) {
    BuildSecondaryListTestParams params = GetParam();
    std::list< int > result = buildSecondaryList(params.main, params.secondaryPairs);
    compareList(params.want, result);
}

INSTANTIATE_TEST_SUITE_P(
    withPairs, BuildSecondaryListSuite,
    testing::Values(
        // Basic case: pairs in order
        BuildSecondaryListTestParams{{2, 4, 6}, {{1, 2}, {3, 4}, {5, 6}}, {1, 3, 5}},
        BuildSecondaryListTestParams{{2, 4, 6}, {{3, 4}, {1, 2}, {5, 6}}, {1, 3, 5}},
        BuildSecondaryListTestParams{{2, 4, 6}, {{5, 6}, {3, 4}, {1, 2}}, {1, 3, 5}},
        // // Single pair
        BuildSecondaryListTestParams{{4}, {{3, 4}}, {3}},

        // // Multiple pairs with same secondary value (edge case)
        BuildSecondaryListTestParams{{4, 4}, {{1, 4}, {2, 4}}, {2, 1}},
        BuildSecondaryListTestParams{{4, 4}, {{2, 4}, {1, 4}}, {1, 2}},

        // Larger lists to test scalability
        BuildSecondaryListTestParams{{2, 4, 6, 8, 10}, {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}}, {1, 3, 5, 7, 9}},

        // Empty lists
        BuildSecondaryListTestParams{{}, {}, {}},

        // Same secondary values in pairs (stress test)
        BuildSecondaryListTestParams{{5, 5, 5}, {{1, 5}, {2, 5}, {3, 5}}, {3, 2, 1}},

        BuildSecondaryListTestParams{{42}, {{41, 42}}, {41}},

        BuildSecondaryListTestParams{{2, 4, 6, 8}, {{7, 8}, {1, 2}, {5, 6}, {3, 4}}, {1, 3, 5, 7}},

        // // Reverse order pairs
        BuildSecondaryListTestParams{{2, 4, 6}, {{5, 6}, {3, 4}, {1, 2}}, {1, 3, 5}},

        // // Random scramble
        BuildSecondaryListTestParams{
            {10, 20, 30, 40, 50}, {{19, 20}, {49, 50}, {9, 10}, {39, 40}, {29, 30}}, {9, 19, 29, 39, 49}},

        // Mixed up with duplicates
        BuildSecondaryListTestParams { {5, 5, 7 }, {{6, 7}, {4, 5}, {3, 5}}, {3, 4, 6} }
        ));
