#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <sstream>
#include <string>

template <typename T> T fromString(const std::string &str) {
    std::istringstream ss(str);
    T value;

    ss >> value;

    if (ss.fail())
        throw std::invalid_argument("Error: invalid input");
    char c;
    if (ss >> c)
        throw std::invalid_argument("Error: invalid input");

    return value;
}

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInput(const std::string &filename);

private:
    std::map<std::string, double> _rates;

    bool isValidDate(const std::string &date) const;
    double getRateForDate(const std::string &date) const;

    void parseLine(const std::string &line, const std::string &delimiter, std::string &date,
                   double &value, bool isDatabase) const;
};

#endif