#include "Parser.h"

std::string Parser::Parse(const std::string &block) {
    size_t end_block = 0;
    size_t start_block = 0;
    size_t start_field = 0;
    size_t end_field = 0;

    std::string result;
    Table t;

    while (ParseBlock(block, "<param_text>", "</param_text>", start_block, end_block)) {
        t.name_ = ParseField(block, "<name>", "</name>", start_field, end_field, end_block);
        t.date_ = ParseField(block, "<date>", "</date>", start_field, end_field, end_block);
        t.hours_worked_ = ParseField(block, "<hours-worked>", "</hours-worked>", start_field, end_field, end_block);
        t.car_ = ParseField(block, "<car-true>", "</car-true>", start_field, end_field, end_block);
        result += t.StringTable();

        start_block = end_block;
        start_field = start_block;
    }
    return result;
}

std::string Parser::ParseField(const std::string& input_str, const std::string& find_start, const std::string& find_end,
        size_t start, size_t &end, size_t end_block) {
    std::string::size_type start_n = input_str.find(find_start, start);
    if (start_n == std::string::npos || start_n > end_block) {
        return {};
    }

    start = start_n + find_start.length();
    std::string::size_type end_n = input_str.find(find_end, start);
    if (end_n == std::string::npos || end_n > end_block) {
        return {};
    }

    end = end_n + find_end.length();
    return {input_str.begin() + start, input_str.begin() + end_n};
}

bool Parser::ParseBlock(const std::string& str, const std::string& find_str, const std::string& find_end,
        size_t& start, size_t& end) {
    std::string::size_type start_n = str.find(find_str, start);
    if (start_n == std::string::npos) {
        return false;
    }

    start = start_n + find_str.length();
    std::string::size_type end_n = str.find(find_end, start);
    if (end_n == std::string::npos) {
        return false;
    }

    end = end_n + find_end.length();
    return true;
}
