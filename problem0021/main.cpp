// Problem 0021
//
// Let d(n) be defined as the sum of proper divisors of n (numbers less than which divide evenly
// into n). If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a
// and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore
// d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71, and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 1000.

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

uint32_t divisors(uint32_t const& number) {
    uint32_t sum{1U};
    for (uint32_t i{2U}; i < number; i++) {
        if (number % i == 0U) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    uint16_t              sum{};
    std::vector<uint16_t> vec{};
    for (uint16_t idx{0U}; idx < 10'000; idx++) {
        vec.push_back(idx);
    }

    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        if (*iter == 0U) {
            continue;
        }
        uint16_t b  = divisors(*iter);
        uint16_t db = divisors(b);
        if (*iter == db && *iter != b) {
            (void)std::printf("d(%4u) = %4u, d(%4u) = %4u\n", *iter, b, b, db);
            // std::cout << "d(" << *iter << ") = " << b << ", d(" << b << ") = " << divisors(b) <<
            // '\n';
            sum += (*iter + b);
            vec.at(b) = 0U;
        }
    }

    std::cout << "\nSum = " << sum << '\n';
    return 0;
}
