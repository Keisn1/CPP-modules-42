#include "gtest/gtest.h"
#include "Fixed.hpp"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(FixedPointTests, firstTests) {
    Fixed a;
    ASSERT_EQ(0, a.getVal());

	Fixed b(a);
    ASSERT_EQ(0, b.getVal());

    Fixed c;

	c = b;
}
