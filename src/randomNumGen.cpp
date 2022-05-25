//
// Created by william on 5/25/22.
//

#include "randomNumGen.h"
#include <chrono>
#include <random>
randomNumGen::randomNumGen()
    : m_seed(std::chrono::steady_clock::now().time_since_epoch().count()), m_generator(m_seed)
{
}

int randomNumGen::getRandomInt(int min, int max)
{
    if (min >= max)
    {
        return min;
    }

    //TODO: update this function for efficiency
    std::uniform_int_distribution<int> distribution(min, max);


    return distribution(m_generator);
}
