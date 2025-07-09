#include "iter.h"
#include <iostream>

void plusOneInt(int& x) { x = x + 1; }
void printPlusTwo(const int& x) { std::cout << x + 2; }
void plusOneChar(char& x) { x = x + 1; }
void printPlusTwoChar(const char& x) { std::cout << static_cast< char >(x + 2); }

void withInt() {
    int arr[] = {0, 1, 2, 3, 4};
    size_t len = 5;
    iter(arr, len, &plusOneInt);
    for (size_t i = 0; i < len; i++) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void withIntConst() {
    int arr[] = {0, 1, 2, 3, 4};
    size_t len = 5;
    iter(arr, len, &printPlusTwo);
    std::cout << std::endl;
}

void withChar() {
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t len = 5;
    iter(arr, len, &plusOneChar);
    for (size_t i = 0; i < len; i++) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void withCharConst() {
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t len = 5;
    iter(arr, len, &printPlusTwoChar);
    std::cout << std::endl;
}

int main() {
    withInt();
    withIntConst();
    withChar();
    withCharConst();
    return 0;
}
