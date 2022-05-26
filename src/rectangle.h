

#ifndef SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#define SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#include "SDL.h"
class rectangle {
public:
    rectangle(int height, int iteration);
    SDL_Rect &getDestRect() { return m_rect; };


    ~rectangle();

private:
    int m_width;
    SDL_Rect m_rect{};
};

#endif// SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
