

#ifndef SORTING_ALGORITHM_VISUALIZED_CREATERANDOMDATA_H
#define SORTING_ALGORITHM_VISUALIZED_CREATERANDOMDATA_H

#include <vector>
#include "SDL.h"
#include "rectangle.h"
class createRandomData {
public:
    explicit createRandomData(SDL_Renderer *render);

    void renderRandomData();

    ~createRandomData();

private:
    std::vector<rectangle *> rectangleVec;
    SDL_Renderer *rend;
    size_t rectLimit;
};
#endif// SORTING_ALGORITHM_VISUALIZED_CREATERANDOMDATA_H