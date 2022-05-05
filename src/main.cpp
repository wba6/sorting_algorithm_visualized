#include "renderWindow.h"

int main(int, char**)
{

    renderWindow window;
    window.init("m_window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                false);

    while (window.running())
    {
        // amount of ticks from when sdl was init
        window.handleEvents();
        window.update();
        window.render();
    }

    return 0;
}
