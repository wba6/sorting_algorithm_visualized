
#include "insertionSort.h"
#include "../ObjectRender.h"
#include "../sortingAlgorimths.h"
#include "imgui/imgui.h"
#include <iostream>
#include <random>
namespace algo
{
    insertionSort::insertionSort()
        : rectLimit(52), sort_speed(0),done(false)
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
        SDL_SetRenderDrawColor(m_rend,0,0,255,255);
        for (size_t i{0}; i < rectangleVec.size(); i++)
        {
            SDL_RenderFillRect(m_rend, &rectangleVec.at(i)->getDestRect());
        }
        ObjectRender::catchFrameVisualize(m_rend);

        if(!done){
            beginSort(rectangleVec,  51, m_rend);
        }

        done = true;
        ObjectRender::releaseFrameVisualize(m_rend);
    }
    void insertionSort::beginSort(std::vector<rectangle *> &vector, size_t interations, SDL_Renderer *&m_rend)
    {
        for (size_t i = 0; i < interations; i++)
        {
            for (size_t j{i + 1}; j < 52; j++)
            {
                if(ObjectRender::visualize(vector, j,i, m_rend)){
                    done = true;
                    return;
                }
                SDL_Delay(50);
                if ((-1 * vector.at(i)->getDestRect().h) < (-1 * vector.at(j)->getDestRect().h))
                {
                    int temp = vector.at(i)->getDestRect().x;
                    vector.at(i)->getDestRect().x = vector.at(j)->getDestRect().x;
                    vector.at(j)->getDestRect().x = temp;
                    iter_swap(vector.begin() + (int) i, vector.begin() + (int) j);
                }
            }
        }


        for (size_t i{0}; i < vector.size(); i++)
        {
            std::cout << "sorted numbers :" << vector.at(i)->getDestRect().x / 15 << " at " << vector.at(i)->getDestRect().h << std::endl;
        }
    }
    void insertionSort::OnImGuiRender()
    {
        ImGui::Text("Insertion sort algorithm");
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
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