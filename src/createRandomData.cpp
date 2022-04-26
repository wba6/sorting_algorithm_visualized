
#include <random>
#include "createRandomData.h"
#include "sortingAlgorimths.h"
createRandomData::createRandomData(SDL_Renderer *render)
    : rend(render), rectLimit(52)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(20, 500);
    for (size_t i{rectLimit}; i > 0; i--)
    {
        int randNum = distribution(generator);
        //TODO: check for mem leak using valgrind
        rectangle *rect = new rectangle(randNum, (int) i);
        rectangleVec.push_back(rect);
        rect = nullptr;
        delete rect;
    }
    sortingAlgorimths *sorter = new sortingAlgorimths;
}
createRandomData::~createRandomData() {
    for (int i = 0; i < rectangleVec.size(); ++i)
    {
        delete rectangleVec.at(i);
        rectangleVec.erase(rectangleVec.begin() + i);
    }
    delete sorter;
};


void createRandomData::renderRandomData()
{
    static int counter;
    SDL_SetRenderDrawColor(rend, 100, 150, 150, 255);
    if (counter % 32)
    {
        sorter->beginSort(rectangleVec, counter / 6);
        counter++;
    }
    else
    {
        counter++;
    }
    for (size_t i{0}; i < rectangleVec.size(); i++)
    {
        SDL_RenderFillRect(rend, &rectangleVec.at(i)->getDestRect());
    }
}
