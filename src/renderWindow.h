

#ifndef DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H
#define DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H


#include "SDL.h"

#include "algorithems/algorithms.h"
#include "createRandomData.h"
#include <iostream>
#include <vector>

class renderWindow {
public:
    renderWindow();

    virtual ~renderWindow();

    void init(const char *title, int xpos, int ypos, int width, int height,
              bool fullscreen);

    void handleEvents();

    void update();

    void render();

    bool running();

    void restart();

    SDL_Window *getWindow() const;

    SDL_Renderer *renderer;
    std::vector<SDL_Event> events;

    static unsigned int s_windowWidth;
    static unsigned int s_windowHeight;

private:
    createRandomData *randData;
    bool m_isRunning;
    SDL_Window *m_window;
    algo::algorithms *currentAlgo;
    algo::algorithms_menu *algoMenu;
};

#endif// DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H
