#include "gtest/gtest.h"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "*Float*";
    // ::testing::GTEST_FLAG(filter) = "*snippet*";
    return RUN_ALL_TESTS();
}

