//
// Created by william on 5/9/22.
//

#include "quickSort.h"
#include "../ObjectRender.h"
#include "imgui/imgui.h"
#include <random>
namespace algo
{
    quickSort::quickSort()
        : rectLimit(52), sort_speed(0), done(false)
    {
        generateRandNum();
    }
    quickSort::~quickSort()
    {
        algorithms::~algorithms();
        for (int i = 0; i < rectangleVec.size(); i++)
        {
            delete rectangleVec.at(i);
            rectangleVec.erase(rectangleVec.begin() + i);
        }
    };


    void quickSort::OnRender(SDL_Renderer *&m_rend)
    {

        //runs every 32 frames
        if (!done)
        {
            beginSort(rectangleVec, 51, m_rend);
        }

        for (size_t i{0}; i < rectangleVec.size(); i++)
        {
            SDL_SetRenderDrawColor(m_rend, 0, 0, 255, 255);
            SDL_RenderFillRect(m_rend, &rectangleVec.at(i)->getDestRect());
        }
        //beginSort(rectangleVec, 51,m_rend);
    }
    void quickSort::beginSort(std::vector<rectangle *> &vector, size_t interations, SDL_Renderer *&m_rend)
    {
        int n = (int) vector.size();
        quickSortAlgo(vector, 0, n - 1, m_rend);

        done = true;
    }
    int quickSort::partition(std::vector<rectangle *> &vector, int low, int high, SDL_Renderer *&m_rend)
    {
        int pivot = (-1 * vector.at(high)->getDestRect().h);// pivot
        int i = (low - 1);                                  // Index of smaller element and indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            ObjectRender::visualize(vector, j, i, m_rend);
            SDL_Delay(50);
            if ((-1 * vector.at(j)->getDestRect().h) > pivot)
            {
                i++;// increment index of smaller element
                int temp = vector.at(i)->getDestRect().x;
                vector.at(i)->getDestRect().x = vector.at(j)->getDestRect().x;
                vector.at(j)->getDestRect().x = temp;
                iter_swap(vector.begin() + (int) i, vector.begin() + (int) j);
            }
        }
        iter_swap(vector.begin() + (int) i + 1, vector.begin() + (int) high);
        return (i + 1);
    }

    void quickSort::quickSortAlgo(std::vector<rectangle *> &vector, int low, int high, SDL_Renderer *&m_rend)
    {
        if (low < high)
        {
            int pi = partition(vector, low, high, m_rend);

            quickSortAlgo(vector, low, pi - 1, m_rend);
            quickSortAlgo(vector, pi + 1, high, m_rend);
        }
    }

    void quickSort::OnImGuiRender()
    {
        ImGui::Text("Quick sort algorithm");
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
    void quickSort::Reset()
    {
        for (int i = (int) rectangleVec.size() - 1; i >= 0; --i)
        {
            delete rectangleVec.at(i);
        }
        rectangleVec.clear();
        done = false;
    }
    void quickSort::generateRandNum()
    {
        Reset();
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(20, 500);
        for (size_t i{rectLimit}; i > 0; i--)
        {
            int randNum = distribution(generator);
            //TODO: check for mem leak using valgrind
            auto rect = new rectangle(randNum, (int) i);
            rectangleVec.push_back(rect);
            rect = nullptr;
            delete rect;
        }
    }
}// namespace algo