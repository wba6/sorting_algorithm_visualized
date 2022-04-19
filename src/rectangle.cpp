
#include "rectangle.h"

rectangle::rectangle(const int hieght, int interation)
    : width(20)
{
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 64;
    srcRect.h = 64;
    destRect.w = width;
    destRect.h = hieght;
    destRect.x = interation * 5;
    destRect.y = 0;
}

rectangle::~rectangle() {}
