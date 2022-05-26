

#ifndef SORTING_ALGORITHM_VISUALIZED_INSERTIONSORT_H
#define SORTING_ALGORITHM_VISUALIZED_INSERTIONSORT_H

#include "../rectangle.h"
#include "SDL.h"
#include "algorithms.h"
#include <vector>
namespace algo
{
    class insertionSort : public algorithms {
    public:
        insertionSort();

        void OnRender(SDL_Renderer *&m_rend) override;
        void OnImGuiRender() override;
        void Reset();
        void generateRandNum() override;
        void beginSort(std::vector<rectangle *> &vector, size_t iterations, SDL_Renderer *&m_rend);

        ~insertionSort() override;

    private:
        int m_sort_speed;
        std::vector<rectangle *> m_rectangleVec;
        size_t m_rectLimit;
        bool m_done;
    };
}//namespace algo

#endif// SORTING_ALGORITHM_VISUALIZED_INSERTIONSORT_H
