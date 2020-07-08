#include "FileWorker.h"
#include <fstream>
#include <iostream>
#include <filesystem>

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
    return false;
}

void FileWorker::SetOutputBuf(const std::string& ready_to_write) {
    output_buffer_ = ready_to_write;
}


