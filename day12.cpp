#include <iostream>
#include <algorithm>
#include <queue>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day12.h"

namespace day12
{
    void Part1(const char* pFilePath)
    {
        int result = INT_MAX;

        matrix::Matrix<char> map;
        map.FillFromFile(pFilePath);

        std::vector<matrix::Coordinate> start;
        map.GetOccurencesOfField('S',&start);
        matrix::Matrix<int> history(map.GetWidth(),map.GetHeight(),INT_MAX);
        history.SetValueOfPoint(start[0],0);

        std::queue<matrix::Coordinate> queue;
        queue.push(start[0]);

        char letter = 'a';

        while(queue.size() > 0)
        {
            matrix::Coordinate pos = queue.front();
            queue.pop();
            std::vector<matrix::Coordinate> neighbors = map.GetNeigborsOf(pos,false);
            char posHeigth = map.GetValueOfPoint(pos);
            int posCost = history.GetValueOfPoint(pos);

            for(const matrix::Coordinate& n : neighbors)
            {
                char nHeigth = map.GetValueOfPoint(n);
                int nCost = history.GetValueOfPoint(n);

                if(nHeigth == 'E' && (posHeigth == 'y' || posHeigth == 'z'))
                {
                    history.SetValueOfPoint(n,posCost + 1);
                    result = std::min(result,posCost + 1);
                }
                else if((nHeigth - posHeigth < 2) || (posHeigth == 'S' && nHeigth == 'a'))
                {
                    if(nCost > (posCost + 1))
                    {
                        history.SetValueOfPoint(n,posCost + 1);
                        queue.push(n);
                    }
                }
            }
        }

        std::cout << "Day 12-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        int result = INT_MAX;

        matrix::Matrix<char> map;
        map.FillFromFile(pFilePath);

        std::vector<matrix::Coordinate> start;
        map.GetOccurencesOfField('a',&start);
        matrix::Matrix<int> history(map.GetWidth(),map.GetHeight(),INT_MAX);
        

        std::queue<matrix::Coordinate> queue;
        for(matrix::Coordinate s : start)
        {
            queue.push(s);
            history.SetValueOfPoint(s,0);
        }

        char letter = 'a';

        while(queue.size() > 0)
        {
            matrix::Coordinate pos = queue.front();
            queue.pop();
            std::vector<matrix::Coordinate> neighbors = map.GetNeigborsOf(pos,false);
            char posHeigth = map.GetValueOfPoint(pos);
            int posCost = history.GetValueOfPoint(pos);

            for(const matrix::Coordinate& n : neighbors)
            {
                char nHeigth = map.GetValueOfPoint(n);
                int nCost = history.GetValueOfPoint(n);

                if(nHeigth == 'E' && (posHeigth == 'y' || posHeigth == 'z'))
                {
                    history.SetValueOfPoint(n,posCost + 1);
                    result = std::min(result,posCost + 1);
                }
                else if((nHeigth - posHeigth < 2) || (posHeigth == 'S' && nHeigth == 'a'))
                {
                    if(nCost > (posCost + 1))
                    {
                        history.SetValueOfPoint(n,posCost + 1);
                        queue.push(n);
                    }
                }
            }
        }

        std::cout << "Day 12-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}