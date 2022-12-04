#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day4.h"

namespace day4
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::string> splits({"-",",","-"});

        for(const std::string& l : input)
        {
            std::vector<std::string> lsplit;
            stringtools::splitString(l,splits,lsplit);

            int i0 = stoi(lsplit[0]);
            int i1 = stoi(lsplit[1]);
            int i2 = stoi(lsplit[2]);
            int i3 = stoi(lsplit[3]);
            
            if((i1 - i0) > (i3 - i2))
            {
                if((i0 <= i2) && (i1 >= i3))
                {
                    result++;
                }
            }
            else
            {
                if((i2 <= i0) && (i3 >= i1))
                {
                    result++;
                }
            }
        }

        std::cout << "Day 04-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::string> splits({"-",",","-"});

        for(const std::string& l : input)
        {
            std::vector<std::string> lsplit;
            stringtools::splitString(l,splits,lsplit);
            if(stoi(lsplit[0]) < stoi(lsplit[2]))
            {
                if(stoi(lsplit[1]) >= stoi(lsplit[2]))
                {
                    result++;
                }
            }
            else
            {
                if(stoi(lsplit[3]) >= stoi(lsplit[0]))
                {
                    result++;
                }
            }
        }

        std::cout << "Day 04-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}