#ifndef TESTTASK_FILEWORKER_H
#define TESTTASK_FILEWORKER_H
#include <string>

class FileWorker {
public:
    FileWorker() = default;
    bool ReadFileToBuf(const std::string& filename);
    bool WriteBufToFile(const std::string& filename);
    std::string GetInputBuf();
    void SetOutputBuf(const std::string& ready_to_write);
private:
    std::string input_buffer_;
    std::string output_buffer_;
};


#endif //TESTTASK_FILEWORKER_H
