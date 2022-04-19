
#include "createRandomData.h"
#include <random>
createRandomData::createRandomData(SDL_Renderer **render)
    : rend(render), rectLimit(80)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(20, 500);
    for (size_t i{rectLimit}; i > 0; i--)
    {
        int randNum = distribution(generator);
        //TODO: create move constuctor in rectangle.h
        rectangle *rect = new rectangle(randNum, (int) i);
        rectangleVec.push_back(rect);
    }
}
createRandomData::~createRandomData() = default;


void createRandomData::renderRandomData()
{
    for (auto &rect: rectangleVec)
    {
        SDL_RenderFillRect((*rend), &rect->getDestRect());
    }
}
