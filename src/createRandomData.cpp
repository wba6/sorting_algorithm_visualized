
#include "createRandomData.h"
#include <random>
createRandomData::createRandomData(SDL_Renderer *render)
    : rend(render), rectLimit(52)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(20, 500);
    for (size_t i{rectLimit}; i > 0; i--)
    {
        int randNum = distribution(generator);
        //TODO: create move constuctor in rectangle.h current mem leak
        rectangle *rect = new rectangle(randNum, (int) i);
        rectangleVec.push_back(rect);
        rect = nullptr;
        delete rect;
    }
}
createRandomData::~createRandomData() = default;


void createRandomData::renderRandomData()
{

    SDL_SetRenderDrawColor(rend, 100, 150, 150, 255);
    for (auto &rect: rectangleVec)
    {
        SDL_RenderFillRect(rend, &rect->getDestRect());
    }
}
