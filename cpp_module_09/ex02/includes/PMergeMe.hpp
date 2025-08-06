#ifndef PMERGEME_H
#define PMERGEME_H

#include <deque>
#include <list>
#include <map>

void binaryInsertList(std::list< int >& l, int val);
void binaryInsertDeque(std::deque< int >& l, int val);
std::list< int > buildSecondaryList(std::list< int > main, std::list< std::pair< int, int > > secondaryPairs);
std::deque< int > buildSecondaryDeque(std::deque< int > main, std::deque< std::pair< int, int > > secondaryPairs);
std::list< int > mergeInsertionList(std::list< int > values);
std::deque< int > mergeInsertionDeque(std::deque< int > values);
unsigned int jacobsthal(int n);

#endif // PMERGEME_H
