// Problem 0004
// A palindromic number reads the same both ways. The largest palindrome made from the product of
// two 2-digit numbers is 9009 = 91 x 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <cmath>
#include <cstdint>
#include <iostream>

bool isPalindrome(uint32_t const& number) {
    uint32_t reverse{};
    for (uint8_t i = 1; number > pow(10, i - 1U); i++) {
        reverse = reverse * 10
                  + ((number % static_cast<uint32_t>(pow(10, i)))
                     / static_cast<uint32_t>(pow(10, i - 1U)));
    }
    return reverse == number;
}

int main() {
    uint32_t max_palindrome{}, num{};
    for (int16_t factor1 = 999U; factor1 > 99U; factor1--) {
        for (int16_t factor2 = 999U; factor2 > 99U; factor2--) {
            num = factor1 * factor2;
            if (isPalindrome(num) && (num > max_palindrome)) {
                max_palindrome = num;
            }
        }
    }
    std::cout << "max_palindrome = " << max_palindrome << '\n';

    return 0;
}
