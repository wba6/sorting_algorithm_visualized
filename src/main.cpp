#include "renderWindow.h"

int main(int argv, char **args)
{

    renderWindow window;
    window.init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
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
