#ifndef BITTWIDDLING_H_
#define BITTWIDDLING_H_

#include <stdint.h>

namespace bittwiddling
{
//Source: https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
static uint32_t CountBitsSet(uint32_t v)
{
    unsigned int c; // c accumulates the total bits set in v
    for (c = 0; v; c++)
    {
        v &= v - 1; // clear the least significant bit set
    }
    return c;
}
}

#endif