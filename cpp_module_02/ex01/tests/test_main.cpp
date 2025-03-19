#include "gtest/gtest.h"
#include "Fixed.hpp"
#include "main.hpp"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testCode, test) {
    testing::internal::CaptureStdout();
    run_test_code();
    std::string got_out = testing::internal::GetCapturedStdout();
    std::string want_out = R"(Default constructor called
Int constructor called
a is 0
b is 10
Destructor called
Destructor called
)";
    ASSERT_STREQ(want_out.c_str(), got_out.c_str());

}
