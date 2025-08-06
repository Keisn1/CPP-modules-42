#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include "PMergeMe.hpp"
#include "gtest/gtest.h"
#include <deque>
#include <gtest/gtest.h>
#include <list>

void compareDeque(std::deque< int > want, std::deque< int > got);
void compareList(std::list< int > want, std::list< int > got);
#endif // TEST_MAIN_H
