#ifndef GUARD_E38CA656_888C_4B2A_9B52_8E3CEC15A82D
#define GUARD_E38CA656_888C_4B2A_9B52_8E3CEC15A82D

#include <array>
#include <cstdint>
#include <cstring>
#include <iosfwd>

class ThousandDigitNumber {
public:
    ThousandDigitNumber();

    ThousandDigitNumber& operator+=(ThousandDigitNumber const&);

    void set(uint8_t const&, uint16_t const&);

    bool isItThousandDigit() const;

    bool isItThreeDigit() const;

    friend ThousandDigitNumber operator+(ThousandDigitNumber const&, ThousandDigitNumber const&);

    friend std::ostream& operator<<(std::ostream&, ThousandDigitNumber const&);

private:
    std::array<uint8_t, 1000U> _digits;
}; // ThousandDigitNumber

#endif // GUARD_E38CA656_888C_4B2A_9B52_8E3CEC15A82D
