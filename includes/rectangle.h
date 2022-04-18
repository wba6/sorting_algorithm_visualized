

#ifndef SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#define SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
#include "SDL.h"
class rectangle {
public:
  rectangle(const int hieght, int interation);

  SDL_Rect getDestRect(){return destRect;};
  SDL_Rect getSrcRect(){return srcRect;};

  ~rectangle();

private:
  int width;
  SDL_Rect srcRect, destRect;
};

#endif // SORTING_ALGORITHM_VISUALIZED_RECTANGLE_H
