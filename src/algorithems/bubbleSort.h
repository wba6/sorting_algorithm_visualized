//
// Created by William Aey on 5/30/2022.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_BUBBLESORT_H
#define SORTING_ALGORITHM_VISUALIZED_BUBBLESORT_H

#include "../rectangle.h"
#include "SDL.h"
#include "algorithms.h"
#include <vector>

namespace algo
{

    class bubbleSort : public algorithms {
    public:
        bubbleSort();

        void OnRender(SDL_Renderer *&m_rend) override;
        void OnImGuiRender() override;
        void Reset();
        void generateRandNum() override;
        void beginSort(std::vector<rectangle *> &vector, size_t iterations, SDL_Renderer *&m_rend);
        ~bubbleSort() override;

    private:
        bool m_done;
        int m_sort_speed;
        std::vector<rectangle *> m_rectangleVec;
        size_t m_rectLimit;
    };

}// namespace algo

#endif//SORTING_ALGORITHM_VISUALIZED_BUBBLESORT_H
