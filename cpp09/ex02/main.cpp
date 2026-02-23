#include <iostream>
#include <cstdlib>
#include "PmergeMe.hpp"

static void printBefore(char **av) {
    std::cout << "Before: ";
    for (int i = 0; av[i]; ++i) {
        std::cout << av[i];
        if (av[i + 1])
            std::cout << " ";
    }
    std::cout << std::endl;
}

void printAfter(const std::vector<int> &v) {
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void printAfter(const std::deque<int> &v) {
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pm(const_cast<const char **>(argv + 1));

    // VECTOR
    if (!pm.sortVector()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // DEQUE
    if (!pm.sortDeque()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // BEFORE
    printBefore(argv + 1);

    // AFTER (vector is sorted)
    printAfter(pm.getDeque());

    // TIMES
    std::cout << "Time to process a range of "
              << pm.getVector().size()
              << " elements with std::vector : "
              << pm.getVectorTime()
              << " us"
              << std::endl;

    std::cout << "Time to process a range of "
              << pm.getDeque().size()
              << " elements with std::deque : "
              << pm.getDequeTime()
              << " us"
              << std::endl;

    return 0;
}
