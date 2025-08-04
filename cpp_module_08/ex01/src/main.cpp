#include "Span.h"
#include <climits>
#include <iostream>

int main() {
    {
        std::cout << "(test 1) defautl test" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "(test 2) test copy constructor" << std::endl;
        // Create original span with data
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);
        // Should be 20
        std::cout << "Original span longest: " << original.longestSpan() << std::endl;

        Span copy(original);
        // should be 20
        std::cout << "Copy span longest: " << copy.longestSpan() << std::endl;

        // Try to add to copy - will work even though original is "full"
        copy.addNumber(100); // This shouldn't work if copy had original's data
        copy.addNumber(200);
        std::cout << "Copy after adding: " << copy.longestSpan() << std::endl;
        std::cout << "Original unchanged: " << original.longestSpan() << std::endl; // Still 20
    }
    std::cout << std::endl;
    {
        std::cout << "(test 3) test copy assignment operator" << std::endl;
        // Create original span with data
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);
        // Should be 20
        std::cout << "Original span longest: " << original.longestSpan() << std::endl;

        // Create another span and use assignment
        Span assigned(3);
        assigned.addNumber(5); // Put some data first
        assigned = original;   // This should copy original's data

        // should be 20
        std::cout << "Assigned span longest: " << assigned.longestSpan() << std::endl;

        // Try to add to assigned - should work since it should have original's
        // capacity
        assigned.addNumber(100);
        assigned.addNumber(200);
        std::cout << "Assigned after adding: " << assigned.longestSpan() << std::endl;
        std::cout << "Original unchanged: " << original.longestSpan() << std::endl; // Still 20
    }
    std::cout << std::endl;
    {
        std::cout << "(test 4) test integer overflow with unsigned return" << std::endl;
        Span sp(3);
        sp.addNumber(INT_MAX); // Maximum int value
        sp.addNumber(INT_MIN); // Minimum int value

        std::cout << "Values: " << INT_MAX << ", " << INT_MIN << std::endl;
        std::cout << "Expected longest span: "
                  << (static_cast< long long >(INT_MAX) - static_cast< long long >(INT_MIN)) << std::endl;

        unsigned int longest = sp.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;

        unsigned int shortest = sp.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "(test 5) test exception cases" << std::endl;
        Span sp(2);

        // Test span calculation with less than 2 elements
        try {
            std::cout << "Empty span shortest: " << sp.shortestSpan() << std::endl;
            std::cout << "Empty span longest: " << sp.longestSpan() << std::endl;
        } catch (...) {
            std::cout << "Exception with empty span" << std::endl;
        }

        sp.addNumber(42);
        try {
            std::cout << "Single element shortest: " << sp.shortestSpan() << std::endl;
            std::cout << "Single element longest: " << sp.longestSpan() << std::endl;
        } catch (...) {
            std::cout << "Exception with single element" << std::endl;
        }

        // Test capacity exceeded
        sp.addNumber(100); // Now full
        try {
            sp.addNumber(200); // Should throw
        } catch (const std::exception& e) {
            std::cout << "Capacity exceeded: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    {
        std::cout << "(test 6) test addNumbers template function" << std::endl;
        Span sp(10);

        int nums[] = {1, 5, 3, 9, 7};
        sp.addNumbers(nums, nums + 5);
        try {
            std::cout << "Added vector, longest span: " << sp.longestSpan() << std::endl;

            // Try to exceed capacity
            int more[] = {10, 20, 30, 40, 50, 60};
            sp.addNumbers(more, more + 5); // Should throw
        } catch (const std::exception& e) {
            std::cout << "addNumbers exception: " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    {
        std::cout << "(test 7) test identical values" << std::endl;
        Span sp(5);
        sp.addNumber(42);
        sp.addNumber(42);
        sp.addNumber(42);

        std::cout << "All identical - shortest: " << sp.shortestSpan() << std::endl; // Should be 0
        std::cout << "All identical - longest: " << sp.longestSpan() << std::endl;   // Should be 0
    }
    std::cout << std::endl;
    {
        std::cout << "(test 8) test addNumbers off-by-one error" << std::endl;
        Span sp(5);

        // Add 3 numbers first
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        std::cout << "Added 3 numbers, capacity is 5" << std::endl;

        // Try to add exactly 2 more numbers (should fit perfectly)
        int nums[] = {40, 50};
        try {
            sp.addNumbers(nums, nums + 2); // This should work (3 + 2 = 5)
            std::cout << "Successfully added 2 more numbers" << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "ERROR: addNumbers rejected valid insertion: " << e.what() << std::endl;
        }

        // Now try to add one more (should fail)
        int more[] = {60};
        try {
            sp.addNumbers(more, more + 1); // This should throw
            std::cout << "ERROR: Should have thrown exception!" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Correctly rejected overflow: " << e.what() << std::endl;
        }
    }
    return 0;
}
