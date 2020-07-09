#include <filesystem>
#include <thread>

#include "FileWorker.h"
#include "Parser.h"
#include "FileMover.h"
#include "ConfigReader.h"


int main() {
    FileWorker fw;
    Parser p;
    FileMover fm;
    ConfigReader cr;

    std::filesystem::path path = std::filesystem::current_path();
    std::string parent_path = path.parent_path().string();
    Paths paths = cr.ReadPaths(parent_path + "/config.txt");

    while (true) {
        if (!fw.ReadFileToBuf(parent_path + paths.input_path_)) {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            continue;
        }

        fw.SetOutputBuf(p.Parse(fw.GetInputBuf()));
        fm.ToDelete(parent_path + paths.input_path_, parent_path + paths.delete_path_);
    }
    return 0;
}
