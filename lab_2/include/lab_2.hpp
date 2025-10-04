#pragma once

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <string>

class Hex {
public:
    Hex();
    Hex(const std::string& hexString);
    Hex(const unsigned char* hexCString);
    Hex(size_t n, unsigned char defaultValue = 0);
    Hex(const Hex& other);
    Hex(Hex&& other) noexcept;
    virtual ~Hex() noexcept;

    Hex add(const Hex& other) const;
    Hex substract(const Hex& other) const;
    Hex copy() const;

    bool isLess(const Hex& other) const;
    bool isEqual(const Hex& other) const;
    bool isGreater(const Hex& other) const;

    std::size_t getSize() const;
    unsigned char getCharByIndex(const std::size_t index);

private:
    Hex(std::size_t n, unsigned char* arr);

    std::size_t size;
    unsigned char* data; // data[0] - least significant digit

    static unsigned char convertChar(char ch);
};
