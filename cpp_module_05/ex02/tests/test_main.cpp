#include "AForm.h"
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

        EXPECT_THROW(pbf.execute(b), AForm::FormNotSignedException);
    }
    {
        // NOTE: 6 is too low of a grade, therefore it fails
        Bureaucrat b("Rastafarix", 6);
        PresidentialPardonForm pbf("Bibi Blocksberg");

        // sign the form before executing
        b.signForm(pbf);

        // execute form with unsufficient grade
        EXPECT_THROW(pbf.execute(b), AForm::GradeTooLowException);
    }
    {
        // NOTE: Form is not signed
        Bureaucrat b("Rastafarix", 5);
        PresidentialPardonForm pbf("Bibi Blocksberg");

        // execute form with unsufficient grade
        EXPECT_THROW(pbf.execute(b), AForm::FormNotSignedException);
    }
    {
        Bureaucrat b("Rastafarix", 5);
        PresidentialPardonForm pbf("Bibi Blocksberg");
        // sign the form before executing
        b.signForm(pbf);

        // execute the form
        testing::internal::CaptureStdout();
        b.executeForm(pbf);
        std::string got = testing::internal::GetCapturedStdout();

        std::string want = "Bibi Blocksberg has been pardoned by Zaphod Beeblebrox\n"
                           "Rastafarix executed Presidential Pardon\n";
        ASSERT_EQ(want, got);
    }
}
