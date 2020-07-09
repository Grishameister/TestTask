#include <filesystem>
#include <thread>

#include "FileWorker.h"
#include "Parser.h"
#include "FileMover.h"

int main() {
    FileWorker fw;
    Parser p;
    FileMover fm;

    std::filesystem::path path = std::filesystem::current_path();
    std::string parent_path = path.parent_path().string();

    while (true) {
        if (!fw.ReadFileToBuf(parent_path + "/input_data/test.xml")) {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            continue;
        }

        fw.SetOutputBuf(p.Parse(fw.GetInputBuf()));
        fm.ToDelete(parent_path + "/input_data/test.xml", parent_path + "/to_delete");
    }
    return 0;
}
