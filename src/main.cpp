#include "renderWindow.h"

int main(int, char **)
{

    renderWindow window;
    window.init("Sorting Algorithms", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600,
                false);

    while (window.running())
    {
        window.handleEvents();
        window.render();
    }

    return 0;
}
