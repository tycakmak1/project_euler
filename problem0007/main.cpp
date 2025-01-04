// Problem 0007
// By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13.
// 
// What is the 10'001st prime number?

#include <cstdint>
#include <cmath>
#include <iostream>

bool isPrime(uint32_t const& number){
    if(number % 2U == 0U){
        return false;
    }
    for(uint32_t i = 3U; i <= sqrt(number); i++){
        if(number % i == 0U){
            return false;
        }
    }
    return true;
}

int main(){
    uint16_t numberOfPrimes{1U};
    uint32_t i{3U}, maxPrime{};
    while(numberOfPrimes < 10'001){
        if(isPrime(i)){
            numberOfPrimes++;
            maxPrime = i;
        }
        i++;
    }
    std::cout << maxPrime << '\n';
    return 0;
}
