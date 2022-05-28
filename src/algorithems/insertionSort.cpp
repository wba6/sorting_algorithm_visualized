
#include "insertionSort.h"
#include "../ObjectRender.h"
#include "../randomNumGen.h"
#include "imgui/imgui.h"

namespace algo
{
    insertionSort::insertionSort()
        : m_rectLimit(52), m_sort_speed(50), m_done(false)
    {
        generateRandNum();
    }
    insertionSort::~insertionSort()
    {
        algorithms::~algorithms();
        for (int i = 0; i < m_rectangleVec.size(); i++)
        {
            delete m_rectangleVec.at(i);
            m_rectangleVec.erase(m_rectangleVec.begin() + i);
        }
    };


    void insertionSort::OnRender(SDL_Renderer *&m_rend)
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


            m_done = true;
            ObjectRender::releaseFrameVisualize(m_rend);
        }
    }
    void insertionSort::beginSort(std::vector<rectangle *> &vector, size_t iterations, SDL_Renderer *&m_rend)
    {
        for (size_t i = 0; i < iterations; i++)
        {
            for (size_t j{i + 1}; j < vector.size(); j++)
            {
                if (ObjectRender::visualize(vector, static_cast<int>(j), static_cast<int>(i), -1, m_rend))
                {
                    m_done = true;
                    return;
                }
                SDL_Delay(100 - m_sort_speed);
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
        ImGui::SliderInt("Speed", &m_sort_speed, 0, 100);
        ImGui::Text("Red is the current index \nbeing compared \n \n");
        ImGui::Text("Green is the current index \nthat red is being\n compared to \n\n");
        ImGui::Text("If Red>green they are swapped");
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
    void insertionSort::Reset()
    {
        for (int i = static_cast<int>(m_rectangleVec.size() - 1); i >= 0; --i)
        {
            delete m_rectangleVec.at(i);
        }
        m_rectangleVec.clear();
        m_done = false;
    }
    void insertionSort::generateRandNum()
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