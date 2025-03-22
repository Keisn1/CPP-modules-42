#include "Fixed.hpp"

int multiply(int a, int b) {
	int result = 0; // Result of multiplication

	while (b != 0) { // Iterate through all bits of b
		if (b & 1) { // If the current bit of b is 1
			result = result + a; // Add a to the result
		}
		a <<= 1; // Shift a to the left (equivalent to multiplying by 2)
		b >>= 1; // Shift b to the right (equivalent to dividing by 2)
	}

	return result;
}

int add(int a, int b) {
	while (b != 0) {
		// Calculate carry
		int carry = a & b;

        // Sum without carry
        a = a ^ b;

        // Calculate next carry
        b = carry << 1;
    }
    return a;
}
