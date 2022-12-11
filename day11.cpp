#include <iostream>
#include <algorithm>
#include <math.h>

#include "tools/fileio.h"
#include "tools/stringtools.h"
#include "tools/matrix.h"
#include "tools/vectortools.h"

#include "day11.h"

namespace day11
{
    long commonDivisor = 0;

    class Monkey
    {
        public:
        enum Calculation
        {
            MULTIPLY,
            ADD,
            POWER_OF_TWO
        };

        Calculation m_calc;
        long m_calcNumber;
        long m_checkNumber;
        long m_trueMonkey;
        long m_falseMonkey;
        std::vector<long long> m_items;
        long m_count;

        void inspectAll(std::vector<Monkey>& rMonkeys, bool division)
        {
            for(long long i : m_items)
            {
                m_count++;
                switch (m_calc)
                {
                case MULTIPLY:
                    i *= m_calcNumber;
                    break;
                    case ADD:
                    i += m_calcNumber;
                    break;
                    case POWER_OF_TWO:
                    i *= i;
                    break;
                }

                if(division)
                {
                    i = std::floor(static_cast<double>(i) / 3);
                }

                if((i % m_checkNumber) == 0)
                {
                    rMonkeys[m_trueMonkey].m_items.push_back(i % commonDivisor);
                }
                else
                {
                    rMonkeys[m_falseMonkey].m_items.push_back(i % commonDivisor);
                }
                
            }
            m_items.clear();
        }
    };

    std::vector<Monkey> ParseFileToMonkeys(const std::vector<std::string> rInput)
    {
        std::vector<Monkey> monkeys;
        Monkey tempMonkey;

        for(const std::string& rL : rInput)
        {   
            std::vector<std::string> output;
            if(stringtools::contains(rL,"Monkey"))
            {
                tempMonkey.m_count = 0;
            }
            else if(stringtools::contains(rL,"Starting"))
            {
                stringtools::splitString(rL,":",output);
                std::string items = output[1];
                stringtools::eraseStringFromString(items," ");
                stringtools::splitString(items,",",output);
                for(std::string i : output)
                {
                    tempMonkey.m_items.push_back(stoi(i));
                }
            }
            else if(stringtools::contains(rL,"Operation"))
            {
                if(stringtools::contains(rL, "*"))
                {
                    tempMonkey.m_calc = Monkey::Calculation::MULTIPLY;
                    stringtools::splitString(rL," ",output);
                    if(output[7] == "old")
                    {
                        tempMonkey.m_calc = Monkey::Calculation::POWER_OF_TWO;
                    }
                    else
                    {
                        tempMonkey.m_calcNumber = stoi(output[7]);
                    }
                }
                else if(stringtools::contains(rL, "+"))
                {
                    tempMonkey.m_calc = Monkey::Calculation::ADD;
                    stringtools::splitString(rL," ",output);
                    tempMonkey.m_calcNumber = stoi(output[7]);
                }
            }
            else if(stringtools::contains(rL,"Test"))
            {
                stringtools::splitString(rL," ",output);
                tempMonkey.m_checkNumber = stoi(output[5]);
            }
            else if(stringtools::contains(rL,"true"))
            {
                stringtools::splitString(rL," ",output);
                tempMonkey.m_trueMonkey = stoi(output[9]);
            }
            else if(stringtools::contains(rL,"false"))
            {
                stringtools::splitString(rL," ",output);
                tempMonkey.m_falseMonkey = stoi(output[9]);
            }
            else
            {
                monkeys.push_back(tempMonkey);
                tempMonkey = Monkey();
            }
        }

        monkeys.push_back(tempMonkey);

        commonDivisor = 1;
        for(const Monkey& m : monkeys)
        {
            commonDivisor *= m.m_checkNumber;
        }

        return monkeys;
    }

    void Part1(const char* pFilePath)
    {
        long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<Monkey> monkeys = ParseFileToMonkeys(input);

        for(long i = 0; i < 20; ++i)
        {
            for(Monkey& m : monkeys)
            {
                m.inspectAll(monkeys, true);
            }
        }

        std::vector<long> counts;
        for(Monkey& m : monkeys)
        {
            counts.push_back(m.m_count);
        }

        std::sort(counts.begin(),counts.end());

        result = counts[counts.size() - 1] * counts[counts.size() - 2];

        std::cout << "Day 11-1: " << result << "\n";
    }

    void Part2(const char* pFilePath)
    {
        long long result = 0;

        std::vector<std::string> input;
        fileio::fileToStringVector(pFilePath, input);

        std::vector<Monkey> monkeys = ParseFileToMonkeys(input);        

        for(long i = 0; i < 10000; ++i)
        {
            for(Monkey& m : monkeys)
            {
                m.inspectAll(monkeys, false);
            }
        }

        std::vector<long long> counts;
        for(Monkey& m : monkeys)
        {
            counts.push_back(m.m_count);
        }

        std::sort(counts.begin(),counts.end());

        result = counts[counts.size() - 1] * counts[counts.size() - 2];

        std::cout << "Day 11-2: " << result << "\n";
    }

    void Run(const char* pFilePath)
    {
        Part1(pFilePath);
        Part2(pFilePath);
    }
}