#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day10.h"

namespace day10
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        int cyclesDoneOfCurrentInstructions = 0;
        int line = 0;
        int value = 1;
        for(int i = 1; i <= 220; ++i)
        {
            cyclesDoneOfCurrentInstructions++;

            if(i % 40 == 20)
            {
                result += i * value;
            }

            if(input[line] == "noop")
            {
                cyclesDoneOfCurrentInstructions = 0;
                line++;
            }
            else if(cyclesDoneOfCurrentInstructions == 2)
            {
                cyclesDoneOfCurrentInstructions = 0;
                std::vector<std::string> output;
                stringtools::splitString(input[line]," ",output);
                value += stoi(output[1]);
                line++;
            }
        }

        std::cout << "Day 10-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        int cyclesDoneOfCurrentInstructions = 0;
        int line = 0;
        int value = 1;
        for(int i = 0; i < 240; ++i)
        {
            cyclesDoneOfCurrentInstructions++;

            if(i % 40 == 0)
            {
                std::cout << '\n';
            }

            if(abs(value - (i % 40)) > 1)
            {
                std::cout << '.';
            }
            else
            {
                std::cout << '#';
            }

            if(input[line] == "noop")
            {
                cyclesDoneOfCurrentInstructions = 0;
                line++;
            }
            else if(cyclesDoneOfCurrentInstructions == 2)
            {
                cyclesDoneOfCurrentInstructions = 0;
                std::vector<std::string> output;
                stringtools::splitString(input[line]," ",output);
                value += stoi(output[1]);
                line++;
            }
        }
        std::cout << '\n';

        std::cout << "Day 10-2: " << "PZGPKPEB" << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}