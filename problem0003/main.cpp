// Problem 0003
// The prime factors of 13195 are 5, 7, 13, and 29.
//
// What is the largest prime factor of the number 600851475143?

#include <cstdint>
#include <iostream>

int main() {
    constexpr uint64_t ROOT = 775147U;
    uint64_t           num  = 600851475143U;
    uint32_t           largest_prime{};
    for (uint32_t i = 2U; i <= ROOT && num > 0U; i++) {
        while (num % i == 0U) {
            num /= i;
            largest_prime = i;
        }
    }
    std::cout << largest_prime << '\n';
    return 0;
}
