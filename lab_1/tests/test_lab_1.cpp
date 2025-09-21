#include <gtest/gtest.h>

#include "lab_1.hpp"

TEST(LAB1Test, DigitsOnlyTest) {
    EXPECT_EQ(solve("123"), std::vector<int>({123}));
}

TEST(LAB1Test, LettersOnlyTest) {
    EXPECT_EQ(solve("asdfasdf"), std::vector<int>({}));
}

TEST(LAB1Test, DigitsAndLettersTest) {
    EXPECT_EQ(solve("123abc"), std::vector<int>({123}));
    EXPECT_EQ(solve("123abc321"), std::vector<int>({123, 321}));
    EXPECT_EQ(solve("aa123abc321cc"), std::vector<int>({123, 321}));
}

TEST(LAB1Test, NonASCIICharactersTest) {
    EXPECT_THROW(solve("123яяЁЁч321"), std::runtime_error);
    EXPECT_THROW(solve("57689.687fasdf"), std::runtime_error);
    EXPECT_THROW(solve("asdfš132"), std::runtime_error);
}

TEST(LAB1Test, FunctionDeclarationsTest) {
    EXPECT_NO_THROW(print_usage());
}