

#ifndef SORTING_ALGORITHM_VISUALIZED_INSERTIONSORT_H
#define SORTING_ALGORITHM_VISUALIZED_INSERTIONSORT_H

#include "../rectangle.h"
#include "../sortingAlgorimths.h"
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
        void beginSort(std::vector<rectangle *> &vector, size_t interations);

        ~insertionSort() override;

    private:
        int sort_speed;
        std::vector<rectangle *> rectangleVec;
        size_t rectLimit;
    };
}//namespace algo

#endif// SORTING_ALGORITHM_VISUALIZED_INSERTIONSORT_H
