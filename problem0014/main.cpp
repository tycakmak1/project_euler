// Problem 0014
// The following iterative sequence is defined for the set of positive integers:
//
//  n -> n / 2     (n is even)
//  n -> 3 * n _ 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
// 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
// Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers
// finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.

#include <cstdint>
#include <iostream>

uint32_t collatzSequence(uint64_t const& number, uint32_t& length) {
    // std::cout << number << ' ';
    if (number == 1U) {
        // std::cout << "length = " << length << '\n';
        return length;
    }
    if (number % 2U == 0U) {
        length++;
        return collatzSequence(number / 2U, length);
    }
    length += 2U;
    // std::cout << 3 * number + 1 << ' ';
    return collatzSequence((3 * number + 1) / 2U, length);
}

int main() {
    uint32_t length{1U}, maxLength{0U}, maxNumber{0U};
    for (uint32_t i{1'000'000}; i > 2U; i--) {
        collatzSequence(i, length);
        if (length > maxLength) {
            maxNumber = i;
            maxLength = length;
        }
        length = 0U;
    }
    std::cout << "Maximum number = " << maxNumber << ", it's chain length = " << maxLength << '\n';
    return 0;
}
