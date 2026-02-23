#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
public:
    RPN();
    RPN(const std::string &input);
    RPN(const RPN &other);

    RPN &operator=(const RPN &other);

    bool run();

    int getResult() const;

    ~RPN();

private:
    std::string input_;
    std::stack<int> stack_;
};

std::ostream& operator<<(std::ostream& os, const RPN& rpn);

#endif