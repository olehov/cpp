#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }

    RPN rpn(argv[1]);

    if (!rpn.run()) {
        return 1;
    }

    std::cout << rpn << std::endl;

    return 0;
}