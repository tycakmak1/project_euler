#include "FiftyDigitNumber.h"

#include <cstring>
#include <iostream>

FiftyDigitNumber::FiftyDigitNumber() { std::memset(&_digits.at(0U), 0U, 51U); }

FiftyDigitNumber::FiftyDigitNumber(uint8_t const& a) {
    _digits.at(0U) = 0U;
    std::memset(&_digits.at(1U), a, 50U);
}

FiftyDigitNumber::FiftyDigitNumber(std::string const& other) {
    _digits.at(0U) = 0U;
    for (uint8_t idx{}; idx < 50U; idx++) {
        _digits.at(idx + 1U) = other.at(idx) - '0';
    }
}

void FiftyDigitNumber::set(uint8_t const& a) {
    _digits.at(0U) = 0U;
    std::memset(&_digits.at(1U), a, 51U);
}

FiftyDigitNumber& FiftyDigitNumber::operator=(std::string const& other) {
    _digits.at(0U) = 0U;
    for (uint8_t idx{}; idx < 50U; idx++) {
        _digits.at(idx + 1U) = other.at(idx) - '0';
    }
    return *this;
}

FiftyDigitNumber& FiftyDigitNumber::operator+=(FiftyDigitNumber const& other) {
    for (uint8_t idx{50U}; idx > 0U; idx--) {
        static_cast<uint8_t>(_digits.at(idx) += other._digits.at(idx));
        static_cast<uint8_t>(_digits.at(idx - 1U) += _digits.at(idx) / 10U);
        static_cast<uint8_t>(_digits.at(idx) %= 10U);
    }
    return *this;
}

void FiftyDigitNumber::printFirstTenDigits() {
    for (uint8_t idx{}; idx < 11U; idx++) {
        std::cout << static_cast<uint16_t>(_digits.at(idx)) << ' ';
    }
    std::cout << '\n';
}

std::ostream& operator<<(std::ostream& out, FiftyDigitNumber const& a) {
    for (uint8_t idx{}; idx < 51U; idx++) {
        out << static_cast<uint16_t>(a._digits.at(idx)) << ' ';
    }
    return out;
}

FiftyDigitNumber operator+(FiftyDigitNumber const& lhs, FiftyDigitNumber const& rhs) {
    return FiftyDigitNumber{lhs} += rhs;
}
