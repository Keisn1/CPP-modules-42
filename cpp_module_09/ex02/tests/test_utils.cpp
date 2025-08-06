#include "test_main.h"
#include <deque>
#include <list>

void compareList(std::list< int > want, std::list< int > got) {
    ASSERT_EQ(want.size(), got.size());
    std::list< int >::iterator wantIt = want.begin();
    std::list< int >::iterator gotIt = got.begin();
    while (gotIt != got.end())
        ASSERT_EQ(*wantIt++, *gotIt++);
}

void compareDeque(std::deque< int > want, std::deque< int > got) {
    ASSERT_EQ(want.size(), got.size());
    std::deque< int >::iterator wantIt = want.begin();
    std::deque< int >::iterator gotIt = got.begin();
    while (gotIt != got.end())
        ASSERT_EQ(*wantIt++, *gotIt++);
}
