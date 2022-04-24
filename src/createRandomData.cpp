
#include "createRandomData.h"
#include <random>
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
    sortingAlgorimths sorter;
    sorter.beginSort(rectangleVec);

}
createRandomData::~createRandomData() = default;


void createRandomData::renderRandomData()
{

    SDL_SetRenderDrawColor(rend, 100, 150, 150, 255);

    for(size_t i{0};i<rectangleVec.size();i++)
    {
        SDL_RenderFillRect(rend,&rectangleVec.at(i)->getDestRect());
    }
}
