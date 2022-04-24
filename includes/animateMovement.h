

#ifndef SORTING_ALGORITHM_VISUALIZED_ANIMATEMOVEMENT_H
#define SORTING_ALGORITHM_VISUALIZED_ANIMATEMOVEMENT_H


#include "rectangle.h"
#include <vector>
class animateMovement {

    animateMovement() = default;
    void moveTo(std::vector<rectangle *> &vector, size_t currentIteration, size_t swapWidth, unsigned diration);
};


#endif//SORTING_ALGORITHM_VISUALIZED_ANIMATEMOVEMENT_H
