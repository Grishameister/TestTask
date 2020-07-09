#ifndef TESTTASK_FILEMOVER_H
#define TESTTASK_FILEMOVER_H

#include <string>

class FileMover {
public:
    FileMover() = default;
    ~FileMover() = default;

    void ToDelete(const std::string& filename, const std::string& delete_folder);
};

#endif //TESTTASK_FILEMOVER_H
