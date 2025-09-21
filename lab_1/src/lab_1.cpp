#include "lab_1.hpp"

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

void print_usage() {
    std::cout << "Please enter a string containing ONLY digits and ASCII letters."
              << std::endl;
}

std::vector<int> solve(const std::string& data) {
    std::vector<int> result;
    
    std::string buffer;
    for (const char& character : data) {
        if (!isalnum(character)) {
            print_usage();
            throw std::runtime_error("Forbidden character.");
        }

        if (std::isdigit(character)) {
            buffer += character;
        } else if (std::isalpha(character)) {
            if (buffer.empty()) {
                continue;
            }
            int number = std::stoi(buffer);
            result.push_back(number);
            buffer.clear();
        }
    }

    if (!buffer.empty()) {
        int number = std::stoi(buffer);
        result.push_back(number);
        buffer.clear();
    }

    return result;
}

std::string get_input() {
    std::string input;
    std::cin >> input;
    return input;
}

void run_task() {
    std::string string = get_input();
    std::vector<int> numbers = solve(string);

    for (const int& number : numbers) {
        std::cout << number << std::endl;
    }
}
