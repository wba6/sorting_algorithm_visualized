

#ifndef SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#define SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#include "SDL.h"
class rectangle {
public:
    rectangle(int height, int iteration);
    SDL_Rect &getDestRect() { return destRect; };


    ~rectangle();

private:
    int width;
    SDL_Rect destRect{};
};

#endif// SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
