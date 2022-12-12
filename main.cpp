#include <iostream>
#include <chrono>
#include <functional>

#include "day01.h"
#include "day02.h"
#include "day03.h"
#include "day04.h"
#include "day05.h"
#include "day06.h"
#include "day07.h"
#include "day08.h"
#include "day09.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"

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
    RunDay([](){

        RunDay([](){day1::Run("input/day01.txt");});
        RunDay([](){day2::Run("input/day02.txt");});
        RunDay([](){day3::Run("input/day03.txt");});
        RunDay([](){day4::Run("input/day04.txt");});
        RunDay([](){day5::Run("input/day05.txt");});
        RunDay([](){day6::Run("input/day06.txt");});
        RunDay([](){day7::Run("input/day07.txt");});
        RunDay([](){day8::Run("input/day08.txt");});
        RunDay([](){day9::Run("input/day09.txt");});
        RunDay([](){day10::Run("input/day10.txt");});
        RunDay([](){day11::Run("input/day11.txt");});
        RunDay([](){day12::Run("input/day12.txt");});
    });
} 