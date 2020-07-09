#include <filesystem>
#include <thread>

#include "FileWorker.h"
#include "Parser.h"
#include "FileMover.h"

int main() {
    FileWorker f;
    Parser p;
    FileMover fm;

    std::filesystem::path path = std::filesystem::current_path();
    std::string parent_path = path.parent_path().string();
    while (true) {
        if (!f.ReadFileToBuf(parent_path + "/input_data/test.xml")) {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            continue;
        }

        f.SetOutputBuf(p.Parse(f.GetInputBuf()));
        fm.ToDelete(parent_path + "/input_data/test.xml", parent_path + "/to_delete");
    }
    return 0;
}
