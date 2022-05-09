

#include "renderWindow.h"
#include "algorithems/algorithms.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_sdlrenderer.h"

unsigned int renderWindow::s_windowWidth = 0;
unsigned int renderWindow::s_windowHeight = 0;
renderWindow::renderWindow() {}

renderWindow::~renderWindow()
{
    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
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
    //setting up imgui
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForSDLRenderer(m_window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);


    currentAlgo = nullptr;
    algoMenu = new algo::algorithms_menu(currentAlgo);
    currentAlgo = algoMenu;
    algoMenu->RegisterAlgorithm<algo::insertionSort>("Insertion Sort");
    algoMenu->RegisterAlgorithm<algo::quickSort>("Quick Sort");

}


void renderWindow::handleEvents()
{
    // gets events
    events.clear();
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
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

//TODO:Remove this
bool show_demo_window = true;
void renderWindow::render()
{

    // Imgui render
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    if (currentAlgo)
    {
        currentAlgo->OnUpdate(0.0f);
        currentAlgo->OnRender(renderer);
        ImGui::Begin("algorithms");
        if (currentAlgo != algoMenu && ImGui::Button("<-"))
        {
            delete currentAlgo;
            currentAlgo = algoMenu;
        }
        currentAlgo->OnImGuiRender();
        ImGui::End();
    }
    ImGui::Render();

    // Update and Render additional Platform Windows

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //sdl renderer

    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
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
