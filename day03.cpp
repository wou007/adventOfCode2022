#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day03.h"

namespace day3
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for (const std::string& rL : input)
        {
            std::string first = rL.substr(0,rL.size()/2);
            std::string second = rL.substr(rL.size()/2);

            for(char c : first)
            {
                if(stringtools::contains(second,c) > 0)
                {
                    result += c < ('Z' + 1) ? (c - 'A') + 27 : (c - 'a') + 1;
                    break;
                }
            }
        }

        std::cout << "Day 03-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for (int i = 0; i < input.size(); i += 3)
        {
            for(char c : input[i])
            {
                if(stringtools::contains(input[i + 1],c) > 0 && stringtools::countAppearancesInString(input[i + 2],c) > 0)
                {
                    result += c < ('Z' + 1) ? (c - 'A') + 27 : (c - 'a') + 1;;
                    break;
                }
            }
        }

        std::cout << "Day 03-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}