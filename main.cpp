#include <iostream>
#include <chrono>
#include <functional>

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"

void RunDay(std::function<void()> f, int runs = 1)
{
    std::streambuf* orig_buf = std::cout.rdbuf();

    if(runs > 1) //Disable output when multiple runs are done
    {
        std::cout.rdbuf(NULL);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < runs; ++i)
    {
        f();
    }

    auto stop = std::chrono::high_resolution_clock::now();

    if(runs > 1)
    {
        std::cout.rdbuf(orig_buf);
    }

    std::cout << "duration: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / runs << " usec average over " << runs << " runs\n" << std::endl;
}

int main()
{
    std::cout << "Advent of code 2022\n\n";

    RunDay([](){day1::Run("input/day1.txt");});
    RunDay([](){day2::Run("input/day2.txt");});
    RunDay([](){day3::Run("input/day3.txt");});
    RunDay([](){day4::Run("input/day4.txt");});
}