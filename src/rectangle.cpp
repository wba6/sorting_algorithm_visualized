
#include "rectangle.h"
#include "renderWindow.h"
rectangle::rectangle(int height, int iteration)
    : m_width(10)
{
    /*
     * SLD default cordite system starts at the top left of the screen
     * We have to invert the height and move then down to the bottom of the screen
     * */

    m_rect.w = m_width;
    m_rect.h = (-1 * height);
    m_rect.x = iteration * 15;
    m_rect.y = 0 + (int) renderWindow::s_windowHeight;
}

rectangle::~rectangle() {}
