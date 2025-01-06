// Problem 0020
//
// n! means n x (n - 1) x ... x 3 x 2 x 1.
// For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
// and the sum of the digits in the number 10! is  3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!.

#include <array>
#include <cstdint>
#include <iostream>

int main() {
    std::array<uint16_t, 159U> digits{};
    digits.at(158U) = 1U;
    uint16_t sum{}, overflow{};

    for (uint8_t num{100U}; num > 0U; num--) {
        for (uint8_t idx{158U}; idx > 0U; idx--) {
            digits.at(idx) *= num;
            digits.at(idx) += overflow;
            overflow = digits.at(idx) / 10U;
            digits.at(idx) %= 10U;
        }
    }

    for (auto iter = digits.begin(); iter != digits.end(); iter++) {
        sum += *iter;
    }
    std::cout << "Sum of digits = " << sum << '\n';
    return 0;
}
