#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(presidentialPardonFormTest, firstTests) {
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
        Bureaucrat* b = new Bureaucrat("Miraculix", 5);
        PresidentialPardonForm* pbf1 = new PresidentialPardonForm("Captain Jack Sparrow");
        PresidentialPardonForm pbf2 = *pbf1;
        // sign the form before executing
        b->signForm(pbf2);
        ASSERT_FALSE(pbf1->isSigned());
        ASSERT_TRUE(pbf2.isSigned());

        // execute the form
        testing::internal::CaptureStdout();
        pbf2.execute(*b);
        std::string got = testing::internal::GetCapturedStdout();
        ASSERT_EQ("Captain Jack Sparrow has been pardoned by Zaphod Beeblebrox\n", got);
        delete b;
        delete pbf1;
    }
    {
        Bureaucrat* b = new Bureaucrat("Miraculix", 5);
        PresidentialPardonForm* pbf1 = new PresidentialPardonForm("Captain Jack Sparrow");
        PresidentialPardonForm* pbf2 = new PresidentialPardonForm("Bibi Blocksberg");
        // sign the form before executing
        b->signForm(*pbf2);
        ASSERT_FALSE(pbf1->isSigned());
        ASSERT_TRUE(pbf2->isSigned());

        *pbf1 = *pbf2;
        // NOTE: pbf1 is still not signed, since pbf1 _signed is private and is not copied
        // NOTE: pbf1 has also still the same target since it is constant
        // execute the form

        EXPECT_THROW(pbf1->execute(*b), AForm::FormNotSignedException);
        testing::internal::CaptureStdout();
        pbf2->execute(*b);
        std::string got = testing::internal::GetCapturedStdout();
        ASSERT_EQ("Bibi Blocksberg has been pardoned by Zaphod Beeblebrox\n", got);
        delete b;
        delete pbf1;
        delete pbf2;
    }
    // {
    //     Bureaucrat b("Miraculix", 5);
    //     PresidentialPardonForm pbf("Bibi Blocksberg");
    //     // sign the form before executing
    //     b.signForm(pbf);
    //     ASSERT_TRUE(pbf.isSigned());

    //     // execute the form
    //     testing::internal::CaptureStdout();
    //     pbf.execute(b);
    //     std::string got = testing::internal::GetCapturedStdout();
    //     ASSERT_EQ("Bibi Blocksberg has been pardoned by Zaphod Beeblebrox\n", got);
    // }
    // {
    //     Bureaucrat b("Miraculix", 5);
    //     PresidentialPardonForm pbf("Bibi Blocksberg");

    //     EXPECT_THROW(pbf.execute(b), AForm::FormNotSignedException);
    // }
    // {
    //     // NOTE: 6 is too low of a grade, therefore it fails
    //     Bureaucrat b("Rastafarix", 6);
    //     PresidentialPardonForm pbf("Bibi Blocksberg");

    //     // sign the form before executing
    //     b.signForm(pbf);

    //     // execute form with unsufficient grade
    //     EXPECT_THROW(pbf.execute(b), AForm::GradeTooLowException);
    // }
    // {
    //     // NOTE: Form is not signed
    //     Bureaucrat b("Rastafarix", 5);
    //     PresidentialPardonForm pbf("Bibi Blocksberg");

    //     // execute form with unsufficient grade
    //     EXPECT_THROW(pbf.execute(b), AForm::FormNotSignedException);
    // }
    // {
    //     Bureaucrat b("Rastafarix", 5);
    //     PresidentialPardonForm pbf("Bibi Blocksberg");
    //     // sign the form before executing
    //     b.signForm(pbf);

    //     // execute the form
    //     testing::internal::CaptureStdout();
    //     b.executeForm(pbf);
    //     std::string got = testing::internal::GetCapturedStdout();

    //     std::string want = "Bibi Blocksberg has been pardoned by Zaphod Beeblebrox\n"
    //                        "Rastafarix executed Presidential Pardon\n";
    //     ASSERT_EQ(want, got);
    // }
}
