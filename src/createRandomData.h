

#ifndef SORTING_ALGORITHM_VISUALIZED_CREATERANDOMDATA_H
#define SORTING_ALGORITHM_VISUALIZED_CREATERANDOMDATA_H

#include "SDL.h"
#include "rectangle.h"
#include "sortingAlgorimths.h"
#include <vector>
class createRandomData {
public:
    explicit createRandomData(SDL_Renderer *render);

    void renderRandomData();

    ~createRandomData();

private:
    std::vector<rectangle *> rectangleVec;
    SDL_Renderer *m_rend;
    sortingAlgorimths *m_sorter;
    size_t rectLimit;
};
#endif// SORTING_ALGORITHM_VISUALIZED_CREATERANDOMDATA_H
