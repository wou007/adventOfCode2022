#ifndef VECTOR_TOOLS_H
#define VECTOR_TOOLS_H

#include <vector>
#include <array>

namespace vectortools {

    template <class T>
    int CountAppearancesOfItem(const std::vector<T>& rVector, const T& rItem)
    {
        int result = 0;

        for (const T& i : rVector)
        {
            if(i == rItem)
            {
                ++result;
            }
        }

        return result;
    }

    template <class T>
    bool DoesContainItem(const std::vector<T>& rVector, const T& rItem)
    {
        for (const T& i : rVector)
        {
            if(i == rItem)
            {
                return true;
            }
        }

        return false;
    }

    template <class T>
    void RemoveItemOnIndex(std::vector<T>& rVector, int index)
    {
        auto it = rVector.begin();
        for(int i = 0; i < index; ++i)
        {
            ++it;
        }
        rVector.erase(it);
    }

    template <class T>
    void RemoveItemsWithValue(std::vector<T>& rVector, const T& rValue)
    {
        for(auto b = rVector.begin(); b <= rVector.end(); b++)
        {
            if(*b == rValue)
            {
                rVector.erase(b);
            }
        }
    }

    template <class T>
    void RemoveDublicateItems(std::vector<T>& rVector)
    {
        std::vector<T> foundItems;
        for(auto b = rVector.begin(); b <= rVector.end(); b++)
        {
            if(DoesContainItem(foundItems,*b) > 0)
            {
                rVector.erase(b);
            }
            else
            {
                foundItems.push_back(*b);
            }
        }
    }
}

#endif