#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day6.h"

namespace day6
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for(int i = 0; i < input[0].size(); ++i)
        {
            std::vector<char> arr;
            bool duplicate = false;
            for(int j = 0; j < 4; ++j)
            {
                if(vectortools::DoesContainItem(arr,input[0][i+j]))
                {
                    duplicate = true;
                    break;
                }
                arr.push_back(input[0][i + j]);
            }

            if(!duplicate)
            {            
                result = i + 4;
                break;
            }
        }

        std::cout << "Day 06-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        for(int i = 0; i < input[0].size(); ++i)
        {
            std::vector<char> arr;
            bool duplicate = false;
            for(int j = 0; j < 14; ++j)
            {
                if(vectortools::DoesContainItem(arr,input[0][i+j]))
                {
                    duplicate = true;
                    break;
                }
                arr.push_back(input[0][i + j]);
            }

            if(!duplicate)
            {            
                result = i + 14;
                break;
            }
        }

        std::cout << "Day 06-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}