
#include "rectangle.h"

rectangle::rectangle(const int hieght, int interation)
    : width(10)
{
    destRect.w = width;
    destRect.h = hieght;
    destRect.x = interation * 15;
    destRect.y = 0;
}

rectangle::~rectangle() {}
