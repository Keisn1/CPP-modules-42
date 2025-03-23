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
    MULTIPLY,
    DIVIDE,
    SUBTRACT,
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
    std::cout << a/b << std::endl;
    switch (params.op) {
    case PLUS:
        ASSERT_TRUE( want == (a + b));
        break;
    case SUBTRACT:
        ASSERT_TRUE( want == (a - b));
        break;
    case MULTIPLY:
        ASSERT_TRUE( want == (a * b));
        break;
    case DIVIDE:
        ASSERT_TRUE( want == (a / b));
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
        testArithmeticParams{10, 0.1015626, 0.203125 , PLUS, 0.3046875}
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


INSTANTIATE_TEST_SUITE_P(
    Division,
    TestArithmeticSuite,
    testing::Values(
        testArithmeticParams{0, 6, 3, DIVIDE, 2},
        testArithmeticParams{1, -10, 2, DIVIDE, -5},
        testArithmeticParams{2, 9, -3, DIVIDE, -3},
        testArithmeticParams{3, 0, 1, DIVIDE, 0},
        testArithmeticParams{5, 20, 4, DIVIDE, 5},
        testArithmeticParams{5, 20, 0, DIVIDE, 0},
        testArithmeticParams{6, 7.5, 2.5, DIVIDE, 3.0},
        testArithmeticParams{7, -8.0, 4.0, DIVIDE, -2.0},
        testArithmeticParams{8, 0.0, 3.0, DIVIDE, 0.0},
        testArithmeticParams{9, 5.5, 2.0, DIVIDE, 2.75},
        testArithmeticParams{10, 9.81, 3.27, DIVIDE, 3}
        ));



INSTANTIATE_TEST_SUITE_P(
    Substraction,
    TestArithmeticSuite,
    testing::Values(
        testArithmeticParams{0, 5, 2, SUBTRACT, 3},
        testArithmeticParams{1, 10, 10, SUBTRACT, 0},
        testArithmeticParams{2, -5, -3, SUBTRACT, -2},
        testArithmeticParams{3, 0, 7, SUBTRACT, -7},
        testArithmeticParams{4, 15, 20, SUBTRACT, -5},
        testArithmeticParams{5, 7, -3, SUBTRACT, 10},
        testArithmeticParams{6, 5.5, 2.25, SUBTRACT, 3.25},
        testArithmeticParams{7, -10.0, 5.0, SUBTRACT, -15.0},
        testArithmeticParams{8, 0.0, -3.0, SUBTRACT, 3.0},
        testArithmeticParams{9, 3.1415, 3.1414, SUBTRACT, 0.0000},
        testArithmeticParams{10, 100.0, 50.5, SUBTRACT, 49.5},
        testArithmeticParams{9, 3.766, 3.1655, SUBTRACT, 0.601562}
        ));

enum IncrementOp {
    INC, // 0
    DEC,
    P_INC, // 0
    P_DEC
};

struct testIncOpParams {
    int testNbr;
    float a;
    IncrementOp op;
    float want;
};

class TestIncOpSuite : public::testing::TestWithParam<testIncOpParams>{};

TEST_P(TestIncOpSuite, testLowerThan) {
    struct testIncOpParams params = GetParam();
    Fixed a(params.a);
    Fixed want(params.want);

    switch (params.op) {
    case INC:
        ++a;
        ASSERT_TRUE( want == a);
        break;
    case DEC:
        --a;
        ASSERT_TRUE( want == a);
        break;
    case P_INC:
        a++;
        ASSERT_TRUE( want == a);
        break;
    case P_DEC:
        a--;
        ASSERT_TRUE( want == a);
        break;
    }
}

INSTANTIATE_TEST_SUITE_P(
    Increment,
    TestIncOpSuite,
    testing::Values(
        testIncOpParams{0, 0, INC, 0.00390625},
        testIncOpParams{0, 5, INC, 5.00390625},
        testIncOpParams{0, 2.25, INC, 2.25390625}
        ));

INSTANTIATE_TEST_SUITE_P(
    P_Increment,
    TestIncOpSuite,
    testing::Values(
        testIncOpParams{0, 0, P_INC, 0.00390625},
        testIncOpParams{0, 5, P_INC, 5.00390625},
        testIncOpParams{0, 2.25, P_INC, 2.25390625}
        ));

INSTANTIATE_TEST_SUITE_P(
    Decrement,
    TestIncOpSuite,
    testing::Values(
        testIncOpParams{0, 0, DEC, -0.00390625},
        testIncOpParams{0, -5, DEC, -5.00390625},
        testIncOpParams{0, 2.25, DEC, 2.24609375}
        ));

INSTANTIATE_TEST_SUITE_P(
    P_Decrement,
    TestIncOpSuite,
    testing::Values(
        testIncOpParams{0, 0, P_DEC, -0.00390625},
        testIncOpParams{0, -5, P_DEC, -5.00390625},
        testIncOpParams{0, 2.25, P_DEC, 2.24609375}
        ));


enum MinMaxOp {
  MIN,
  MAX,
  MIN_CONST,
  MAX_CONST,
};

struct testMinMaxParams {
    int testNbr;
    float a;
    float b;
    MinMaxOp op;
};

class TestMinMaxSuite : public::testing::TestWithParam<testMinMaxParams>{};

TEST_P(TestMinMaxSuite, testLowerThan) {
    struct testMinMaxParams params = GetParam();
	Fixed a(params.a);
	Fixed b(params.b);
	const Fixed const_a(params.a);
	const Fixed const_b(params.b);

    switch (params.op) {
    case MIN:
        if (a <= b)
            ASSERT_EQ(&Fixed::min(a, b), &a); // c should be a reference to small if small < big
        else
            ASSERT_EQ(&Fixed::min(a, b), &b);   // Otherwise c should be a reference to big
        break;
    case MIN_CONST:
        if (a <= b)
            ASSERT_EQ(&Fixed::min(const_a, const_b), &const_a); // c should be a reference to small if small < big
        else
            ASSERT_EQ(&Fixed::min(const_a, const_b), &const_b);   // Otherwise c should be a reference to big
        break;
    case MAX:
        if (a >= b)
            ASSERT_EQ(&Fixed::max(a, b), &a); // c should be a reference to small if small < big
        else
            ASSERT_EQ(&Fixed::max(a, b), &b);   // Otherwise c should be a reference to big
        break;
    case MAX_CONST:
        if (a >= b)
            ASSERT_EQ(&Fixed::max(const_a, b), &const_a); // c should be a reference to small if small < big
        else
            ASSERT_EQ(&Fixed::max(const_a, const_b), &const_b);   // Otherwise c should be a reference to big
        break;
    }
}

INSTANTIATE_TEST_SUITE_P(
    MinMax,
    TestMinMaxSuite,
    testing::Values(
        testMinMaxParams{0, 0, 1, MIN},
        testMinMaxParams{1, 1, 1, MIN},
        testMinMaxParams{2, 2, 1, MIN},
        testMinMaxParams{3, 0.0, 0.00390625, MIN},
        testMinMaxParams{4, 0.0, 0.00390624, MIN},
        testMinMaxParams{5, 0.0, -0.00390624, MIN},
        testMinMaxParams{6, 0.0, -0.00390625, MIN},
        testMinMaxParams{7, 0.0, -0.0000001, MIN},
        testMinMaxParams{8, 1.0, 1.0000001, MIN},
        testMinMaxParams{9, -1.0, -1.0000001, MIN},
        testMinMaxParams{10, 0, 1, MAX},
        testMinMaxParams{11, 1, 1, MAX},
        testMinMaxParams{12, 2, 1, MAX},
        testMinMaxParams{13, 0.0, 0.00390625, MAX},
        testMinMaxParams{14, 0.0, 0.00390624, MAX},
        testMinMaxParams{15, 0.0, -0.00390624, MAX},
        testMinMaxParams{16, 0.0, -0.00390625, MAX},
        testMinMaxParams{17, 0.0, -0.0000001, MAX},
        testMinMaxParams{18, 1.0, 1.0000001, MAX},
        testMinMaxParams{19, -1.0, -1.0000001, MAX},
        testMinMaxParams{20, 0, 1, MIN_CONST},
        testMinMaxParams{21, 1, 1, MIN_CONST},
        testMinMaxParams{22, 2, 1, MIN_CONST},
        testMinMaxParams{23, 0.0, 0.00390625, MIN_CONST},
        testMinMaxParams{24, 0.0, 0.00390624, MIN_CONST},
        testMinMaxParams{25, 0.0, -0.00390624, MIN_CONST},
        testMinMaxParams{26, 0.0, -0.00390625, MIN_CONST},
        testMinMaxParams{27, 0.0, -0.0000001, MIN_CONST},
        testMinMaxParams{28, 1.0, 1.0000001, MIN_CONST},
        testMinMaxParams{29, -1.0, -1.0000001, MIN_CONST},
        testMinMaxParams{30, 0, 1, MAX_CONST},
        testMinMaxParams{31, 1, 1, MAX_CONST},
        testMinMaxParams{32, 2, 1, MAX_CONST},
        testMinMaxParams{33, 0.0, 0.00390625, MAX_CONST},
        testMinMaxParams{34, 0.0, 0.00390624, MAX_CONST},
        testMinMaxParams{35, 0.0, -0.00390624, MAX_CONST},
        testMinMaxParams{36, 0.0, -0.00390625, MAX_CONST},
        testMinMaxParams{37, 0.0, -0.0000001, MAX_CONST},
        testMinMaxParams{38, 1.0, 1.0000001, MAX_CONST},
        testMinMaxParams{39, -1.0, -1.0000001, MAX_CONST}
        ));
