// Problem 0016
//
// 2^15  = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?

#include <array>
#include <cstdint>
#include <iostream>

int main() {
    uint16_t sum{}, overflow{};

    std::array<uint8_t, 302U> digits{};
    digits.at(301U) = 2U;

    for (uint16_t i{1U}; i < 1000U; i++) {
        for (uint16_t idx{301U}; idx > 0U; idx--) {
            static_cast<uint8_t>(digits.at(idx) *= 2U);
            static_cast<uint8_t>(digits.at(idx) += overflow);
            static_cast<uint8_t>(overflow = digits.at(idx) / 10U);
            static_cast<uint8_t>(digits.at(idx) %= 10U);
        }
    }
    sum += overflow;

    for (auto iter = digits.begin(); iter != digits.end(); iter++) {
        static_cast<uint8_t>(sum += *iter);
    }

    std::cout << "Sum = " << sum << '\n';
    return 0;
}
