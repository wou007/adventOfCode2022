#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day7.h"

namespace day7
{
    int ListAllDirectorySizes(const std::vector<std::string>& input, int& rowNumber, std::vector<long>& list)
    {
        int count = 0;
        while(rowNumber < input.size())
        {
            std::string row = input[rowNumber++];
            if(stringtools::contains(row,"$ cd .."))
            {
                break;
            }
            else if(stringtools::contains(row,"$ cd "))
            {
                count += ListAllDirectorySizes(input,rowNumber,list);
            }
            else if(stringtools::contains(row,"$ ls")) //ignore
            {
                
            }
            else if(stringtools::contains(row,"dir "))// ignore
            {
                
            }
            else
            {
                std::vector<std::string> splits;
                stringtools::splitString(row," ",splits);
                count += stoi(splits[0]);
            }
        }

        list.push_back(count);

        return count;
    }

    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        int line = 1;
        std::vector<long> list;
        ListAllDirectorySizes(input,line,list);

        for(long l : list)
        {
            if(l <= 100000)
            {
                result += l;
            }   
        }

        std::cout << "Day 07-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        int line = 1;
        std::vector<long> list;
        long totalsize = ListAllDirectorySizes(input,line,list);

        std::sort(list.begin(),list.end());

        for(long l : list)
        {
            if(totalsize - l < 40000000)
            {
                result = l;
                break;
            }
        }

        std::cout << "Day 07-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}