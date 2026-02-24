#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T> T fromString(const std::string &str) {
    std::istringstream ss(str);
    T value;

    ss >> value;

    if (ss.fail())
        throw std::invalid_argument("invalid input");
    char c;
    if (ss >> c)
        throw std::invalid_argument("invalid input");

    return value;
}

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(char **av);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    
    const std::vector<int> &getVector() const;
    const std::deque<int> &getDeque() const;
    double getVectorTime() const;
    double getDequeTime() const;
    
    bool sortVector();
    bool sortDeque();
    
    ~PmergeMe();

private:
    char **av_;
    std::vector<int> vec_;
    double vectorTime_;
    std::deque<int> deq_;
    double dequeTime_;

    template <typename Container> void parseInput(Container &c) {
        c.clear();
        for (size_t i = 0; av_[i]; i++) {
            int val = fromString<int>(av_[i]);
            if (val <= 0)
                throw std::invalid_argument("invalid input");
            c.push_back(val);
        }
    }

    void fordJohnsonVector(std::vector<int> &);
    void fordJohnsonDeque(std::deque<int> &);
};

#endif