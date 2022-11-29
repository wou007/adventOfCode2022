#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "fileio.h"

namespace matrix
{
    class Coordinate
    {
    public:
        Coordinate(int x,int y) : m_x(x),m_y(y) {};
        virtual ~Coordinate() = default;

        int GetX() {return m_x;}
        int GetY() {return m_y;}
        void SetX(int x) {m_x = x;}
        void SetY(int y) {m_y = y;}
    private:
        int m_x;
        int m_y;
    };

    class Matrix
    {
    public:
        Matrix() = default;
        virtual ~Matrix() = default;

        int GetHeight() const
        {
            return m_matrix.size();
        }
        int GetWidth() const
        {
            return m_matrix[0].size();
        }

        void FillFromFile(const char* pFilePath)
        {
            m_matrix.clear();
            std::vector<std::string> file;
            fileio::fileToStringVector(pFilePath,file);
            for(int i = file.size() - 1; i >=0; --i)
            {
                std::vector<char> temp;
                for(char c : file[i])
                {
                    temp.push_back(c);
                }
                m_matrix.push_back(temp);
            }
        }
        void Print() const
        {
            for(int i = m_matrix.size() - 1; i >=0; --i)
            {
                for(char c : m_matrix[i])
                {
                    std::cout << c;
                }
                std::cout << std::endl;
            }
        }
        char GetValueOfPoint(int x, int y) const
        {
            return m_matrix[y][x];
        }
        void SetValueOfPoint(int x, int y, char value)
        {
            m_matrix[y][x] = value;
        }
        int GetOccurencesOfField(char t, std::vector<Coordinate>* pList = nullptr) const
        {
            int result = 0;
            if(pList != nullptr)
            {
                pList->clear();
            }

            for(int y = m_matrix.size() - 1; y >= 0 ; --y)
            {
                for(int x = 0; x < m_matrix[y].size(); ++x)
                {
                    if(GetValueOfPoint(x,y) == t)
                    {
                        ++result;
                        if(pList != nullptr)
                        {
                            pList->push_back(Coordinate(x,y));
                        }
                    }
                }
            }
            return result;
        }
        std::vector<Coordinate> GetNeigborsOf(int x, int y, bool includeDiagonal = true) const
        {
            std::vector<Coordinate> results;

            if(includeDiagonal)
            {
                for(int a = y - 1; a <= y + 1; ++a)
                {
                    if((a >= 0) && (a < m_matrix.size()))
                    {
                        for(int b = x - 1; b <= x + 1; ++b)
                        {
                            if((b >= 0) && (b < m_matrix[b].size()) && ((a != y) || (b != x)))
                            {
                                results.push_back(Coordinate(b,a));
                            }
                        }
                    }
                }
            }
            else
            {
                if(x > 0)
                {
                    results.push_back(Coordinate(x - 1,y));
                }
                if(y > 0)
                {
                    results.push_back(Coordinate(x,y - 1));
                }
                if(x < (m_matrix[y].size() - 1))
                {
                    results.push_back(Coordinate(x + 1,y));
                }
                if(y < (m_matrix.size() - 1))
                {
                    results.push_back(Coordinate(x,y + 1));
                }
            }

            return results;
        }
        int GetOccurencesOfFieldInSelection(char t, const std::vector<Coordinate>& rSelection, std::vector<Coordinate>* pList = nullptr) const
        {
            int result = 0;
            if(pList != nullptr)
            {
                pList->clear();
            }

            for(const Coordinate& rC : rSelection)
            {
                if(GetValueOfPoint(rC) == t)
                {
                    ++result;
                    if(pList != nullptr)
                    {
                        pList->push_back(rC);
                    }
                }
            }

            return result;
        }

        char GetValueOfPoint(Coordinate c) const
        {
            return GetValueOfPoint(c.GetX(), c.GetY());
        }
        void SetValueOfPoint(Coordinate c, char value)
        {
            SetValueOfPoint(c.GetX(), c.GetY(), value);
        }
        std::vector<Coordinate> GetNeigborsOf(Coordinate c) const
        {
            return GetNeigborsOf(c.GetX(), c.GetY());
        }
    private:
        std::vector<std::vector<char>> m_matrix;
    };

    

    
}

#endif