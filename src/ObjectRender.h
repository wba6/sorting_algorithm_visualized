//
// Created by william on 5/9/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
#define SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
#include "SDL.h"
#include "rectangle.h"
#include <vector>
class ObjectRender {
    public:
    static void visualize(std::vector<rectangle*> &rects, int compareIndex, int swapIndex, SDL_Renderer*& renderer)
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);


        for (size_t i{0}; i < rects.size(); i++)
        {
            if(i == compareIndex){
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }else if(i == swapIndex)
            {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            }else{
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            SDL_RenderFillRect(renderer, &rects.at(i)->getDestRect());

        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        SDL_RenderPresent(renderer);

    }
private:
    ObjectRender() = delete;
    ~ObjectRender() = delete;


};
#endif//SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
