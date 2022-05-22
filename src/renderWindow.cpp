

#include "renderWindow.h"
#include "EventHandler.h"
#include "ObjectRender.h"


unsigned int renderWindow::s_windowWidth = 0;
unsigned int renderWindow::s_windowHeight = 0;
renderWindow::renderWindow() {}

renderWindow::~renderWindow()
{
    ObjectRender::shutDownImgui();
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
    SDL_WindowFlags window_flags = (SDL_WindowFlags) (SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (fullscreen)
    {
        window_flags = (SDL_WindowFlags) (SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    }

    // checks to make sure that the system is initialized correctly before making
    // a m_window
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "subsystem running" << std::endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, width, height, window_flags);
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
    // Setup Dear ImGui context
    ObjectRender::initImgui(renderer, m_window);
    EventHandler::initEvents(this);
}


void renderWindow::handleEvents()
{
    EventHandler::HandleEvents();
}

void renderWindow::update()
{
}

void renderWindow::render()
{

    ObjectRender::completeRender(renderer);
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
