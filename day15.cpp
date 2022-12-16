#include <iostream>
#include <algorithm>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day15.h"

namespace day15
{
    void Part1(const char* pFilePath)
    {
        long result = 0;
        long rowToCheck = 10;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::string> delimiters({"x=",", y=",": ","x=",", y="});

        std::vector<std::pair<long,long>> beaconFreeLocations;
        std::vector<long> beaconLocations;

        for(std::string& l : input)
        {
            std::vector<std::string> splits = stringtools::splitString(l,delimiters);
            long sensorX = stoi(splits[1]);
            long sensorY = stoi(splits[2]);
            long beaconX = stoi(splits[4]);
            long beaconY = stoi(splits[5]);

            long distance = std::abs(sensorX - beaconX) + std::abs(sensorY - beaconY);

            if(distance >= std::abs(rowToCheck - sensorY))
            {
                long xLeft = distance - std::abs(rowToCheck - sensorY);

                beaconFreeLocations.push_back(std::pair<long,long>(sensorX - xLeft,sensorX + xLeft));
            }

            if(beaconY == rowToCheck)
            {
                if(!vectortools::DoesContainItem(beaconLocations,beaconX))
                {
                    beaconLocations.push_back(beaconX);
                    result--;
                }
            }
        }

        std::vector<std::pair<long,long>> temp = beaconFreeLocations;
        
        while(temp.size() > 1)
        {
            std::sort(temp.begin(),temp.end());
            if(temp[0].second >= temp[1].first)
            {
                temp.push_back(std::pair<long,long>(std::min(temp[0].first,temp[1].first),std::max(temp[0].second,temp[1].second)));
                vectortools::RemoveItemOnIndex(temp,0);
                vectortools::RemoveItemOnIndex(temp,0);
            }
            else
            {
                break;
            }
        }

        result += temp[0].second - temp[1].first;
        result += 1;

        std::cout << "Day 15-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long long result = 0;
        long rowsToCheck = 4000000;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<std::string> delimiters({"x=",", y=",": ","x=",", y="});
        std::vector<std::pair<std::pair<long,long>,std::pair<long,long>>> sbcombs;

        for(std::string& l : input)
        {
            std::vector<std::string> splits = stringtools::splitString(l,delimiters);
            long sensorX = stoi(splits[1]);
            long sensorY = stoi(splits[2]);
            long beaconX = stoi(splits[4]);
            long beaconY = stoi(splits[5]);

            sbcombs.push_back(std::pair<std::pair<long,long>,std::pair<long,long>>(std::pair<long,long>(sensorX,sensorY),std::pair<long,long>(beaconX,beaconY)));
        }

        for(long r = 0; r <= rowsToCheck; ++r)
        {
            std::vector<std::pair<long,long>> beaconFreeLocations;
            
            for(auto c : sbcombs)
            {
                long distance = std::abs(c.first.first - c.second.first) + std::abs(c.first.second - c.second.second);

                if(distance >= std::abs(r - c.first.second))
                {
                    long xLeft = distance - std::abs(r - c.first.second);

                    beaconFreeLocations.push_back(std::pair<long,long>(c.first.first - xLeft,c.first.first + xLeft));
                }
            }
            
            std::sort(beaconFreeLocations.begin(),beaconFreeLocations.end());

            while(beaconFreeLocations.size() > 1)
            {
                if(beaconFreeLocations[0].second >= beaconFreeLocations[1].first)
                {
                    beaconFreeLocations[1] = (std::pair<long,long>(std::min(beaconFreeLocations[0].first,beaconFreeLocations[1].first),std::max(beaconFreeLocations[0].second,beaconFreeLocations[1].second)));
                    vectortools::RemoveItemOnIndex(beaconFreeLocations,0);
                }
                else
                {
                    break;
                }
            }

            if(beaconFreeLocations.size() > 1)
            {                
                result = 4000000ll * (long long)(beaconFreeLocations[0].second + 1);
                result += r;

                break;
            }
        }
        
        std::cout << "Day 15-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}