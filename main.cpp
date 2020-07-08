#include <iostream>
#include "FileWorker.h"
#include "Parser.h"
#include <filesystem>

int main() {
    FileWorker f;
    f.ReadFileToBuf("../input_data/test.xml");
    Parser p;
    p.Parse(f.GetInputBuf());
    return 0;
}
