
#include "rectangle.h"
#include "renderWindow.h"
rectangle::rectangle(int height, int iteration)
    : width(10)
{
    /*
     * SLD default cordite system starts at the top left of the screen
     * We have to invert the height and move then down to the bottom of the screen
     * */

    destRect.w = width;
    destRect.h = (-1 * height);
    destRect.x = iteration * 15;
    destRect.y = 0 + (int) renderWindow::s_windowHeight;
}

rectangle::~rectangle() {}
