//
// Created by william on 5/9/22.
//

#include "quickSort.h"
#include "../ObjectRender.h"
#include "imgui/imgui.h"
#include <chrono>
#include <random>
namespace algo
{
    quickSort::quickSort()
        : rectLimit(52), sort_speed(50), done(false)
    {
        generateRandNum();
    }
    quickSort::~quickSort()
    {
        algorithms::~algorithms();
        for (int i = (int) rectangleVec.size() - 1; i >= 0; --i)
        {
            delete rectangleVec.at(i);
        }
        rectangleVec.clear();
    };


    void quickSort::OnRender(SDL_Renderer *&m_rend)
    {

        SDL_SetRenderDrawColor(m_rend, 0, 0, 255, 255);
        for (size_t i{0}; i < rectangleVec.size(); i++)
        {
            SDL_RenderFillRect(m_rend, &rectangleVec.at(i)->getDestRect());
        }
        if (!done)
        {
            ObjectRender::catchFrameVisualize(m_rend);

            beginSort(rectangleVec, 51, m_rend);

            ObjectRender::releaseFrameVisualize(m_rend);
        }
    }
    void quickSort::beginSort(std::vector<rectangle *> &vector, size_t interations, SDL_Renderer *&m_rend)
    {
        quickSortAlgo(vector, 0, (int) vector.size() - 1, m_rend);
        done = true;
    }
    int quickSort::partition(std::vector<rectangle *> &vector, int low, int high, SDL_Renderer *&m_rend)
    {
        int pivot = -1 * vector.at(high)->getDestRect().h;// pivot
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            //render objects and check if the user has stopped the algorithm
            if (ObjectRender::visualize(vector, j, i, high, m_rend))
            {
                done = true;
                break;
            }
            //controls speed of sort
            SDL_Delay(100 - sort_speed);
            // If current element is smaller than the pivot
            if ((-1 * vector.at(j)->getDestRect().h) >= pivot)
            {
                i++;
                std::swap(vector.at(j)->getDestRect().x, vector.at(i)->getDestRect().x);
                std::iter_swap(vector.begin() + (int) i, vector.begin() + (int) j);
            }
        }
        if (!done)
        {
            std::swap(vector.at(i + 1)->getDestRect().x, vector.at(high)->getDestRect().x);
            iter_swap(vector.begin() + (int) i + 1, vector.begin() + (int) high);
        }
        return (i + 1);
    }

    void quickSort::quickSortAlgo(std::vector<rectangle *> &vector, int low, int high, SDL_Renderer *&m_rend)
    {
        if (low < high)
        {

            int pivot = partition(vector, low, high, m_rend);

            if (!done)
            {

                quickSortAlgo(vector, low, pivot - 1, m_rend);
            }
            if (!done)
            {

                quickSortAlgo(vector, pivot + 1, high, m_rend);
            }
        }
    }

    void quickSort::OnImGuiRender()
    {
        ImGui::Text("Quick sort algorithm");
        ImGui::SliderInt("Speed", &sort_speed, 0, 100);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        if (done)
        {
            if (ImGui::Button("Reset"))
            {
                generateRandNum();
                done = false;
            }
        }
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
        unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> distribution(20, 500);
        for (size_t i{rectLimit}; i > 0; i--)
        {
            int randNum = distribution(generator);
            auto rect = new rectangle(randNum, (int) i);
            rectangleVec.push_back(rect);
            rect = nullptr;
            delete rect;
        }
    }
}// namespace algo