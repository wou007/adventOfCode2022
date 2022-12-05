#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day5.h"

namespace day5
{
    void Part1(const char* pFilePath)
    {
        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::vector<char>> ship;
        ship.push_back(std::vector<char>({' '}));
        ship.push_back(std::vector<char>({'R','G','H','Q','S','B','T','N'}));
        ship.push_back(std::vector<char>({'H','S','F','D','P','Z','J'}));
        ship.push_back(std::vector<char>({'Z','H','V'}));
        ship.push_back(std::vector<char>({'M','Z','J','F','G','H'}));
        ship.push_back(std::vector<char>({'T','Z','C','D','L','M','S','R'}));
        ship.push_back(std::vector<char>({'M','T','W','V','H','Z','J'}));
        ship.push_back(std::vector<char>({'T','F','P','L','Z'}));
        ship.push_back(std::vector<char>({'Q','V','W','S'}));
        ship.push_back(std::vector<char>({'W','H','L','M','T','D','N','C'}));

        for(const std::string& rL : input)
        {
            std::vector<std::string> output;
            stringtools::splitString(rL," ",output);

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                ship[stoi(output[5])].push_back(ship[stoi(output[3])][ship[stoi(output[3])].size() - 1]);
                ship[stoi(output[3])].pop_back();
            }
        }

        std::string result;

        for(const std::vector<char>& bla : ship)
        {
            result += bla.back();
        }

        std::cout << "Day 05-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::vector<char>> ship;
        ship.push_back(std::vector<char>({' '}));
        ship.push_back(std::vector<char>({'R','G','H','Q','S','B','T','N'}));
        ship.push_back(std::vector<char>({'H','S','F','D','P','Z','J'}));
        ship.push_back(std::vector<char>({'Z','H','V'}));
        ship.push_back(std::vector<char>({'M','Z','J','F','G','H'}));
        ship.push_back(std::vector<char>({'T','Z','C','D','L','M','S','R'}));
        ship.push_back(std::vector<char>({'M','T','W','V','H','Z','J'}));
        ship.push_back(std::vector<char>({'T','F','P','L','Z'}));
        ship.push_back(std::vector<char>({'Q','V','W','S'}));
        ship.push_back(std::vector<char>({'W','H','L','M','T','D','N','C'}));

        for(const std::string& rL : input)
        {
            std::vector<std::string> output;
            stringtools::splitString(rL," ",output);

            std::vector<char> stack;

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                stack.push_back(ship[stoi(output[3])].back());
                ship[stoi(output[3])].pop_back();
            }

            for(int i = 0; i < stoi(output[1]); ++i)
            {
            ship[stoi(output[5])].push_back(stack.back());
            stack.pop_back();
            }
        }

        std::string result;

        for(const std::vector<char>& bla : ship)
        {
            result += bla.back();
        }

        std::cout << "Day 05-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}