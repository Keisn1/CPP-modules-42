#include "easyfind.h"
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector< int > vec(arr, arr + 5);
    std::vector< int >::iterator it = easyfind(vec, 3); // Returns iterator pointing to 3
    std::cout << *it << std::endl;

    return 0;
}
