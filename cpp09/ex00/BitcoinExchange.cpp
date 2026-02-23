#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;

    // skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::string date;
        double value;

        try {
            parseLine(line, ",", date, value, true);
        } catch (const std::exception &e) {
            throw std::runtime_error(e.what());
        }

        _rates[date] = value;
    }
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    // skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::string date;
        double value;

        try {
            parseLine(line, " | ", date, value, false);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            double rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << rate * value << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 10)
        return false;

    int year, month, day;
    char dash1, dash2;

    std::istringstream ss(date);

    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;

    if (dash1 != '-' || dash2 != '-')
        return false;

    ss >> std::ws;
    if (!ss.eof())
        return false;

    if (month < 1 || month > 12)
        return false;

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int maxDays;

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxDays = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        maxDays = 30;
        break;

    case 2:
        maxDays = isLeap ? 29 : 28;
        break;

    default:
        return false;
    }

    if (day < 1 || day > maxDays)
        return false;

    return true;
}

double BitcoinExchange::getRateForDate(const std::string &date) const {
    if (_rates.empty()) {
        throw std::runtime_error("Error: database is empty.");
    }

    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

    if (it == _rates.end()) {
        --it;
        return it->second;
    }

    if (it->first == date)
        return it->second;

    if (it == _rates.begin())
        throw std::runtime_error("Error: no earlier date available.");

    --it;
    return it->second;
}

void BitcoinExchange::parseLine(const std::string &line, const std::string &delimiter,
                                std::string &date, double &value, bool isDatabase) const {
    size_t pos = line.find(delimiter);

    if (pos == std::string::npos || pos == 0 || pos + delimiter.length() >= line.length()) {
        throw std::runtime_error(isDatabase ? "Error: bad database file."
                                            : "Error: bad input => " + line);
    }

    date = line.substr(0, pos);
    std::string valueStr = line.substr(pos + delimiter.length());

    if (!isValidDate(date)) {
        throw std::runtime_error(isDatabase ? "Error: invalid date in database."
                                            : "Error: bad input => " + line);
    }

    try {
        value = fromString<double>(valueStr);
    } catch (const std::exception &) {
        throw std::runtime_error(isDatabase ? "Error: invalid exchange rate in database."
                                            : "Error: bad input => " + line);
    }

    if (isDatabase) {
        if (value < 0)
            throw std::runtime_error("Error: invalid exchange rate in database.");
    }
}

BitcoinExchange::~BitcoinExchange() {}
