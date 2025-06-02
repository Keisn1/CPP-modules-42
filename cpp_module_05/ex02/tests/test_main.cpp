#include "Bureaucrat.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(presedentialPardonFormTest, firstTests) {
    Bureaucrat b("Macron", 10);
    PresidentialPardonForm pbf("Presidential Pardon", 25, 5);

    pbf.execute(b);
    ASSERT_TRUE(pbf.isSigned());

}
