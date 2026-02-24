#include <iostream>
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

static void printAfter(const std::vector<int> &v) {
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

    PmergeMe pm(argv + 1);

    if (!pm.sortVector() || !pm.sortDeque()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    printBefore(argv + 1);
    printAfter(pm.getVector());

    std::cout << "Time to process a range of "
              << pm.getVector().size()
              << " elements with std::vector : "
              << pm.getVectorTime()
              << " us" << std::endl;

    std::cout << "Time to process a range of "
              << pm.getDeque().size()
              << " elements with std::deque : "
              << pm.getDequeTime()
              << " us" << std::endl;

    return 0;
}