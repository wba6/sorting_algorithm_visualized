

#ifndef DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H
#define DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H


#include <iostream>
#include <vector>
#include "SDL.h"
#include "createRandomData.h"

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

private:
    createRandomData randData;
    bool isRunning;
    SDL_Window *window;
};

#endif // DATA_STRUCTURES_VISUALIZED_RENDERWINDOW_H
