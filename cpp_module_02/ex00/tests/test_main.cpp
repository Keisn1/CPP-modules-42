#include "gtest/gtest.h"
#include "Fixed.hpp"
#include "main.hpp"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(FixedPointTests, firstTests) {
    testing::internal::CaptureStdout();
    run_test_code();
    std::string got_out = testing::internal::GetCapturedStdout();
    std::string want_out = R"(Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
)";
    ASSERT_STREQ(want_out.c_str(), got_out.c_str());
        }
