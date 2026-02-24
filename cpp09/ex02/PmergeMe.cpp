#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe() : av_(NULL), vectorTime_(0), dequeTime_(0) {}

PmergeMe::PmergeMe(char **av) : av_(av), vectorTime_(0), dequeTime_(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : av_(other.av_),
      vec_(other.vec_),
      vectorTime_(other.vectorTime_),
      deq_(other.deq_),
      dequeTime_(other.dequeTime_) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        av_ = other.av_;
        vec_ = other.vec_;
        deq_ = other.deq_;
        vectorTime_ = other.vectorTime_;
        dequeTime_ = other.dequeTime_;
    }
    return *this;
}

const std::vector<int> &PmergeMe::getVector() const { return vec_; }
const std::deque<int> &PmergeMe::getDeque() const { return deq_; }
double PmergeMe::getVectorTime() const { return vectorTime_; }
double PmergeMe::getDequeTime() const { return dequeTime_; }

bool PmergeMe::sortVector() {
    if (av_ == NULL)
        return false;

    try {
        const clock_t start = clock();

        parseInput(vec_);        // data management
        fordJohnsonVector(vec_); // sorting

        const clock_t end = clock();

        vectorTime_ = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    } catch (const std::exception &) {
        return false;
    }

    return true;
}

bool PmergeMe::sortDeque() {
    if (av_ == NULL)
        return false;

    try {
        const clock_t start = clock();

        parseInput(deq_);       // data management
        fordJohnsonDeque(deq_); // sorting

        const clock_t end = clock();

        dequeTime_ = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    } catch (const std::exception &) {
        return false;
    }

    return true;
}

static void binaryInsertVector(std::vector<int> &v, int value) {
    std::vector<int>::iterator left = v.begin();
    std::vector<int>::iterator right = v.end();

    while (left < right) {
        std::vector<int>::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    v.insert(left, value);
}

void PmergeMe::fordJohnsonVector(std::vector<int> &v) {
    if (v.size() <= 1)
        return;

    std::vector< std::pair<int, int> > pairs;
    int rest = -1;
    bool hasRest = false;

    // Pairing
    for (size_t i = 0; i + 1 < v.size(); i += 2) {
        int a = v[i];
        int b = v[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    if (v.size() % 2 != 0) {
        rest = v.back();
        hasRest = true;
    }

    // Main chain (larger elements)
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);

    // Recursive sort
    fordJohnsonVector(mainChain);

    // Insert smaller elements
    for (size_t i = 0; i < pairs.size(); i++)
        binaryInsertVector(mainChain, pairs[i].first);

    // Insert leftover element
    if (hasRest)
        binaryInsertVector(mainChain, rest);

    v = mainChain;
}

static void binaryInsertDeque(std::deque<int> &d, int value) {
    std::deque<int>::iterator left = d.begin();
    std::deque<int>::iterator right = d.end();

    while (left < right) {
        std::deque<int>::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    d.insert(left, value);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &d) {
    if (d.size() <= 1)
        return;

    std::deque< std::pair<int, int> > pairs;
    int rest = -1;
    bool hasRest = false;

    // Pairing
    for (size_t i = 0; i + 1 < d.size(); i += 2) {
        int a = d[i];
        int b = d[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    if (d.size() % 2 != 0) {
        rest = d.back();
        hasRest = true;
    }

    // Main chain (larger elements)
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);

    // Recursive sort
    fordJohnsonDeque(mainChain);

    // Insert smaller elements
    for (size_t i = 0; i < pairs.size(); i++)
        binaryInsertDeque(mainChain, pairs[i].first);

    // Insert leftover element
    if (hasRest)
        binaryInsertDeque(mainChain, rest);

    d = mainChain;
}

PmergeMe::~PmergeMe() {}
