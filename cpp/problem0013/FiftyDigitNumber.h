#ifndef GUARD_C9D61AFF_3A79_4BA8_B246_0F54589D1B92
#define GUARD_C9D61AFF_3A79_4BA8_B246_0F54589D1B92

#include <array>
#include <cstdint>
#include <iosfwd>
#include <string>

class FiftyDigitNumber {
public:
    FiftyDigitNumber();

    FiftyDigitNumber(uint8_t const& a);

    FiftyDigitNumber(std::string const& other);

    void set(uint8_t const& a);

    FiftyDigitNumber& operator=(std::string const& other);

    FiftyDigitNumber& operator+=(FiftyDigitNumber const& other);

    void printFirstTenDigits();

    friend std::ostream& operator<<(std::ostream& out, FiftyDigitNumber const& a);

private:
    std::array<uint8_t, 51U> _digits;
}; // class FiftyDigitNumber
#endif // GUARD_C9D61AFF_3A79_4BA8_B246_0F54589D1B92
