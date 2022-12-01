#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <vector>
#include <fstream>

namespace fileio
{
    static void fileToStringVector(const char* pFilePath, std::vector<std::string>& rOutput)
    {
        std::ifstream infile(pFilePath);
        std::string line;
        while(std::getline(infile, line))
        {
            rOutput.push_back(line);
        }
    }

    static void fileToLongVector(const char* pFilePath, std::vector<long>& rOutput)
    {
        std::ifstream infile(pFilePath);
        std::string line;
        while(std::getline(infile, line))
        {
            rOutput.push_back(atol(line.c_str()));
        }
    }
}

#endif