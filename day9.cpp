#include <iostream>
#include <algorithm>
#include <tuple>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day9.h"

namespace day9
{
    void Part1(const char* pFilePath)
    {
        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<matrix::Coordinate> visited;
        matrix::Coordinate hl(0,0);
        matrix::Coordinate tl(0,0);
        visited.push_back(tl);

        for(std::string l : input)
        {
            std::vector<std::string> output;
            stringtools::splitString(l," ",output);

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                matrix::Coordinate prevhl = hl;
            if(output[0] == "U")
            {
                hl.SetY(hl.GetY() + 1);
            }
            else if (output[0] == "D")
            {
                hl.SetY(hl.GetY() - 1);
            }
            else if (output[0] == "L")
            {
                hl.SetX(hl.GetX() - 1);
            }
            else if (output[0] == "R")
            {
                hl.SetX(hl.GetX() + 1);
            }

            if(std::abs(hl.GetX() - tl.GetX()) > 1 || std::abs(hl.GetY() - tl.GetY()) > 1)
            {
                tl = prevhl;
                if(!vectortools::DoesContainItem(visited,tl))
                {
                    visited.push_back(tl);
                }
            }
            }
        }

        std::cout << "Day 09-1: " << visited.size() << "\n";
    }

    void Part2(const char* pFilePath)
    {
        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<matrix::Coordinate> visited;
        std::array<matrix::Coordinate,10> rope;
        visited.push_back(matrix::Coordinate(0,0));

        for(std::string l : input)
        {
            std::vector<std::string> output;
            stringtools::splitString(l," ",output);

            

            for(int i = 0; i < stoi(output[1]); ++i)
            {
                matrix::Coordinate prev = rope[0];
                if(output[0] == "U")
                {
                    rope[0].SetY(rope[0].GetY() + 1);
                }
                else if (output[0] == "D")
                {
                    rope[0].SetY(rope[0].GetY() - 1);
                }
                else if (output[0] == "L")
                {
                    rope[0].SetX(rope[0].GetX() - 1);
                }
                else if (output[0] == "R")
                {
                    rope[0].SetX(rope[0].GetX() + 1);
                }

                for(int j = 1; j < rope.size(); j++)
                {
                    if(std::abs(rope[j].GetX() - rope[j - 1].GetX()) > 1 || std::abs(rope[j].GetY() - rope[j - 1].GetY()) > 1)
                    {
                        if(std::abs(rope[j].GetX() - rope[j - 1].GetX()) > 0) 
                        {
                            if(rope[j].GetX() > rope[j - 1].GetX())
                            {
                                rope[j].SetX(rope[j].GetX() - 1);
                            }
                            else
                            {
                                rope[j].SetX(rope[j].GetX() + 1);
                            }
                        }
                        if(std::abs(rope[j].GetY() - rope[j - 1].GetY()) > 0)
                        {
                            if(rope[j].GetY() > rope[j - 1].GetY())
                            {
                                rope[j].SetY(rope[j].GetY() - 1);
                            }
                            else
                            {
                                rope[j].SetY(rope[j].GetY() + 1);
                            }
                        }
                        if(!vectortools::DoesContainItem(visited,rope[9]))
                        {
                            visited.push_back(rope[9]);
                        }
                    }
                }
            }
        }

        std::cout << "Day 09-2: " << visited.size() << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}