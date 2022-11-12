#include <string>
#include <vector>
#include <fstream>

namespace tools
{
    void fileToStringVector(const std::string& rPath, std::vector<std::string>& rOutput)
    {
        std::ifstream infile("thefile.txt");
        std::string line;
        while(std::getline(infile, line))
        {
            rOutput.push_back(line);
        }
    }
}