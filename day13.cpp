#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day13.h"

namespace day13
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for(int i = 0; i < input.size(); i+= 3)
        {
            std::string a = input[i];
            std::string b = input[i+1];

            for(int j = 0; j < a.size(); ++j)
            {
                
            }
        }

        std::cout << "Day 13-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;



        std::cout << "Day 13-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}