#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"
#include "tools/bittwiddling.h"

#include "day06.h"

namespace day6
{
    int FindEndOfMarkerNaive(const std::string& rInput, int markerLength)
    {
        int result = 0;
        for(int i = 0; i < rInput.size(); ++i)
        {
            std::vector<char> arr;
            arr.reserve(markerLength);
            bool duplicate = false;
            for(int j = 0; j < markerLength; ++j)
            {
                if(vectortools::DoesContainItem(arr,rInput[i+j]))
                {
                    duplicate = true;
                    break;
                }
                arr.push_back(rInput[i + j]);
            }

            if(!duplicate)
            {            
                result = i + markerLength;
                break;
            }
        }

        return result;
    }

    int FindEndOfMarkerFancy(const std::string& rInput, int markerLength)
    {
        int result = 0;
        uint32_t mask = 0;
        for(int i = 0; i < rInput.size(); ++i)
        {
            mask ^= 1 << (rInput[i] - 'a');
            if(i >= markerLength)
            {
                mask ^= 1 << (rInput[i-markerLength] - 'a');
                if(bittwiddling::CountBitsSet(mask) == markerLength)
                {
                    result = i + 1;
                    break;
                }
            } 
        }

        return result;
    }

    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        result = FindEndOfMarkerFancy(input[0], 4);

        std::cout << "Day 06-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        result = FindEndOfMarkerFancy(input[0], 14);

        std::cout << "Day 06-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}