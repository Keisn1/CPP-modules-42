#include "Fixed.hpp"
#include "gtest/gtest.h"

struct SnippetParams {
     void (*snippet)(void);
     std::string want;
};

class TestCodeSnippets : public::testing::TestWithParam<SnippetParams>{};

void snippet_1() {
     Fixed a;
     Fixed const b( 10 );
     std::cout << "a is " << a << std::endl;
     std::cout << "b is " << b << std::endl;
}

void snippet_2() {
     // 8 bits for frac_bits, leaves 2^24 as range
     // 2^23 - 1 =
     Fixed const d( 8388607 );
     std::cout << "d is " << d << std::endl;
}

void snippet_3() {
    Fixed
        a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}


TEST_P(TestCodeSnippets, tests) {
     SnippetParams params = GetParam();
     testing::internal::CaptureStdout();
     params.snippet();
     std::string got = testing::internal::GetCapturedStdout();
     ASSERT_STREQ(params.want.c_str(), got.c_str());
}

INSTANTIATE_TEST_SUITE_P(
    snippets, TestCodeSnippets,
    testing::Values(SnippetParams{snippet_1, R"(Default constructor called
Int constructor called
a is 0
b is 10
Destructor called
Destructor called
)"},
        SnippetParams{
snippet_3, R"(Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
)"}
                              ));
