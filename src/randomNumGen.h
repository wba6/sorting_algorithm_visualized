//
// Created by william on 5/25/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_RANDOMNUMGEN_H
#define SORTING_ALGORITHM_VISUALIZED_RANDOMNUMGEN_H
#include <random>
class randomNumGen {
public:
    explicit randomNumGen();

    int getRandomInt(int min, int max);
private:
    void setMinMax(int min, int max);
    unsigned m_seed;
    std::default_random_engine m_generator;
    int m_min, m_max;
};
#endif//SORTING_ALGORITHM_VISUALIZED_RANDOMNUMGEN_H
