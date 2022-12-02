#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day2.h"

namespace day2
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for(const std::string& l : input)
        {   
            uint8_t a = (l.c_str()[0] - 'A') + 1;
            uint8_t b = (l.c_str()[2] - 'X') + 1;

            result += b;

            if(a == b)
            {
                result += 3;
            }
            else if((a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1))
            {
                result += 6;
            }
        }

        std::cout << "Day 02-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for(const std::string& l : input)
        {
            uint8_t a = (l.c_str()[0] - 'A') + 1;
            uint8_t b = (l.c_str()[2] - 'X');

            result += b * 3;

            if(b == 0)
            {
                result += ((a + 1) % 3) + 1;
            }
            else if(b == 1)
            {
                result += a;
            }
            else
            {
                result += ((a) % 3) + 1;
            }
        }

        std::cout << "Day 02-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}