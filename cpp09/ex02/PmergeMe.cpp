#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

/*
 * Constructors / Canonical form
 */

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

/*
 * Getters
 */

const std::vector<int> &PmergeMe::getVector() const { return vec_; }
const std::deque<int> &PmergeMe::getDeque() const { return deq_; }
double PmergeMe::getVectorTime() const { return vectorTime_; }
double PmergeMe::getDequeTime() const { return dequeTime_; }

/*
 * sortVector / sortDeque
 * Measures total time of:
 *   - parsing input
 *   - Ford-Johnson sorting
 */

bool PmergeMe::sortVector() {
    if (av_ == NULL) {
        return false;
    }

    try {
        const clock_t start = clock();

        parseInput(vec_);        // Data validation + conversion
        fordJohnsonVector(vec_); // Ford-Johnson sorting (vector)

        const clock_t end = clock();

        // Total processing time in microseconds
        vectorTime_ = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    } catch (const std::exception &) {
        return false;
    }

    return true;
}

bool PmergeMe::sortDeque() {
    if (av_ == NULL) {
        return false;
    }

    try {
        const clock_t start = clock();

        parseInput(deq_);       // Data validation + conversion
        fordJohnsonDeque(deq_); // Ford-Johnson sorting (deque)

        const clock_t end = clock();

        // Total processing time in microseconds
        dequeTime_ = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    } catch (const std::exception &) {
        return false;
    }

    return true;
}

/*
 * Builds Jacobsthal-based insertion order.
 * This order minimizes comparisons during insertion phase.
 *
 * Jacobsthal recurrence:
 *   J(n) = J(n-1) + 2 * J(n-2)
 *
 * The sequence defines optimal insertion blocks
 * in the Ford-Johnson algorithm.
 */

static std::vector<size_t> buildInsertionOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) {
        return order;
    }

    std::vector<size_t> jacob;
    jacob.push_back(1);

    size_t j1 = 1;
    size_t j2 = 0;

    // Generate Jacobsthal numbers up to n
    while (true) {
        size_t next = j1 + 2 * j2;
        if (next > n) {
            break;
        }
        jacob.push_back(next);
        j2 = j1;
        j1 = next;
    }

    // Convert Jacobsthal values into insertion indices
    size_t prev = 0;
    for (size_t k = 0; k < jacob.size(); ++k) {
        size_t curr = jacob[k];
        for (size_t i = curr; i > prev; --i) {
            order.push_back(i - 1);
        }
        prev = curr;
    }

    // Insert any remaining indices
    for (size_t i = n; i > prev; --i) {
        order.push_back(i - 1);
    }

    return order;
}

/*
 * Binary insertion inside restricted range [begin, endIt).
 * The search range is limited to reduce comparisons.
 */

