#include <iostream>
#include <chrono>

#include "day1.h"

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Hello World\n";

    day1::Run();

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "duration: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << std::endl;
}