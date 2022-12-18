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
        std::map<std::string,int> distanceToNeigbors;

        void CalculateDistanceToAllNeigborsWithRate(const std::vector<Valve>& valveList, Valve CurrentVisiting, int currentDistance)
        {
            if(CurrentVisiting.name == name && currentDistance > 0)
            {
                return; //back at start
            }
            else if(distanceToNeigbors.find(CurrentVisiting.name) != distanceToNeigbors.end())
            {
                if(distanceToNeigbors[CurrentVisiting.name] <= currentDistance)
                {
                    return; //no cheaper way found
                }
            }

            distanceToNeigbors[CurrentVisiting.name] = currentDistance;

            for(const std::string& n : CurrentVisiting.neigbors)
            {
                for(const Valve& v : valveList)
                {   
                    if(v.name == n)
                    {
                        CalculateDistanceToAllNeigborsWithRate(valveList, v, currentDistance + 1);
                    }
                }
            }
        }
    };

    int CalculateMaxPressurePossible(std::vector<Valve>& valves, std::vector<std::string> openedValves, Valve& currentPosition, int minutesLeft)
    {
        int minutesLeftorig = minutesLeft;
        int result = 0;
        int maxPath = 0;
        std::vector<std::string> openedValvesOrig = openedValves;

        if(currentPosition.rate > 0 && !vectortools::DoesContainItem(openedValves,currentPosition.name))
        {
            minutesLeft--;
            openedValves.push_back(currentPosition.name);
            result = minutesLeft * currentPosition.rate;
        }

        for(Valve& n : valves)
        {
            if(currentPosition.distanceToNeigbors[n.name] < minutesLeft)
            {
                if(n.rate > 0 && !vectortools::DoesContainItem(openedValves,n.name))
                {
                    maxPath = std::max(maxPath,CalculateMaxPressurePossible(valves,openedValves,n,minutesLeft - currentPosition.distanceToNeigbors[n.name]));
                }
            }
        }

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

        Valve start;

        for(Valve& v : valves)
        {
            v.CalculateDistanceToAllNeigborsWithRate(valves,v,0);
            if(v.name == "AA")
            {
                start = v;
            }
        }

        result = CalculateMaxPressurePossible(valves,std::vector<std::string>(),start,30);

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