static void binaryInsertVector(std::vector<int> &v, int value, std::vector<int>::iterator endIt) {
    std::vector<int>::iterator left = v.begin();
    std::vector<int>::iterator right = endIt;

    while (left < right) {
        std::vector<int>::iterator mid = left + (right - left) / 2;
        if (*mid < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    v.insert(left, value);
}

/*
 * Inserts all smaller elements (a_i) into sorted main chain (b_i).
 *
 * Each a_i satisfies:
 *     a_i ≤ b_i
 *
 * Therefore insertion only needs to search in the prefix
 * ending at b_i, reducing the number of comparisons.
 */

static void jacobsthalInsertVector(std::vector<int> &mainChain,
                                   const std::vector<std::pair<int, int> > &pairs, int rest,
                                   bool hasRest) {
    std::vector<size_t> order = buildInsertionOrder(pairs.size());

    for (size_t i = 0; i < order.size(); ++i) {
        size_t idx = order[i];

        int a = pairs[idx].first;
        int b = pairs[idx].second;

        // Locate paired b_i inside sorted main chain
        std::vector<int>::iterator posB = std::lower_bound(mainChain.begin(), mainChain.end(), b);

        binaryInsertVector(mainChain, a, posB);
    }

    // Insert leftover element if original size was odd
    if (hasRest) {
        binaryInsertVector(mainChain, rest, mainChain.end());
    }
}

/*
 * Ford-Johnson (Merge-Insert) algorithm for std::vector.
 *
 * Algorithm structure:
 * 1. Pair adjacent elements (a_i ≤ b_i)
 * 2. Recursively sort larger elements (b_i)
 * 3. Insert smaller elements (a_i) using Jacobsthal order
 *
 * This reduces the number of comparisons compared to
 * classical merge sort in worst-case comparison count.
 */

void PmergeMe::fordJohnsonVector(std::vector<int> &v) {
    if (v.size() <= 1) {
        return;
    }

    std::vector<std::pair<int, int> > pairs;
    int rest = 0;
    bool hasRest = false;

    // Step 1: Pair adjacent elements and order internally
    for (size_t i = 0; i + 1 < v.size(); i += 2) {
        int a = v[i];
        int b = v[i + 1];
        if (a < b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }

    if (v.size() % 2 != 0) {
        rest = v.back();
        hasRest = true;
    }

    // Step 2: Build main chain from larger elements (b_i)
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].second);
    }

    // Recursively sort main chain
    fordJohnsonVector(mainChain);

    // Step 3: Insert smaller elements using Jacobsthal sequence
    jacobsthalInsertVector(mainChain, pairs, rest, hasRest);

    v = mainChain;
}

/*
 * Binary insertion for deque version
 */

static void binaryInsertDeque(std::deque<int> &v, int value, std::deque<int>::iterator endIt) {
    std::deque<int>::iterator left = v.begin();
    std::deque<int>::iterator right = endIt;

    while (left < right) {
        std::deque<int>::iterator mid = left + (right - left) / 2;
        if (*mid < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    v.insert(left, value);
}

/*
 * Jacobsthal insertion phase for deque container.
 * Separate implementation required by subject.
 */

static void jacobsthalInsertDeque(std::deque<int> &mainChain,
                                  const std::deque<std::pair<int, int> > &pairs, int rest,
                                  bool hasRest) {
    std::vector<size_t> order = buildInsertionOrder(pairs.size());

    for (size_t i = 0; i < order.size(); ++i) {
        size_t idx = order[i];

        int a = pairs[idx].first;
        int b = pairs[idx].second;

        // Locate paired b_i inside sorted main chain
        std::deque<int>::iterator posB = std::lower_bound(mainChain.begin(), mainChain.end(), b);

        binaryInsertDeque(mainChain, a, posB);
    }

    // Insert leftover element if original size was odd
    if (hasRest) {
        binaryInsertDeque(mainChain, rest, mainChain.end());
    }
}

/*
 * Ford-Johnson (Merge-Insert) algorithm for std::deque.
 *
 * Algorithm structure:
 * 1. Pair adjacent elements (a_i ≤ b_i)
 * 2. Recursively sort larger elements (b_i)
 * 3. Insert smaller elements (a_i) using Jacobsthal order
 *
 * This reduces the number of comparisons compared to
 * classical merge sort in worst-case comparison count.
 */
void PmergeMe::fordJohnsonDeque(std::deque<int> &d) {
    if (d.size() <= 1) {
        return;
    }

    std::deque<std::pair<int, int> > pairs;
    int rest = 0;
    bool hasRest = false;

    // Step 1: Pair adjacent elements and order internally
    for (size_t i = 0; i + 1 < d.size(); i += 2) {
        int a = d[i];
        int b = d[i + 1];
        if (a < b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }

    if (d.size() % 2 != 0) {
        rest = d.back();
        hasRest = true;
    }

    // Step 2: Build main chain from larger elements (b_i)
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].second);
    }

    // Recursively sort main chain
    fordJohnsonDeque(mainChain);

    // Step 3: Insert smaller elements using Jacobsthal sequence
    jacobsthalInsertDeque(mainChain, pairs, rest, hasRest);

    d = mainChain;
}

PmergeMe::~PmergeMe() {}