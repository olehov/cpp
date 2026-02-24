#include "RPN.hpp"
#include <iostream>

template <typename T> static T getElement(std::stack<T> &stack) {
    T el = stack.top();
    stack.pop();
    return el;
}

static int charToNumber(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return -1; // Invalid character
    }
}

static bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*') {
        return true;
    }
    return false;
}

static int calculate(int a, int b, char operation) {
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '/':
        if (b == 0) {
            throw std::runtime_error("division by zero");
        }
        return a / b;
    case '*':
        return a * b;
    default:
        break;
    }
    return 0;
}

static std::string getWord(const std::string &s, size_t &pos) {
    if (s.empty()) {
        return std::string();
    }

    std::string res = "";

    while (pos < s.size() && isspace(static_cast<unsigned char>(s[pos]))) {
        pos++;
    }

    for (; pos < s.size(); pos++) {
        if (isspace(static_cast<unsigned char>(s[pos]))) {
            return res;
        }
        res.push_back(s[pos]);
    }
    return res;
}

RPN::RPN() {}

RPN::RPN(const std::string &input) : input_(input) {}

RPN::RPN(const RPN &other) : input_(other.input_), stack_(other.stack_) {}

RPN &RPN::operator=(const RPN &other) {
    if (this == &other) {
        return *this;
    }
    input_ = other.input_;
    stack_ = other.stack_;
    return *this;
}

bool RPN::run() {
    while (!stack_.empty()) {
        stack_.pop();
    }

    for (size_t i = 0; i < input_.size();) {
        std::string tmp = getWord(input_, i);
        if (tmp.size() > 1) {
            std::cerr << "Error: invalid token: " << tmp << std::endl;
            return false;
        }
        if (tmp.empty()) {
            continue;
        } else if (isdigit(static_cast<unsigned char>(tmp[0]))) {
            int num = charToNumber(tmp[0]);
            stack_.push(num);
        } else if (isOperator(tmp[0])) {
            if (stack_.size() <= 1) {
                std::cerr << "Error: insufficient operands" << std::endl;
                return false;
            }
            int b = getElement(stack_);
            int a = getElement(stack_);
            try {
                int res = calculate(a, b, tmp[0]);
                stack_.push(res);
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return false;
            }
        } else {
            std::cerr << "Error: invalid token: " << tmp << std::endl;
            return false;
        }
    }

    if (stack_.size() != 1) {
        std::cerr << "Error: invalid expression" << std::endl;
        return false;
    }
    return true;
}

int RPN::getResult() const
{
    if (stack_.empty()) {
        return 0;
    }
    return stack_.top();
}

RPN::~RPN() {}

std::ostream &operator<<(std::ostream &os, const RPN &rpn)
{
    os << rpn.getResult();
    return os;
}
