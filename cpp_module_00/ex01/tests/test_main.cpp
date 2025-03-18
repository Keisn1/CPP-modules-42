#include "test_main.hpp"

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "*PhoneBookDisplayCtct*";
    ::testing::GTEST_FLAG(filter) = "*getCmdTest*";
    return RUN_ALL_TESTS();
}

