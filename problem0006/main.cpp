// Problem 0006
// The sum of the squares of the first ten natural numbers is,
// 1^2 + 2^2 + ... + 10^2 = 385.
//
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)^2 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers and the
// square of the sum is 3025 - 385 - 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural numbers and
// the square of the sum.

#include <cstdint>
#include <iostream>

int main() {
    uint32_t squareOfSum{}, sumOfSquares{};

    for (uint8_t i = 1U; i <= 100U; i++) {
        sumOfSquares += i * i;
    }
    squareOfSum = 50U * 101U;
    squareOfSum *= squareOfSum;
    std::cout << "Difference = " << squareOfSum - sumOfSquares << '\n';
}
