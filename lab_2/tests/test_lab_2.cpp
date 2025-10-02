#include <gtest/gtest.h>
#include "lab_2.hpp"

TEST(LAB2Test, TestConstructors) {
    {
        // Default constructor
        Hex hex1;
        ASSERT_EQ(hex1.getSize(), 1);
        Hex hex2("0");
        ASSERT_TRUE(hex1.isEqual(hex2));
        ASSERT_TRUE(hex2.isEqual(hex1));
    }
    {
        // String constructor
        const size_t HEX_A_INDEX = 10;
        Hex hex1("1A3F");
        ASSERT_EQ(hex1.getSize(), 4);
        ASSERT_EQ(hex1.getCharByIndex(0), '1' - '0');
        ASSERT_EQ(hex1.getCharByIndex(1), 'A' - 'A' + HEX_A_INDEX);
        ASSERT_EQ(hex1.getCharByIndex(2), '3' - '0');
        ASSERT_EQ(hex1.getCharByIndex(3), 'F' - 'A' + HEX_A_INDEX);
    }
    {
        // Copy constructor
        Hex hex1("ABCD");
        Hex hex2(hex1);
        ASSERT_TRUE(hex1.isEqual(hex2));
    }
    {
        // Move constructor
        const size_t HEX_A_INDEX = 10;
        Hex hex1("FF");
        Hex hex2(std::move(hex1));
        ASSERT_EQ(hex2.getSize(), 2);
        ASSERT_EQ(hex2.getCharByIndex(0), 'F' - 'A' + HEX_A_INDEX);
        ASSERT_EQ(hex2.getCharByIndex(1), 'F' - 'A' + HEX_A_INDEX);
    }
    {
        // Invalid string (non-hex symbols)
        ASSERT_THROW(Hex("XYZ"), std::invalid_argument);
        ASSERT_THROW(Hex("12G5"), std::invalid_argument);
        ASSERT_THROW(Hex("-F"), std::invalid_argument);
    }
}

TEST(LAB2Test, TestAdd) {
    Hex hex1("A");    // 10
    Hex hex2("5");    // 5
    Hex sum = hex1.add(hex2); // 15 = "F"
    Hex expected("F");
    EXPECT_TRUE(sum.isEqual(expected));

    Hex hex3("FF");   // 255
    Hex hex4("1");    // 1
    Hex sum2 = hex3.add(hex4); // 256 = "100"
    Hex expected2("100");
    EXPECT_TRUE(sum2.isEqual(expected2));
}

TEST(LAB2Test, TestSubstract) {
    Hex hex1("10");   // 16
    Hex hex2("1");    // 1
    Hex diff = hex1.substract(hex2); // 15 = "F"
    Hex expected("F");
    EXPECT_TRUE(diff.isEqual(expected));

    // Вычитание до нуля
    Hex hex3("A");   // 10
    Hex hex4("A");   // 10
    Hex diff2 = hex3.substract(hex4); // 0
    Hex expected2("0");
    EXPECT_TRUE(diff2.isEqual(expected2));

    // Ошибка при отрицательном результате
    Hex hex5("1");   // 1
    Hex hex6("A");   // 10
    EXPECT_THROW(hex5.substract(hex6), std::invalid_argument);
}

TEST(LAB2Test, TestCopy) {
    Hex hex1("1234");
    Hex hex2(hex1);
    EXPECT_TRUE(hex1.isEqual(hex2));
    EXPECT_TRUE(hex2.isEqual(hex1));

    EXPECT_THROW(hex1.getCharByIndex(10), std::invalid_argument);
}

TEST(LAB2Test, TestComparison) {
    Hex hex1("A");
    Hex hex2("B");
    Hex hex3("A");

    EXPECT_TRUE(hex1.isLess(hex2));
    EXPECT_TRUE(hex2.isGreater(hex1));
    EXPECT_TRUE(hex1.isEqual(hex3));
    EXPECT_FALSE(hex1.isGreater(hex2));
    EXPECT_FALSE(hex2.isLess(hex1));
}
