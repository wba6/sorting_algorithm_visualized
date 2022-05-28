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
    static void initEvents(renderWindow *window)
    {
        s_instance = window;
    }
    static void HandleEvents()
    {
        //clear previous s_events
        s_events.clear();
        //get new s_events
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            //imgui s_events
            ImGui_ImplSDL2_ProcessEvent(&event);
            switch (event.type)
            {
                case SDL_QUIT:
                    //TODO: Close window when close button is clicked while in for loop
                    s_instance->m_isRunning = false;
                    break;
            }
            s_events.push_back(event);
        }
    }

private:
    static renderWindow *s_instance;
    static std::vector<SDL_Event> s_events;

    EventHandler() = delete;
};
#endif//SORTING_ALGORITHM_VISUALIZED_EVENTHANDLER_H
