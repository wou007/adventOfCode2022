#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day5.h"

namespace day5
{
    std::vector<std::vector<char>> ParseHeaderData(const std::vector<std::string>& rInput)
    {
        std::vector<std::vector<char>> result(9);

        for(int j = rInput.size() - 1; j >= 0; --j)
        {
            for(int i = 1; i < rInput[j].length(); i += 4)
            {
                if(rInput[j][i] != ' ')
                {
                    result[((i + 3) / 4) - 1].push_back(rInput[j][i]);
                }
            }
        }

        return result;
    }

    void Part1(const char* pFilePath)
    {
        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::vector<char>> ship;

        std::vector<std::string> header;

        while(!stringtools::contains(input[0],"move"))
        {
            header.push_back(input[0]);
            vectortools::RemoveItemOnIndex(input,0);
        }

        header.pop_back();
        header.pop_back();

        ship = ParseHeaderData(header);

        for(const std::string& rL : input)
        {
            std::vector<std::string> output;
            stringtools::splitString(rL," ",output);

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                ship[stoi(output[5]) - 1].push_back(ship[stoi(output[3]) - 1][ship[stoi(output[3]) - 1].size() - 1]);
                ship[stoi(output[3]) - 1].pop_back();
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

        std::vector<std::string> header;

        while(!stringtools::contains(input[0],"move"))
        {
            header.push_back(input[0]);
            vectortools::RemoveItemOnIndex(input,0);
        }

        header.pop_back();
        header.pop_back();

        ship = ParseHeaderData(header);

        for(const std::string& rL : input)
        {
            std::vector<std::string> output;
            stringtools::splitString(rL," ",output);

            std::vector<char> stack;
            stack.reserve(stoi(output[1]));

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                stack.push_back(ship[stoi(output[3]) - 1].back());
                ship[stoi(output[3]) - 1].pop_back();
            }

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                ship[stoi(output[5]) - 1].push_back(stack.back());
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