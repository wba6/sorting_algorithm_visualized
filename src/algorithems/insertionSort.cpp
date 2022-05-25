
#include "insertionSort.h"
#include "../ObjectRender.h"
#include "../randomNumGen.h"
#include "imgui/imgui.h"

namespace algo
{
    insertionSort::insertionSort()
        : rectLimit(52), sort_speed(50), done(false)
    {
        generateRandNum();
    }
    insertionSort::~insertionSort()
    {
        algorithms::~algorithms();
        for (int i = 0; i < rectangleVec.size(); i++)
        {
            delete rectangleVec.at(i);
            rectangleVec.erase(rectangleVec.begin() + i);
        }
    };


    void insertionSort::OnRender(SDL_Renderer *&m_rend)
    {
        SDL_SetRenderDrawColor(m_rend, 0, 0, 255, 255);
        for (size_t i{0}; i < rectangleVec.size(); i++)
        {
            SDL_RenderFillRect(m_rend, &rectangleVec.at(i)->getDestRect());
        }
        if (!done)
        {
            ObjectRender::catchFrameVisualize(m_rend);

            if (!done)
            {
                beginSort(rectangleVec, 51, m_rend);
            }

            done = true;
            ObjectRender::releaseFrameVisualize(m_rend);
        }
    }
    void insertionSort::beginSort(std::vector<rectangle *> &vector, size_t interations, SDL_Renderer *&m_rend)
    {
        for (size_t i = 0; i < interations; i++)
        {
            for (size_t j{i + 1}; j < vector.size(); j++)
            {
                if (ObjectRender::visualize(vector, j, i, -1, m_rend))
                {
                    done = true;
                    return;
                }
                SDL_Delay(100 - sort_speed);
                if ((-1 * vector.at(i)->getDestRect().h) < (-1 * vector.at(j)->getDestRect().h))
                {
                    std::swap(vector.at(j)->getDestRect().x, vector.at(i)->getDestRect().x);
                    iter_swap(vector.begin() + (int) i, vector.begin() + (int) j);
                }
            }
        }
    }
    void insertionSort::OnImGuiRender()
    {
        ImGui::Text("Insertion sort algorithm");
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
    void insertionSort::Reset()
    {
        for (int i = rectangleVec.size() - 1; i >= 0; --i)
        {
            delete rectangleVec.at(i);
        }
        rectangleVec.clear();
        done = false;
    }
    void insertionSort::generateRandNum()
    {
        Reset();
        randomNumGen numGen;
        for (size_t i{rectLimit}; i > 0; i--)
        {
            int randNum{numGen.getRandomInt(20, 500)};
            auto rect = new rectangle(randNum, (int) i);
            rectangleVec.push_back(rect);
            rect = nullptr;
            delete rect;
        }
    }
}// namespace algo