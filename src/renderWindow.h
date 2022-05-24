

#ifndef DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H
#define DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H


#include "SDL.h"
#include <iostream>
#include <vector>

class renderWindow {
public:
    renderWindow();

    virtual ~renderWindow();

    void init(const char *title, int xpos, int ypos, int width, int height,
              bool fullscreen);

    static void handleEvents();

    void render();

    bool running() const;


    SDL_Window *getWindow() const;

    SDL_Renderer *renderer;

    static unsigned int s_windowWidth;
    static unsigned int s_windowHeight;

    bool m_isRunning;

private:
    SDL_Window *m_window;
};

#endif// DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H
