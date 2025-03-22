// #include "Fixed.hpp"
// #include "gtest/gtest.h"

// struct SnippetParams {
//      void (*snippet)(void);
//      std::string want;
// };

// class TestCodeSnippets : public::testing::TestWithParam<SnippetParams>{};

// void snippet_1() {
//      Fixed a;
//      Fixed const b( 10 );
//      std::cout << "a is " << a << std::endl;
//      std::cout << "b is " << b << std::endl;
// }

// void snippet_2() {
//      // 8 bits for frac_bits, leaves 2^24 as range
//      // 2^23 - 1 =
//      Fixed const d( 8388607 );
//      std::cout << "d is " << d << std::endl;
// }


// TEST_P(TestCodeSnippets, tests) {
//      SnippetParams params = GetParam();
//      testing::internal::CaptureStdout();
//      params.snippet();
//      std::string got = testing::internal::GetCapturedStdout();
//      ASSERT_STREQ(params.want.c_str(), got.c_str());
// }

// INSTANTIATE_TEST_SUITE_P(snippets, TestCodeSnippets,
//                           testing::Values(
//                               SnippetParams{
//                                   snippet_1, R"(Default constructor called
// Int constructor called
// a is 0
// b is 10
// Destructor called
// Destructor called
// )"}
//                               ));
