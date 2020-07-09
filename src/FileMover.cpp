#include "FileMover.h"
#include <filesystem>

void FileMover::ToDelete(const std::string& filename, const std::string& delete_folder) {
    std::filesystem::path path = std::filesystem::current_path();
    std::filesystem::directory_iterator del_it(delete_folder);
    size_t i = std::distance(del_it, std::filesystem::directory_iterator {}) + 1;
    std::string new_filename = delete_folder + filename.substr(filename.find_last_of('/')) + ".0000";
    std::string number = std::to_string(i);
    for (auto n = number.rbegin(), f = new_filename.rbegin(); n != number.rend();) {
        *f++ = *n++;
    }
    std::filesystem::rename(filename, new_filename);
}
