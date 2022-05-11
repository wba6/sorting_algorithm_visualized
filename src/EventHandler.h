//
// Created by william on 5/11/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_EVENTHANDLER_H
#define SORTING_ALGORITHM_VISUALIZED_EVENTHANDLER_H
#include "SDL.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_sdlrenderer.h"
#include "renderWindow.h"
#include <vector>

class EventHandler {
public:

    static void initEvents(renderWindow* window)
    {
        instance = window;
    }
    static void HandleEvents(){
        // gets events
        events.clear();
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            switch (event.type)
            {
                case SDL_QUIT:
                    instance->m_isRunning = false;
                    break;
            }
            events.push_back(event);
        }
    }
private:
    static renderWindow* instance;
    static std::vector<SDL_Event> events;

    EventHandler();
};
#endif//SORTING_ALGORITHM_VISUALIZED_EVENTHANDLER_H
