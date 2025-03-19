#include "gtest/gtest.h"
#include "Fixed.hpp"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void run_test_code() {
    Fixed a;
    Fixed const b( 10 );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;

    // 8 bits for frac_bits, leaves 2^24 as range
    // 2^23 - 1 =
    Fixed const d( 8388607 );
    std::cout << "d is " << d << std::endl;

    // Fixed const c( 42.42f );
    // Fixed const d( b );
    // a = Fixed( 1234.4321f );
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;
    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

TEST(testCode, test) {
    testing::internal::CaptureStdout();
    run_test_code();
    std::string got_out = testing::internal::GetCapturedStdout();
    std::string want_out = R"(Default constructor called
Int constructor called
a is 0
b is 10
Int constructor called
d is 8388607
Destructor called
Destructor called
Destructor called
)";
    ASSERT_STREQ(want_out.c_str(), got_out.c_str());

}
