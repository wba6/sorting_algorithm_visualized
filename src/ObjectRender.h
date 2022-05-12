//
// Created by william on 5/9/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
#define SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
#include "EventHandler.h"
#include "SDL.h"
#include "algorithems/algorithms.h"
#include "algorithems/insertionSort.h"
#include "algorithems/quickSort.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_sdlrenderer.h"
#include "rectangle.h"
#include <vector>
class ObjectRender {
public:
    static void initImgui(SDL_Renderer *&renderer, SDL_Window *&window)
    {

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void) io;
        ImGui::StyleColorsDark();
        ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer_Init(renderer);

        s_currentAlgo = nullptr;
        s_algoMenu = new algo::algorithms_menu(s_currentAlgo);
        s_currentAlgo = s_algoMenu;
        s_algoMenu->RegisterAlgorithm<algo::insertionSort>("Insertion Sort");
        s_algoMenu->RegisterAlgorithm<algo::quickSort>("Quick Sort");
    }
    static void shutDownImgui()
    {
        ImGui_ImplSDLRenderer_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }
    static void catchFrameVisualize(SDL_Renderer *&renderer)
    {


        ImGui::Begin("algorithms");
        if (s_currentAlgo != s_algoMenu && ImGui::Button("<-"))
        {
            delete s_currentAlgo;
            s_currentAlgo = s_algoMenu;
        }
        s_currentAlgo->OnImGuiRender();
        ImGui::End();

        ImGui::Render();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
    }

    static bool visualize(std::vector<rectangle *> &rects, int compareIndex, int swapIndex, SDL_Renderer *&renderer)
    {
        SDL_RenderClear(renderer);

        auto instanceName = s_currentAlgo;
        for (size_t i{0}; i < rects.size(); i++)
        {
            if (i == compareIndex)
            {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (i == swapIndex)
            {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            SDL_RenderFillRect(renderer, &rects.at(i)->getDestRect());
        }
        EventHandler::HandleEvents();
        ObjectRender::imguiRender(renderer, true);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
        if (instanceName != s_currentAlgo)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    static void releaseFrameVisualize(SDL_Renderer *&renderer)
    {
        SDL_RenderClear(renderer);


        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    static void completeRender(SDL_Renderer *&renderer)
    {

        // Imgui render
        SDL_RenderClear(renderer);


        // Update and Render additional Platform Windows
        ObjectRender::imguiRender(renderer, false);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //sdl renderer

        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
    }

    static void imguiRender(SDL_Renderer *&renderer, bool inBeaded)
    {
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        if (s_currentAlgo)
        {
            if (!inBeaded)
            {
                s_currentAlgo->OnUpdate(0.0f);
                s_currentAlgo->OnRender(renderer);
            }

            ImGui::Begin("algorithms");
            if (s_currentAlgo != s_algoMenu && ImGui::Button("<-"))
            {
                delete s_currentAlgo;
                s_currentAlgo = s_algoMenu;
            }

            s_currentAlgo->OnImGuiRender();
            ImGui::End();
        }
        ImGui::Render();
    }

private:
    ObjectRender() = delete;
    ~ObjectRender() = delete;
    static algo::algorithms *s_currentAlgo;
    static algo::algorithms_menu *s_algoMenu;
};
#endif//SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
