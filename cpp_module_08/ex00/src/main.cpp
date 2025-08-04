#include "easyfind.h"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
    {
        std::cout << "Test 1: vector - element found" << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        std::vector< int > vec(arr, arr + 5);
        std::vector< int >::iterator it = easyfind(vec, 3); // Returns iterator pointing to 3
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    {
        std::cout << "Test 2: const vector - element found" << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        const std::vector< int > vec(arr, arr + 5);
        std::vector< int >::const_iterator it = easyfind(vec, 3); // Returns iterator pointing to 3
        std::cout << *it << std::endl;
    }

    {
        std::cout << "Test 3: vector - element not found" << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        std::vector< int > vec(arr, arr + 5);
        std::vector< int >::iterator it = easyfind(vec, 42);
        if (it != vec.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "Test 4: empty vector" << std::endl;
        std::vector< int > vec;
        std::vector< int >::iterator it = easyfind(vec, 1);
        if (it != vec.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found (empty container)" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "Test 5: list container" << std::endl;
        std::list< int > lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        std::list< int >::iterator it = easyfind(lst, 20);
        if (it != lst.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "Test 6: deque container" << std::endl;
        std::deque< int > dq;
        dq.push_back(100);
        dq.push_back(200);
        dq.push_back(300);
        std::deque< int >::iterator it = easyfind(dq, 300);
        if (it != dq.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "Test 7: single element container" << std::endl;
        std::vector< int > vec;
        vec.push_back(42);
        std::vector< int >::iterator it = easyfind(vec, 42);
        if (it != vec.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "Test 8: duplicate elements" << std::endl;
        int arr[] = {1, 3, 2, 3, 5};
        std::vector< int > vec(arr, arr + 5);
        std::vector< int >::iterator it = easyfind(vec, 3);
        if (it != vec.end()) {
            std::cout << "Found: " << *it << " at position: " << (it - vec.begin()) << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    return 0;
}
