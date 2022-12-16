#include <iostream>
#include <algorithm>
#include <map>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day16.h"

namespace day16
{
    class Valve
    {
        public:
        std::string name;
        int rate;
        std::vector<std::string> neigbors;
    };

    class Memory
    {
        public:
        std::string name;
        int minutesLeft;
        std::vector<std::string> openedValves;
        int result;
    };

    std::vector<Memory> memory;

    int CalculateMaxPressurePossible(const std::vector<Valve>& valves, std::vector<std::string> openedValves, std::string currentPosition, int minutesLeft)
    {
        int minutesLeftorig = minutesLeft;
        int result = 0;
        int maxPath = 0;
        std::vector<std::string> openedValvesOrig = openedValves;

        for(Memory m : memory)
        {
            if(m.name == currentPosition && m.minutesLeft == minutesLeft && m.openedValves == openedValves)
            {
                return m.result;
            }
        }

        for(auto v : valves)
        {
            if(v.name == currentPosition)
            {
                if(v.rate > 0 && !vectortools::DoesContainItem(openedValves,currentPosition))
                {
                    minutesLeft--;
                    openedValves.push_back(currentPosition);
                    result = minutesLeft * v.rate;
                }

                if(minutesLeft > 1)
                {
                    for(auto n : v.neigbors)
                    {
                        maxPath = std::max(maxPath,CalculateMaxPressurePossible(valves,openedValves,n,minutesLeft - 1));
                    }
                }
                else{
                    //std::cout << minutesLeft << currentPosition << std::endl;
                }
                break;
            }
        }

        std::cout << currentPosition << " " << minutesLeft << ":" << result + maxPath <<std::endl;

        Memory m;
        m.minutesLeft = minutesLeftorig;
        m.name = currentPosition;
        m.openedValves = openedValvesOrig;
        m.result = result + maxPath;

        memory.push_back(m);

        return result + maxPath;
    }

    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::string> delimiters = {"Valve "," has flow rate=",";","valve"};
        std::vector<Valve> valves;

        for(const std::string& l : input)
        {
            Valve v;
            std::vector<std::string> split = stringtools::splitString(l,delimiters);
            
            v.name = split[1];
            v.rate = stoi(split[2]);

            stringtools::eraseStringFromString(split[4],"s ");
            std::vector<std::string> neigbors = stringtools::splitString(split[4],", ");

            for(std::string n : neigbors)
            {
                stringtools::eraseStringFromString(n," ");
                v.neigbors.push_back(n);
            }
            valves.push_back(v);
        }

        result = CalculateMaxPressurePossible(valves,std::vector<std::string>(),"AA",30);

        std::cout << "Day 16-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::cout << "Day 16-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}