#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include "fileio.h"

//0,0 is top left!!!

namespace matrix
{
    class Coordinate
    {
    public:
        inline bool operator==(const Coordinate& rhs) const { return (m_x == rhs.m_x) && (m_y == rhs.m_y);  }

        Coordinate(int x,int y) : m_x(x),m_y(y) {};
        Coordinate() : m_x(0),m_y(0) {};
        virtual ~Coordinate() = default;

        int GetX() {return m_x;}
        int GetY() {return m_y;}
        void SetX(int x) {m_x = x;}
        void SetY(int y) {m_y = y;}
    private:
        int m_x;
        int m_y;
    };

    template <class T>
    class Matrix
    {
    public:
        Matrix() = default;
        Matrix(int width, int height, T defaultValue)
        {
            for(int i = 0; i < height; ++i)
            {
                std::vector<T> temp = std::vector<T>(width,defaultValue);
                m_matrix.push_back(temp);
            }
        }

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
            for(int i = 0; i < file.size(); ++i)
            {
                std::vector<T> temp;
                for(T c : file[i])
                {
                    temp.push_back(c);
                }
                m_matrix.push_back(temp);
            }
        }

        void Print() const
        {
            for(int i = 0; i < m_matrix.size(); ++i)
            {
                for(T c : m_matrix[i])
                {
                    std::cout << c;
                }
                std::cout << std::endl;
            }
        }

        T GetValueOfPoint(int x, int y) const
        {
            return m_matrix[y][x];
        }

        void SetValueOfPoint(int x, int y, T value)
        {
            m_matrix[y][x] = value;
        }

        int GetOccurencesOfField(T t, std::vector<Coordinate>* pList = nullptr) const
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

        int GetOccurencesOfFieldInSelection(T t, const std::vector<Coordinate>& rSelection, std::vector<Coordinate>* pList = nullptr) const
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

        void IncreaseSizeInAllDirections(T defaultValue)
        {
            std::vector<std::vector<T>> newVector;
            std::vector<T> emptyLine(m_matrix.size() + 2,defaultValue);
            newVector.push_back(emptyLine);

            for(const std::vector<T>& rL : m_matrix)
            {
                std::vector<T> newLine;
                newLine.push_back(defaultValue);
                for(T c : rL)
                {
                    newLine.push_back(c);
                }
                newLine.push_back(defaultValue);
                newVector.push_back(newLine);
            }

            newVector.push_back(emptyLine);

            m_matrix = newVector;
        }



        T GetValueOfPoint(Coordinate c) const
        {
            return GetValueOfPoint(c.GetX(), c.GetY());
        }

        void SetValueOfPoint(Coordinate c, T value)
        {
            SetValueOfPoint(c.GetX(), c.GetY(), value);
        }

        std::vector<Coordinate> GetNeigborsOf(Coordinate c,bool includeDiagonal = true) const
        {
            return GetNeigborsOf(c.GetX(), c.GetY(),includeDiagonal);
        }

    private:
        std::vector<std::vector<T>> m_matrix;
    };

    

    
}

#endif