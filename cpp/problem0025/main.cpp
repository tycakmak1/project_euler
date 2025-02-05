// Problem 0025
//
// The Fibonacci sequence is defined by the recurrence relation:
// Fn = F(n-1) + F(n-2), where F1 = 1 and F2 = 1.
// Hence the first 12 terms will be: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144.
// The 12th term, F12, is the first, is the first term to contain three digits.

// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

#include "ThousandDigitNumber.h"

#include <iostream>

int main() {
    ThousandDigitNumber fib1{}, fib2{}, swap{};
    fib1.set(1U, 999U);
    fib2.set(1U, 999U);
    uint16_t index{2U};

    while (!fib2.isItThousandDigit()) {
        swap = fib1;
        fib1 = fib2;
        fib2 += swap;
        index++;
    }

    std::cout << "Index = " << index << '\n';
}
