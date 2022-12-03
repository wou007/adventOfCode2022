#ifndef STRING_TOOLS_H_
#define STRING_TOOLS_H_

#include <string>
#include <vector>
#include <array>

namespace stringtools {

    static void splitString(const std::string& rInput, const std::vector<std::string>& rDelimiters, std::vector<std::string>& rOutput)
    {
        rOutput.clear();
        int pos = 0, prevPos = 0;
        for(const std::string& rD : rDelimiters)
        {
            pos = rInput.find(rD, prevPos);
            rOutput.push_back(rInput.substr(prevPos,pos - prevPos));
            prevPos = pos + rD.length();
        }
        rOutput.push_back(rInput.substr(prevPos,rInput.length()-prevPos));
    }

    static void splitString(const std::string& rInput, std::string delimiter, std::vector<std::string>& rOutput)
    {
        rOutput.clear();
        int pos = 0, prevPos = 0;
        while((pos = rInput.find(delimiter, prevPos)) != std::string::npos)
        {
            rOutput.push_back(rInput.substr(prevPos,pos - prevPos));
            prevPos = pos + delimiter.length();
        }
        rOutput.push_back(rInput.substr(prevPos,rInput.length()-prevPos));
    }

    static long countAppearancesInString(const std::string& rInput, const std::string& rItemToFind)
    {
        long result = 0;
        int pos = 0, prevPos = 0;
        while((pos = rInput.find(rItemToFind, prevPos)) != std::string::npos)
        {
            prevPos = pos + rItemToFind.length();
            ++result;
        }

        return result;
    }

    inline bool contains(const std::string& rInput, const std::string& rItemToFind)
    {
        return rInput.find(rItemToFind) != std::string::npos;
    }

    inline bool contains(const std::string& rInput, char itemToFind)
    {
        return rInput.find(itemToFind) != std::string::npos;
    }

    static long countAppearancesInString(const std::string& rInput, char itemToFind)
    {
        long result = 0;
        int pos = 0, prevPos = 0;
        while((pos = rInput.find(itemToFind, prevPos)) != std::string::npos)
        {
            prevPos = pos + sizeof(itemToFind);
            ++result;
        }

        return result;
    }

    static void eraseStringFromString(std::string& rInput, const std::string& rItemToRemove)
    {
        int pos = 0;
        while((pos = rInput.find(rItemToRemove)) != std::string::npos)
        {
            rInput.erase(pos,rItemToRemove.length());
        }
    }
}

#endif