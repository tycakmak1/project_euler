// Problem 0001
// If we list all the natural numbers below 10
// that are multiples of 3 or 5, we get 3, 5, 6, and 9.
// The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <cstdint>
#include <iostream>

int main() {
    uint32_t sum{};
    for (uint16_t i = 0U; i < 1000U; i++) {
        if (i % 3U == 0U || i % 5U == 0U) {
            sum += i;
        }
    }
    std::cout << sum << '\n';
    return 0;
}
