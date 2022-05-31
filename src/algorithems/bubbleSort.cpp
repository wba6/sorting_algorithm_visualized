//
// Created by William Aey on 5/30/2022.
//

#include "bubbleSort.h"
#include "../ObjectRender.h"
#include "../randomNumGen.h"
#include "imgui/imgui.h"

namespace algo
{
    bubbleSort::bubbleSort()
        : m_rectLimit(52), m_sort_speed(50), m_done(false)
    {
        generateRandNum();
    }
    bubbleSort::~bubbleSort()
    {
        algorithms::~algorithms();
        for (int i = (int) m_rectangleVec.size() - 1; i >= 0; --i)
        {
            delete m_rectangleVec.at(i);
        }
        m_rectangleVec.clear();
    };


    void bubbleSort::OnRender(SDL_Renderer *&m_rend)
    {

        SDL_SetRenderDrawColor(m_rend, 0, 0, 255, 255);
        for (size_t i{0}; i < m_rectangleVec.size(); i++)
        {
            SDL_RenderFillRect(m_rend, &m_rectangleVec.at(i)->getDestRect());
        }
        if (!m_done)
        {
            ObjectRender::catchFrameVisualize(m_rend);

            beginSort(m_rectangleVec, 51, m_rend);

            ObjectRender::releaseFrameVisualize(m_rend);
        }
    }
    void bubbleSort::beginSort(std::vector<rectangle *> &vector, size_t iterations, SDL_Renderer *&m_rend)
    {
        int i, j;
        bool swapped;
        for (i = 0; i < vector.size() - 1; i++)
        {
            swapped = false;
            for (j = 0; j < (vector.size() - i - 1); j++)
            {
                if (ObjectRender::visualize(vector, j, i, -1, m_rend))
                {
                    m_done = true;
                    break;
                }
                SDL_Delay(100 - m_sort_speed);
                if (vector.at(j)->getDestRect().h >= vector.at(j + 1)->getDestRect().h)
                {
                    //std::swap(vector.at(j), vector.at(j+1));
                    std::swap(vector.at(j)->getDestRect().x, vector.at(j + 1)->getDestRect().x);
                    std::iter_swap(vector.begin() + (int) j, vector.begin() + ((int) j + 1));
                    swapped = true;
                }
            }

            // IF no two elements were swapped by inner loop, then break
            if (!swapped)
                break;
        }
        m_done = true;
    }


    void bubbleSort::OnImGuiRender()
    {
        //TODO: add description text
        ImGui::Text("bubble sort algorithm");
        ImGui::SliderInt("Speed", &m_sort_speed, 0, 100);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        if (m_done)
        {
            if (ImGui::Button("Reset"))
            {
                generateRandNum();
                m_done = false;
            }
        }
    }
    void bubbleSort::Reset()
    {
        for (int i = (int) m_rectangleVec.size() - 1; i >= 0; --i)
        {
            delete m_rectangleVec.at(i);
        }
        m_rectangleVec.clear();
        m_done = false;
    }
    void bubbleSort::generateRandNum()
    {
        Reset();
        randomNumGen numGen;
        for (size_t i{m_rectLimit}; i > 0; i--)
        {
            int randNum{numGen.getRandomInt(20, 500)};
            auto rect = new rectangle(randNum, (int) i);
            m_rectangleVec.push_back(rect);
            rect = nullptr;
            delete rect;
        }
    }
}// namespace algo