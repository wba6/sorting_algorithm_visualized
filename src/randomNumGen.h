

#ifndef SORTING_ALGORITHM_VISUALIZED_RANDOMNUMGEN_H
#define SORTING_ALGORITHM_VISUALIZED_RANDOMNUMGEN_H
#include <random>
class randomNumGen {
public:
    explicit randomNumGen();

    int getRandomInt(int min, int max);

private:
    unsigned m_seed;
    std::default_random_engine m_generator;
};
#endif//SORTING_ALGORITHM_VISUALIZED_RANDOMNUMGEN_H
