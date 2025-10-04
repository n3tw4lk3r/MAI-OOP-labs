#include "lab_2.hpp"

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <string>

Hex::Hex() :
    size(1),
    data(new unsigned char[1])
{
    data[0] = 0;
}

Hex::Hex(const std::string& hexString) :
    size(hexString.size()),
    data(new unsigned char[size])
{
    if (hexString.empty()) {
        delete[] data;
        throw std::invalid_argument("Empty hexadecimal string.");
    }
    for (std::size_t i = 0; i < size; ++i) {
        if (!std::isalnum(hexString[size - 1 - i])) {
            delete[] data;
            throw std::invalid_argument("Invalid hexadecimal string.");
        }
        data[i] = convertChar(hexString[size - 1 - i]);
    }
}

Hex::Hex(const unsigned char* hexCString) :
    size(std::strlen(reinterpret_cast<const char*>(hexCString))),
    data(new unsigned char[size])
{
    if (size == 0) {
        throw std::invalid_argument("Empty hexadecimal c-string.");
    }
    for (std::size_t i = 0; i < size; ++i) {
        if (!std::isalnum(hexCString[size - 1 - i])) {
            delete[] data;
            throw std::invalid_argument("Invalid hexadecimal string.");
        }
        data[i] = convertChar(reinterpret_cast<const char*>(hexCString)[size - 1 - i]);
    }
}

Hex::Hex(const Hex& other) :
    size(other.size),
    data(new unsigned char[size])
{
    std::copy(other.data, other.data + size, data);
}

Hex::Hex(Hex&& other) noexcept :
    size(other.size),
    data(other.data)
{
    other.data = nullptr;
    other.size = 0;
}

Hex::~Hex() noexcept
{
    delete[] data;
}

Hex::Hex(std::size_t n, unsigned char* arr) :
    size(n),
    data(arr)
{}

Hex Hex::add(const Hex& other) const {
    std::size_t n = std::max(size, other.size);
    unsigned char* res = new unsigned char[n + 1];
    unsigned carry = 0;

    for (std::size_t i = 0; i < n; ++i) {
        unsigned a = (i < size ? data[i] : 0);
        unsigned b = (i < other.size ? other.data[i] : 0);
        unsigned sum = a + b + carry;
        res[i] = sum % 16;
        carry = sum / 16;
    }

    if (carry > 0) {
        res[n] = carry;
        return Hex(n + 1, res);
    } else {
        return Hex(n, res);
    }
}

Hex Hex::substract(const Hex& other) const {
    if (isLess(other)) {
        throw std::invalid_argument("Hex number can't be negative.");
    }

    std::size_t n = size;
    unsigned char* res = new unsigned char[n];
    int borrow = 0;

    for (std::size_t i = 0; i < n; ++i) {
        int a = data[i];
        int b = (i < other.size ? other.data[i] : 0);
        int diff = a - b - borrow;
        if (diff < 0) {
            diff += 16;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res[i] = static_cast<unsigned char>(diff);
    }

    while (n > 1 && res[n - 1] == 0) --n;
    return Hex(n, res);
}

Hex Hex::copy() const {
    return Hex(*this);
}

bool Hex::isLess(const Hex& other) const {
    if (size < other.size) {
        return true;
    } else if (size > other.size) {
        return false;
    }
    for (std::size_t i = size - 1; i >= 0; --i) {
        if (data[i] < other.data[i]) {
            return true;
        } else if (data[i] > other.data[i]) {
            return false;
        }
    }
    return false;
}

bool Hex::isEqual(const Hex& other) const {
    if (size != other.size) {
        return false;
    }
    for (std::size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Hex::isGreater(const Hex& other) const {
    if (size > other.size) {
        return true;
    } else if (size < other.size) {
        return false;
    }
    for (std::size_t i = size - 1; i >= 0; --i) {
        if (data[i] > other.data[i]) {
            return true;
        } else if (data[i] < other.data[i]) {
            return false;
        }
    }
    return false;
}

std::size_t Hex::getSize() const {
    return size;
}

unsigned char Hex::getCharByIndex(const std::size_t index) {
    if (index >= size) {
        throw std::invalid_argument("Invalid index.");
    }
    return data[size - 1 - index];
}
unsigned char Hex::convertChar(char c) {
    const std::size_t HEX_A_INDEX = 10;
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + HEX_A_INDEX;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + HEX_A_INDEX;
    }
    throw std::invalid_argument("Invalid hex character.");
}