#include "FileWorker.h"
#include <fstream>

std::string FileWorker::GetInputBuf() {
    return input_buffer_;
}

bool FileWorker::ReadFileToBuf(const std::string& filename) {
    std::ifstream fs(filename);
    if (!fs.is_open()) {
        return false;
    }
    getline(fs, input_buffer_, std::string::traits_type::to_char_type(std::string::traits_type::eof()));
    return true;
}

bool FileWorker::WriteBufToFile(const std::string& filename) {
    std::ofstream fs(filename);
    fs.write(output_buffer_.c_str(), output_buffer_.length() - 1);
    return true;
}

void FileWorker::SetOutputBuf(const std::string& ready_to_write) {
    output_buffer_ = ready_to_write;
}
