#include <iostream>
#include <chrono>
#include <functional>

#include "day1.h"
#include "day2.h"

void RunDay(std::function<void()> f, int runs = 1)
{
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < runs; ++i)
    {
        f();
    }

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "duration: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / runs << " usec average over " << runs << " runs\n" << std::endl;
}

int main()
{
    std::cout << "Advent of code 2022\n\n";

    RunDay([](){day1::Run("input/day1.txt");},1);
    RunDay([](){day2::Run("input/day2.txt");},1);
}