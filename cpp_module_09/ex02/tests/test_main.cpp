#include "test_main.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(filter) = "*BuildSecondaryListSuite*";
    return RUN_ALL_TESTS();
    return 0;
}
