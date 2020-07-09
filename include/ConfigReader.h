#ifndef TESTTASK_CONFIGREADER_H
#define TESTTASK_CONFIGREADER_H
#include <string>

struct Paths {
    std::string input_path_;
    std::string delete_path_;
};

class ConfigReader {
public:
    ConfigReader() = default;
    ~ConfigReader() = default;

    Paths ReadPaths(const std::string& config_path);
};


#endif //TESTTASK_CONFIGREADER_H
