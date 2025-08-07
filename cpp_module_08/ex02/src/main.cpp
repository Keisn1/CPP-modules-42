#include "MutantStack.h"
#include <iostream>
#include <list>
#include <stack>
#include <vector>

int main() {
    {
        std::cout << "(TEST 1)" << std::endl;
        std::cout << "Construction / push-pop-top / copy construction / copy assignment" << std::endl;

        {
            MutantStack< int, std::list< int > > mStack;
            mStack.showContainerType();
            mStack.push(2);
            mStack.push(17);
            std::cout << mStack.top() << std::endl;

            mStack.pop();
            std::cout << mStack.top() << std::endl;
            std::cout << mStack.size() << std::endl;
            mStack.push(3);
            mStack.push(5);
            mStack.push(737);
            std::cout << mStack.size() << std::endl;

            std::cout << "using copy constructor" << std::endl;
            MutantStack< int, std::list< int > > mcStack(mStack);
            mcStack.showContainerType();

            std::cout << mcStack.size() << std::endl;
            while (!mcStack.empty()) {
                mcStack.pop();
            }
            std::cout << mStack.size() << std::endl;

            std::cout << "using copy-assing constructor" << std::endl;
            MutantStack< int, std::list< int > > mcaStack;
            mcaStack.showContainerType();
            mcaStack = mStack;
            while (!mcaStack.empty()) {
                std::cout << mcaStack.top() << std::endl;
                mcaStack.pop();
            }
            std::cout << mStack.size() << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "(TEST 1.2) with other container type" << std::endl;
        std::cout << "Construction / push-pop-top / copy construction / copy assignment" << std::endl;

        {
            MutantStack< int, std::vector< int > > mStack;
            mStack.showContainerType();
            mStack.push(2);
            mStack.push(17);
            std::cout << mStack.top() << std::endl;

            mStack.pop();
            std::cout << mStack.top() << std::endl;
            std::cout << mStack.size() << std::endl;
            mStack.push(3);
            mStack.push(5);
            mStack.push(737);
            std::cout << mStack.size() << std::endl;
            MutantStack< int, std::vector< int > > mcStack(mStack);
            std::cout << mcStack.size() << std::endl;
            while (!mcStack.empty()) {
                mcStack.pop();
            }
            std::cout << mStack.size() << std::endl;

            MutantStack< int, std::vector< int > > mcaStack;
            mcaStack = mStack;
            while (!mcaStack.empty()) {
                std::cout << mcaStack.top() << std::endl;
                mcaStack.pop();
            }
            std::cout << mStack.size() << std::endl;
        }
    }
    {
        std::cout << "(TEST 2)" << std::endl;
        std::cout << "iterator" << std::endl;
        {

            MutantStack< int > mStack;
            mStack.push(2);
            mStack.push(17);
            mStack.push(3);
            mStack.push(5);
            mStack.push(737);

            MutantStack< int >::iterator it = mStack.begin();
            MutantStack< int >::iterator ite = mStack.end();
            it++;
            it--;
            while (it != ite) {
                std::cout << *it << std::endl;
                ++it;
            }
            std::stack< int > s(mStack);
        }
    }
    std::cout << std::endl;
    {
        std::cout << "(TEST 2.1)" << std::endl;
        std::cout << "reverse iterator" << std::endl;
        {

            MutantStack< int > mStack;
            mStack.push(2);
            mStack.push(17);
            mStack.push(3);
            mStack.push(5);
            mStack.push(737);

            MutantStack< int >::reverse_iterator it = mStack.rbegin();
            MutantStack< int >::reverse_iterator ite = mStack.rend();
            it++;
            it--;
            while (it != ite) {
                std::cout << *it << std::endl;
                ++it;
            }
            std::stack< int > s(mStack);
        }
    }
    std::cout << std::endl;
    {
        std::cout << "(TEST 2.2)" << std::endl;
        std::cout << "const iterator" << std::endl;
        {

            MutantStack< int > mStack;
            mStack.push(2);
            mStack.push(17);
            mStack.push(3);
            mStack.push(5);
            mStack.push(737);

            const MutantStack< int > mStackConst = mStack;

            MutantStack< int >::const_iterator it = mStackConst.begin();
            MutantStack< int >::const_iterator ite = mStackConst.end();
            it++;
            it--;
            while (it != ite) {
                std::cout << *it << std::endl;
                ++it;
            }
            std::stack< int > s(mStack);
        }
    }
    {
        std::cout << "(TEST 3)" << std::endl;
        std::cout << "fails if implemeneted without Container Template parameter" << std::endl;

        MutantStack< int, std::vector< int > > ms;
        ms.push(1);
        ms.push(2);

        // Try to use iterators - this should fail or behave incorrectly
        MutantStack< int, std::vector< int > >::iterator it = ms.begin();
        (void)it;
    }
}
