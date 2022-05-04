

#include "renderWindow.h"

unsigned int renderWindow::s_windowWidth = 0;
unsigned int renderWindow::s_windowHeight = 0;
renderWindow::renderWindow() : randData(nullptr) {}

renderWindow::~renderWindow()
{

    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "renderWindow cleaned" << std::endl;
}

void renderWindow::init(const char *title, int xpos, int ypos, int width, int height,
                        bool fullscreen)
{
    s_windowHeight = height;
    s_windowWidth = width;
    int flags{0};
    // checks if fullscreen is true
    flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
    // checks to make sure that the system is initialized correctly before making
    // a m_window
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "subsystem running" << std::endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        // check if m_window was made successfully
        if (m_window)
        {
            std::cout << "m_window created" << std::endl;
        }

        // create render
        renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Render created" << std::endl;
        }

        m_isRunning = true;
    }
    else
    {
        m_isRunning = false;
    }
    randData = new createRandomData(renderer);
}

void renderWindow::handleEvents()
{
    // gets events
    events.clear();
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_isRunning = false;
                break;
        }
        events.push_back(event);
    }
}

void renderWindow::update()
{
}


void renderWindow::render()
{
    // clear render buffer
    SDL_RenderClear(renderer);

    randData->renderRandomData();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // render new stuff
    SDL_RenderPresent(renderer);
}

bool renderWindow::running() { return m_isRunning; }

SDL_Window *renderWindow::getWindow() const
{
    return m_window;
}


void renderWindow::restart()
{
    int numKeys;
    const Uint8 *keys = SDL_GetKeyboardState(&numKeys);
    if (keys[SDL_SCANCODE_R])
    {
    }
}
