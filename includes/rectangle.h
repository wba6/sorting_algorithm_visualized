

#ifndef SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#define SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#include "SDL.h"
class rectangle {
public:
    rectangle(const int hieght, int interation);

    SDL_Rect &getDestRect() { return destRect; };

    ~rectangle();

private:
    int width;
    SDL_Rect destRect;
};

#endif // SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
