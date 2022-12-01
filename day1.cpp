#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day1.h"

namespace day1
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<long> input;
        fileio::fileToLongVector(pFilePath, input);

        long temp = 0;

        for(long i : input)
        {
            if(i > 0)
            {
                temp += i;
            }
            else
            {
                result = temp > result ? temp : result;
                temp =0;
            }
        }

        std::cout << "Day 01-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<long> input;
        fileio::fileToLongVector(pFilePath, input);

        std::vector<long> list;
        long temp = 0;

        for(long i : input)
        {
            if(i > 0)
            {
                temp += i;
            }
            else
            {
                list.push_back(temp);
                temp =0;
            }
        }

        std::sort(list.begin(), list.end());
        auto end = list.end();
        result += *--end;
        result += *--end;
        result += *--end;


        std::cout << "Day 01-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}