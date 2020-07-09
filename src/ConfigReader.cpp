#include "ConfigReader.h"
#include <fstream>

Paths ConfigReader::ReadPaths(const std::string& config_path) {
    Paths paths;
    std::ifstream ifs(config_path);
    if (!ifs.is_open()) {
        return paths;
    }
    ifs >> paths.input_path_ >> paths.delete_path_;
    return paths;
}
