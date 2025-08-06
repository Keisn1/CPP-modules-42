#ifndef PMERGEME_H
#define PMERGEME_H

#include <deque>
#include <list>
#include <map>

void binaryInsertList(std::list< int >& l, int val);
void binaryInsertDeque(std::deque< int >& l, int val);
std::list< int > buildSecondaryList(std::list< int > main, std::list< std::pair< int, int > > secondaryPairs);
std::list< int > mergeInsertionList(std::list< int > values);

#endif // PMERGEME_H
