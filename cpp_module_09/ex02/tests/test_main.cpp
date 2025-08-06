#include "test_main.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    // testing::GTEST_FLAG(filter) = "*MergeInsertListSuite*";
    return RUN_ALL_TESTS();
    return 0;
}
