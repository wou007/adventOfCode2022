#include <iostream>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

namespace day1
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<long> input;
        fileio::fileToLongVector(pFilePath, input);

        std::cout << "Day 01-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<long> input;
        fileio::fileToLongVector(pFilePath, input);

        std::cout << "Day 01-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}