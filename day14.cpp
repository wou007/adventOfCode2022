#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day14.h"

namespace day14
{
    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        int minX = INT_MAX;
        int maxX = 0;
        int minY = 0; //should be 0 or smaller
        int maxY = 0;

        for(std::string& l : input)
        {
            std::vector<std::string> splits;
            stringtools::splitString(l," -> ", splits);
            for(std::string& c : splits)
            {
                std::vector<std::string> coords;
                stringtools::splitString(c,",", coords);

                minX = std::min(stoi(coords[0]),minX);
                minY = std::min(stoi(coords[1]),minY);
                maxX = std::max(stoi(coords[0]),maxX);
                maxY = std::max(stoi(coords[1]),maxY);
            }
        }

        minX--;
        maxX++;
        maxY++;
        maxX++;
        maxY++;

        matrix::Matrix<char> map(maxX-minX,maxY-minY,'.');

        for(std::string& l : input)
        {
            std::vector<std::string> splits;
            stringtools::splitString(l," -> ", splits);
            for(int i = 1; i < splits.size(); ++i)
            {
                std::vector<std::string> a;
                stringtools::splitString(splits[i-1],",", a);
                std::vector<std::string> b;
                stringtools::splitString(splits[i],",", b);

                if(a[0] == b[0])
                {
                    for(int i = std::min(stoi(a[1]),stoi(b[1])); i <= std::max(stoi(a[1]),stoi(b[1])); i++)
                    {
                        map.SetValueOfPoint(stoi(a[0]) - minX,i,'#');
                    }
                }
                else
                {
                    for(int i = std::min(stoi(a[0]),stoi(b[0])); i <= std::max(stoi(a[0]),stoi(b[0])); i++)
                    {
                        map.SetValueOfPoint(i - minX,stoi(a[1]),'#');
                    }
                }
            }
        }

        map.SetValueOfPoint(500 - minX,0,'+');

        bool finished = false;

        while(!finished)
        {
            //drop sand
            int x = 500 - minX;
            int y = 0;

            while(true)//not found end value;
            {
                if(y >= maxY - 2)
                {
                    finished = true;
                    break;
                }
                if(map.GetValueOfPoint(x,y+1) == '.')
                {
                    y++;
                }
                else if(map.GetValueOfPoint(x-1,y+1) == '.')
                {
                    y++;
                    x--;
                }
                else if(map.GetValueOfPoint(x+1,y+1) == '.')
                {
                    y++;
                    x++;
                }
                else
                {
                    map.SetValueOfPoint(x,y,'O');
                    result++;
                    break;
                }
            }
        }

        std::cout << "Day 14-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        int minX = INT_MAX;
        int maxX = 0;
        int minY = 0; //should be 0 or smaller
        int maxY = 0;

        for(std::string& l : input)
        {
            std::vector<std::string> splits;
            stringtools::splitString(l," -> ", splits);
            for(std::string& c : splits)
            {
                std::vector<std::string> coords;
                stringtools::splitString(c,",", coords);

                minX = std::min(stoi(coords[0]),minX);
                minY = std::min(stoi(coords[1]),minY);
                maxX = std::max(stoi(coords[0]),maxX);
                maxY = std::max(stoi(coords[1]),maxY);
            }
        }

        minX -= maxY;
        maxX += maxY;
        maxY++;
        maxX++;
        maxY++;

        matrix::Matrix<char> map(maxX-minX,maxY-minY,'.');

        for(std::string& l : input)
        {
            std::vector<std::string> splits;
            stringtools::splitString(l," -> ", splits);
            for(int i = 1; i < splits.size(); ++i)
            {
                std::vector<std::string> a;
                stringtools::splitString(splits[i-1],",", a);
                std::vector<std::string> b;
                stringtools::splitString(splits[i],",", b);

                if(a[0] == b[0])
                {
                    for(int i = std::min(stoi(a[1]),stoi(b[1])); i <= std::max(stoi(a[1]),stoi(b[1])); i++)
                    {
                        map.SetValueOfPoint(stoi(a[0]) - minX,i,'#');
                    }
                }
                else
                {
                    for(int i = std::min(stoi(a[0]),stoi(b[0])); i <= std::max(stoi(a[0]),stoi(b[0])); i++)
                    {
                        map.SetValueOfPoint(i - minX,stoi(a[1]),'#');
                    }
                }
            }
        }

        map.SetValueOfPoint(500 - minX,0,'+');

        bool finished = false;

        while(!finished)
        {
            //drop sand
            int x = 500 - minX;
            int y = 0;

            while(true)//not found end value;
            {
                if(y == maxY - 1)
                {
                    map.SetValueOfPoint(x,y,'O');
                    result++;
                    break;
                }
                if(map.GetValueOfPoint(x,y+1) == '.')
                {
                    y++;
                }
                else if(map.GetValueOfPoint(x-1,y+1) == '.')
                {
                    y++;
                    x--;
                }
                else if(map.GetValueOfPoint(x+1,y+1) == '.')
                {
                    y++;
                    x++;
                }
                else
                {
                    map.SetValueOfPoint(x,y,'O');
                    result++;
                    if(y == 0)
                    {
                        finished = true;
                    }
                    break;
                }
            }
        }

        std::cout << "Day 14-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}