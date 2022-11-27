#include <iostream>

#include "tools/fileio.h"
#include "tools/stringtools.h"

namespace day1
{
    void Run(const char* pFilePath)
    {
        std::vector<long> input;
        fileio::fileToLongVector(pFilePath, input);

        std::cout << "Day 01-1: " << count << "\n";
    }
}