// Problem 0005
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any
// remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <cstdint>
#include <iostream>

// LCM(x, y) = x * y / GCD(x, y)
uint32_t gcd(uint32_t a, uint32_t b) {
    if (a < b) {
        return gcd(b, a);
    }
    // originally it's like this but with big numbers it's inefficient
    // return b == 0U ? a : gcd(b, a - b);
    return b == 0U ? a : gcd(b, a - (a / b) * b);
}

uint64_t lcm(uint64_t a, uint32_t b) { return a * b / gcd(a, b); }

int main() {
    std::cout << "GCD(19, 20) = " << gcd(19, 20) << '\n';
    std::cout << "LCM(19, 20) = " << lcm(19, 20) << '\n';
    uint64_t step{2U};
    for (uint8_t i = 20U; i >= 3U; i--) {
        step = lcm(step, i);
        std::cout << step << '\n';
    }
    std::cout << step << '\n';
    return 0;
}
