#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(presedentialPardonFormTest, firstTests) {
    {
        Bureaucrat b("Miraculix", 5);
        PresidentialPardonForm pbf("Captain Jack Sparrow");
        // sign the form before executing
        b.signForm(pbf);
        ASSERT_TRUE(pbf.isSigned());

        // execute the form
        testing::internal::CaptureStdout();
        pbf.execute(b);
        std::string got = testing::internal::GetCapturedStdout();
        ASSERT_EQ("Captain Jack Sparrow has been pardoned by Zaphod Beeblebrox\n", got);
    }
    {
        Bureaucrat b("Miraculix", 5);
        PresidentialPardonForm pbf("Bibi Blocksberg");
        // sign the form before executing
        b.signForm(pbf);
        ASSERT_TRUE(pbf.isSigned());

        // execute the form
        testing::internal::CaptureStdout();
        pbf.execute(b);
        std::string got = testing::internal::GetCapturedStdout();
        ASSERT_EQ("Bibi Blocksberg has been pardoned by Zaphod Beeblebrox\n", got);
    }
    {
        Bureaucrat b("Miraculix", 5);
        PresidentialPardonForm pbf("Bibi Blocksberg");

        // execute the unsigned form
        testing::internal::CaptureStdout();
        pbf.execute(b);
        std::string got = testing::internal::GetCapturedStdout();
        ASSERT_EQ("Could not exec Presidential Pardon due to Exception: Form was not signed\n", got);
    }
    {
        Bureaucrat b("Rastafarix", 6);
        PresidentialPardonForm pbf("Bibi Blocksberg");
        // sign the form before executing
        b.signForm(pbf);

        // execute form with unsufficient grade
        testing::internal::CaptureStdout();
        pbf.execute(b);
        std::string got = testing::internal::GetCapturedStdout();
        ASSERT_EQ("Could not exec Presidential Pardon due to Exception: Grade too low\n", got);
    }
}
