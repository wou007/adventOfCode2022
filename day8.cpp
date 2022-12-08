#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day8.h"

namespace day8
{
    bool IsTreeVisible(matrix::Matrix<char>& map, int x, int y)
    {
        char valueOfTree = map.GetValueOfPoint(x,y);
        bool visible[4] = {true,true,true,true};

        for(int i = x - 1; i >= 0; i--)
        {
            if(map.GetValueOfPoint(i,y) >= valueOfTree)
            {
                visible[0] = false;
            }
        }

        for(int i = x + 1; i < map.GetWidth(); i++)
        {
            if(map.GetValueOfPoint(i,y) >= valueOfTree)
            {
                visible[1] = false;
            }
        }

        for(int i = y - 1; i >= 0; i--)
        {
            if(map.GetValueOfPoint(x,i) >= valueOfTree)
            {
                visible[2] = false;
            }
        }

         for(int i = y + 1; i < map.GetHeight(); i++)
        {
            if(map.GetValueOfPoint(x,i) >= valueOfTree)
            {
                visible[3] = false;
            }
        } 

        return visible[0] || visible[1] || visible[2] || visible[3];
    }

    int calculateScenicScore(matrix::Matrix<char>& map, int x, int y)
    {
        char valueOfTree = map.GetValueOfPoint(x,y);
        int score[4] = {0,0,0,0};

        for(int i = x - 1; i >= 0; i--)
        {
            score[0]++;
            if(map.GetValueOfPoint(i,y) >= valueOfTree)
            {
                break;
            }
        }

        for(int i = x + 1; i < map.GetWidth(); i++)
        {
            score[1]++;
            if(map.GetValueOfPoint(i,y) >= valueOfTree)
            {
                break;
            }
        }

        for(int i = y - 1; i >= 0; i--)
        {
            score[2]++;
            if(map.GetValueOfPoint(x,i) >= valueOfTree)
            {
                break;
            }
        }

         for(int i = y + 1; i < map.GetHeight(); i++)
        {
            score[3]++;
            if(map.GetValueOfPoint(x,i) >= valueOfTree)
            {
                break;
            }
        } 

        return score[0] * score[1] * score[2] * score[3];
    }

    void Part1(const char* pFilePath)
    {
        long result = 0;

        matrix::Matrix<char> map;
        map.FillFromFile(pFilePath);

        for(int x = 0; x < map.GetWidth(); x++)
        {
            for(int y = 0; y < map.GetHeight(); y++)
            {
                if(IsTreeVisible(map,x,y))
                {    
                    result++;
                }
            }            
        }

        std::cout << "Day 08-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        int result = 0;

        matrix::Matrix<char> map;
        map.FillFromFile(pFilePath);

        for(int x = 0; x < map.GetWidth(); x++)
        {
            for(int y = 0; y < map.GetHeight(); y++)
            {
                int score = calculateScenicScore(map,x,y);
                result = std::max(result,score);
            }            
        }

        std::cout << "Day 08-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}