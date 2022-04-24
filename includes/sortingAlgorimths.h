//
// Created by william on 4/23/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_SORTINGALGORIMTHS_H
#define SORTING_ALGORITHM_VISUALIZED_SORTINGALGORIMTHS_H


#include "rectangle.h"
#include <vector>
class sortingAlgorimths {
public:
    sortingAlgorimths() = default;

    ~sortingAlgorimths() = default;

    void beginSort(std::vector<rectangle*> &vector, size_t  interations);
    static size_t counter;
private:
};


#endif//SORTING_ALGORITHM_VISUALIZED_SORTINGALGORIMTHS_H
