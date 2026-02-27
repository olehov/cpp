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

static std::vector<size_t> buildInsertionOrder(size_t n)
{
    std::vector<size_t> order;
    if (n == 0)
        return order;

    std::vector<size_t> jacob;
    jacob.push_back(1);

    size_t j1 = 1;
    size_t j2 = 0;

    while (true) {
        size_t next = j1 + 2 * j2;
        if (next > n)
            break;
        jacob.push_back(next);
        j2 = j1;
        j1 = next;
    }

    size_t prev = 0;
    for (size_t k = 0; k < jacob.size(); ++k) {
        size_t curr = jacob[k];
        for (size_t i = curr; i > prev; --i)
            order.push_back(i - 1);
        prev = curr;
    }

    for (size_t i = n; i > prev; --i)
        order.push_back(i - 1);

    return order;
}

static void binaryInsertVector(
    std::vector<int> &v,
    int value,
    std::vector<int>::iterator endIt)
{
    std::vector<int>::iterator left = v.begin();
    std::vector<int>::iterator right = endIt;

    while (left < right)
    {
        std::vector<int>::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    v.insert(left, value);
}

static void jacobsthalInsertVector(
    std::vector<int> &mainChain,
    const std::vector< std::pair<int,int> > &pairs,
    int rest,
    bool hasRest)
{
    std::vector<size_t> order = buildInsertionOrder(pairs.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];

        int a = pairs[idx].first;
        int b = pairs[idx].second;

        std::vector<int>::iterator posB =
            std::lower_bound(mainChain.begin(), mainChain.end(), b);

        binaryInsertVector(mainChain, a, posB);
    }

    if (hasRest)
        binaryInsertVector(mainChain, rest, mainChain.end());
}

void PmergeMe::fordJohnsonVector(std::vector<int> &v) {
    if (v.size() <= 1)
        return;

    std::vector< std::pair<int, int> > pairs;
    int rest = 0;
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

    jacobsthalInsertVector(mainChain, pairs, rest, hasRest);

    v = mainChain;
}
static void binaryInsertDeque(
    std::deque<int> &v,
    int value,
    std::deque<int>::iterator endIt)
{
    std::deque<int>::iterator left = v.begin();
    std::deque<int>::iterator right = endIt;

    while (left < right)
    {
        std::deque<int>::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    v.insert(left, value);
}

static void jacobsthalInsertDeque(
    std::deque<int> &mainChain,
    const std::deque< std::pair<int,int> > &pairs,
    int rest,
    bool hasRest)
{
    std::vector<size_t> order = buildInsertionOrder(pairs.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];

        int a = pairs[idx].first;
        int b = pairs[idx].second;

        std::deque<int>::iterator posB =
            std::lower_bound(mainChain.begin(), mainChain.end(), b);

        binaryInsertDeque(mainChain, a, posB);
    }

    if (hasRest)
        binaryInsertDeque(mainChain, rest, mainChain.end());
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &d) {
    if (d.size() <= 1)
        return;

    std::deque< std::pair<int, int> > pairs;
    int rest = 0;
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

    jacobsthalInsertDeque(mainChain, pairs, rest, hasRest);

    d = mainChain;
}

PmergeMe::~PmergeMe() {}
