//
// Created by william on 5/9/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_QUICKSORT_H
#define SORTING_ALGORITHM_VISUALIZED_QUICKSORT_H
#include "../rectangle.h"
#include "SDL.h"
#include "algorithms.h"
#include <vector>

namespace algo
{

    class quickSort : public algorithms {
    public:
        quickSort();

        void OnRender(SDL_Renderer *&m_rend) override;
        void OnImGuiRender() override;
        void Reset();
        void generateRandNum() override;
        void beginSort(std::vector<rectangle *> &vector, size_t interations, SDL_Renderer *&m_rend);
        int partition(std::vector<rectangle *> &vector, int start, int end, SDL_Renderer *&m_rend);
        void quickSortAlgo(std::vector<rectangle *> &vector, int low, int high, SDL_Renderer *&m_rend);
        void quickSortTest( std::vector<rectangle *> &vector,int first,int last, SDL_Renderer *&m_rend);
        ~quickSort() override;

    private:
        bool done;
        int sort_speed;
        std::vector<rectangle *> rectangleVec;
        size_t rectLimit;
    };

}// namespace algo

#endif//SORTING_ALGORITHM_VISUALIZED_QUICKSORT_H
