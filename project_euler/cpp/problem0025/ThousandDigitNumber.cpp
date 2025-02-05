#include "ThousandDigitNumber.h"

#include <iostream>

ThousandDigitNumber::ThousandDigitNumber() { std::memset(&_digits, 0U, _digits.size()); }

ThousandDigitNumber& ThousandDigitNumber::operator+=(ThousandDigitNumber const& other) {
    uint8_t overflow{};
    for (int16_t idx{999}; idx >= 0; idx--) {
        static_cast<uint8_t>(_digits.at(idx) += overflow + other._digits.at(idx));
        static_cast<uint8_t>(overflow = _digits.at(idx) / 10U);
        static_cast<uint8_t>(_digits.at(idx) = _digits.at(idx) % 10U);
    }
    return *this;
}

ThousandDigitNumber
operator+(ThousandDigitNumber const& leftOperand, ThousandDigitNumber const& rightOperand) {
    return ThousandDigitNumber{leftOperand} += rightOperand;
}

std::ostream& operator<<(std::ostream& out, ThousandDigitNumber const& num) {
    for (uint16_t idx{}; idx < 1000U; idx++) {
        out << static_cast<uint16_t>(num._digits.at(idx));
    }
    return out;
}

void ThousandDigitNumber::set(uint8_t const& num, uint16_t const& idx) { _digits.at(idx) = num; }

bool ThousandDigitNumber::isItThousandDigit() const { return _digits.at(0U) > 0U ? true : false; }

bool ThousandDigitNumber::isItThreeDigit() const { return _digits.at(997U) > 0U ? true : false; }
