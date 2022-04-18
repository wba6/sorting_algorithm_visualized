

#include "renderWindow.h"

renderWindow::renderWindow() {}

renderWindow::~renderWindow() {

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "renderWindow cleaned" << std::endl;
}

void renderWindow::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags{0};
  // checks if fullscreen is true
  flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
  // checks to make sure that the system is initialized correctly before making
  // a window
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "subsystem running" << std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    // check if window was made successfully
    if (window) {
      std::cout << "window created" << std::endl;
    }

    // create render
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      std::cout << "Render created" << std::endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

}

void renderWindow::handleEvents() {
  // gets events
  events.clear();
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    }
    events.push_back(event);
  }
}

void renderWindow::update() {

}



void renderWindow::render() {
  // clear render buffer
  SDL_RenderClear(renderer);

  // render new stuff
  SDL_RenderPresent(renderer);
}

bool renderWindow::running() { return isRunning; }

SDL_Window *renderWindow::getWindow() const {
  return window;
}



void renderWindow::restart() {
  int numKeys;
  const Uint8 *keys = SDL_GetKeyboardState(&numKeys);
  if (keys[SDL_SCANCODE_R]) {

  }
}
