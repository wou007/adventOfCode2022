#ifndef VECTOR_TOOLS_H_
#define VECTOR_TOOLS_H_

#include <vector>
#include <array>

namespace vectortools {

    template <class T>
    static int CountAppearancesOfItem(const std::vector<T>& rVector, const T& rItem)
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
    static bool DoesContainItem(const std::vector<T>& rVector, const T& rItem)
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
    static bool DoVectorsContainSameItems(const std::vector<T>& rA, const std::vector<T>& rB)
    {
        bool result = true;

        for (const T& i : rA)
        {
            result = DoesContainItem(rB,i);
            if(!result)
            {
                break;
            }
        }

        return result;
    }

    template <class T>
    static void RemoveItemOnIndex(std::vector<T>& rVector, int index)
    {
        auto it = rVector.begin();
        for(int i = 0; i < index; ++i)
        {
            ++it;
        }
        rVector.erase(it);
    }

    template <class T>
    static void RemoveItemsWithValue(std::vector<T>& rVector, const T& rValue)
    {
        for(auto b = rVector.begin(); b < rVector.end(); ++b)
        {
            if(*b == rValue)
            {
                rVector.erase(b);
                --b;
            }
        }
    }

    template <class T>
    static void RemoveDuplicateItems(std::vector<T>& rVector)
    {
        std::vector<T> foundItems;
        for(auto b = rVector.begin(); b < rVector.end(); ++b)
        {
            if(DoesContainItem(foundItems,*b) > 0)
            {
                rVector.erase(b);
                --b;
            }
            else
            {
                foundItems.push_back(*b);
            }
        }
    }

    template <class T>
    static void Print(const std::vector<T>& rVector)
    {
        for(int i = 0; i < rVector.size(); ++i)
        {
            if(i < (rVector.size() - 1))
            {
                std::cout << rVector[i] << ',';
            }
            else
            {
                std::cout << rVector[i] << '\n';
            }
        }
    }
}

#endif