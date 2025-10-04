#include "lab_1.hpp"

int main() {
    try {
        run_task();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}