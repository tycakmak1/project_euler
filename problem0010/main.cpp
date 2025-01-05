// Problem 0010
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.

#include <cstdint>
#include <iostream>

bool isPrime(uint64_t const& num) {
    for(uint64_t i = 2U; i * i <= num; i++) {
        if(num % i == 0U) {
            return false;
        }
    }
    return true;
}

int main() {
    uint64_t sum{2U};
    for(uint64_t i = 3U; i < 2'000'000U; i++) {
        if(isPrime(i)) {
            sum += i;
        }
    }
    std::cout << sum << '\n';
    return 0;
}
