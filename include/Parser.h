#ifndef TESTTASK_PARSER_H
#define TESTTASK_PARSER_H
#include <string>
#include <iostream>

struct Table {
    std::string name_;
    std::string date_;
    std::string hours_worked_;
    std::string car_;
    std::string StringTable() {
        std::string res;
        res.reserve(name_.length() + date_.length() + hours_worked_.length() + car_.length() + 5);
        std::cout << name_ << std::endl << date_ << std::endl << hours_worked_ << std::endl << car_ << std::endl << std::endl;
        return res;
    }
};

class Parser {
public:
    Parser() = default;
    ~Parser() = default;
    std::string Parse(const std::string& block);
    std::string ParseField(const std::string& str, const std::string& find_str,  const std::string& find_end,
            size_t start, size_t& end, size_t end_block);
    bool ParseBlock(const std::string& str, const std::string& find_str,  const std::string& find_end,
                           size_t& start, size_t& end);
};


#endif //TESTTASK_PARSER_H
