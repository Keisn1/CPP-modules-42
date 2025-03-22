#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include "Fixed.hpp"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

enum ComparisonOp {
  LT, // 0
  GT, // 1
  LEQ,
  GEQ,
  EQ,
  NEQ
};

struct testOperatorsParams {
    int testNbr;
    float a;
    float b;
    ComparisonOp op;
    bool want;
};

class TestOperatorsSuite : public::testing::TestWithParam<testOperatorsParams>{};

TEST_P(TestOperatorsSuite, testLowerThan) {
    struct testOperatorsParams params = GetParam();
    Fixed a(params.a);
    Fixed b(params.b);

    switch (params.op) {
    case LT:
        ASSERT_EQ(params.want, a < b);
        break;
    case GT:
        ASSERT_EQ(params.want, a > b);
        break;
    case LEQ:
        ASSERT_EQ(params.want, a <= b);
        break;
    case GEQ:
        ASSERT_EQ(params.want, a >= b);
        break;
    case EQ:
        ASSERT_EQ(params.want, a == b);
        break;
    case NEQ:
        ASSERT_EQ(params.want, a >= b);
        break;
    }
}

INSTANTIATE_TEST_SUITE_P(lowerThan, TestOperatorsSuite,
                         testing::Values(
                             testOperatorsParams{0, 0, 1, LT, true},
                             testOperatorsParams{1, 0, 2, LT, true},
                             testOperatorsParams{2, 1, 0, LT, false},
                             testOperatorsParams{3, 10, 0, LT, false},
                             testOperatorsParams{4, 0.1, 0.2, LT, true},
                             testOperatorsParams{5, -0.1, -0.2, LT, false},
                             testOperatorsParams{6, 0.1, 0.1000001, LT, false},
                             testOperatorsParams{7, 0, 1, GT, false},
                             testOperatorsParams{8, 0, 2, GT, false},
                             testOperatorsParams{9, 1, 0, GT, true},
                             testOperatorsParams{10, 2, 0, GT, true},
                             testOperatorsParams{11, 0.1, 0.1000001, GT, false},
                             testOperatorsParams{12, 2.2, -0.02, GT, true},
                             testOperatorsParams{13, 0, 1, LEQ, true},
                             testOperatorsParams{14, 0, 2, LEQ, true},
                             testOperatorsParams{15, 1, 0, LEQ, false},
                             testOperatorsParams{16, 10, 0, LEQ, false},
                             testOperatorsParams{17, 0.1, 0.2, LEQ, true},
                             testOperatorsParams{18, -0.1, -0.2, LEQ, false},
                             testOperatorsParams{19, 0.1, 0.1000001, LEQ, true},
                             testOperatorsParams{20, 0, 1, GEQ, false},
                             testOperatorsParams{21, 0, 2, GEQ, false},
                             testOperatorsParams{22, 1, 0, GEQ, true},
                             testOperatorsParams{23, 2, 0, GEQ, true},
                             testOperatorsParams{24, 0.1, 0.1000001, GEQ, true},
                             testOperatorsParams{25, 2.2, -0.02, GEQ, true},
                             testOperatorsParams{25, 0.308594, 0.308594, EQ, true}
                             ));


enum ArithmeticOp {
    PLUS, // 0
    MULTIPLY // 0
};

struct testArithmeticParams {
    int testNbr;
    float a;
    float b;
    ArithmeticOp op;
    float want;
};

class TestArithmeticSuite : public::testing::TestWithParam<testArithmeticParams>{};

TEST_P(TestArithmeticSuite, testLowerThan) {
    struct testArithmeticParams params = GetParam();
    Fixed a(params.a);
    Fixed b(params.b);
    Fixed want(params.want);

    std::cout << "1: " << a*b << std::endl;

    switch (params.op) {
    case PLUS:
        ASSERT_TRUE( want == (a + b));
        break;
    case MULTIPLY:
        ASSERT_TRUE( want == (a * b));
        break;
    }
}

INSTANTIATE_TEST_SUITE_P(
    Plus,
    TestArithmeticSuite,
    testing::Values(
        testArithmeticParams{0, 0, 0, PLUS, 0},
        testArithmeticParams{1, 1, 0, PLUS, 1},
        testArithmeticParams{2, 1, 1, PLUS, 2},
        testArithmeticParams{3, 1, 2, PLUS, 3},
        testArithmeticParams{4, 2, 2, PLUS, 4},
        testArithmeticParams{5, 1.0, 1.0, PLUS, 2.0},
        testArithmeticParams{6, 1.5, 2.5, PLUS, 4.0},
        testArithmeticParams{7, 2.0, 3.5, PLUS, 5.5},
        testArithmeticParams{8, 0.0, 0.0, PLUS, 0.0},
        testArithmeticParams{9, 0.1015625, 0.203125 , PLUS, 0.3046875},
        testArithmeticParams{10, 0.1015626, 0.203125 , PLUS, 0.30859375}
        ));

INSTANTIATE_TEST_SUITE_P(
    Multiply,
    TestArithmeticSuite,
    testing::Values(testArithmeticParams{0, 0, 0, MULTIPLY, 0},
                    testArithmeticParams{1, 2, 3, MULTIPLY, 6},
                    testArithmeticParams{2, -1, 5, MULTIPLY, -5},
                    testArithmeticParams{3, 7, 0, MULTIPLY, 0},
                    testArithmeticParams{4, -3, -4, MULTIPLY, 12},
                    testArithmeticParams{5, 10, 10, MULTIPLY, 100},

                    testArithmeticParams{6, 1.5, 2.0, MULTIPLY, 3.0},
                    testArithmeticParams{7, -2.5, 4.0, MULTIPLY, -10.0},
                    testArithmeticParams{8, 0.0, 0.0, MULTIPLY, 0.0},
                    testArithmeticParams{9, 3.14, 2.71, MULTIPLY, 8.51562},
                    testArithmeticParams{10, -1.5, -2.5, MULTIPLY, 3.75}
        ));
