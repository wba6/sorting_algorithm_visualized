
#include "createRandomData.h"
#include "sortingAlgorimths.h"
#include <random>
createRandomData::createRandomData(SDL_Renderer *render)
    : m_rend(render), rectLimit(52)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(20, 500);
    for (size_t i{rectLimit}; i > 0; i--)
    {
        int randNum = distribution(generator);
        //TODO: check for mem leak using valgrind
        auto *rect = new rectangle(randNum, (int) i);
        rectangleVec.push_back(rect);
        rect = nullptr;
        delete rect;
    }
    m_sorter = new sortingAlgorimths;
}
createRandomData::~createRandomData()
{
    for (int i = 0; i < rectangleVec.size(); ++i)
    {
        delete rectangleVec.at(i);
        rectangleVec.erase(rectangleVec.begin() + i);
    }
    delete m_sorter;
};


void createRandomData::renderRandomData()
{
    static int s_counter;
    SDL_SetRenderDrawColor(m_rend, 100, 150, 150, 255);
    //runs every 32 frames
    if (s_counter % 32)
    {
        m_sorter->beginSort(rectangleVec, s_counter / 6);
        s_counter++;
    }
    else
    {
        s_counter++;
    }
    for (size_t i{0}; i < rectangleVec.size(); i++)
    {
        SDL_RenderFillRect(m_rend, &rectangleVec.at(i)->getDestRect());
    }
}
