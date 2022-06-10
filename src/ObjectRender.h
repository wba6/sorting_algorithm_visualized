

#ifndef SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
#define SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
#include "EventHandler.h"
#include "SDL.h"
#include "algorithems/algorithms.h"
#include "algorithems/bubbleSort.h"
#include "algorithems/insertionSort.h"
#include "algorithems/quickSort.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_sdlrenderer.h"
#include "rectangle.h"
#include <vector>
class ObjectRender {
public:
    /*
     * instantiates imgui, sets theme, and sets default menu and algorithm types
     *
     * takes in SDL_Renderer pointer reference and  SDL_Window pointer reference
     *
     * Parameters: SDL_Renderer *&renderer, SDL_Window *&window
     * */
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
        s_algoMenu->RegisterAlgorithm<algo::bubbleSort>("bubble Sort");
    }

    /*
     * terminates Imgui should be m_done when finished with program
     * */
    static void shutDownImgui()
    {
        ImGui_ImplSDLRenderer_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    /*
     * catches the frame from which an algorithm was called
     * needs to be m_done once before calling visualize
     *
     * takes in a pointer reference to current renderer s_instance
     *
     * Parameters: SDL_Render*& renderer
     */
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

    /*
     * visualize function used to show the algorithms sorting each frame
     * called from within an algorithm at each iteration
     *
     * takes in a vector of pointers to rects objects, a compare index that will be red, the swapIndex witch is green,
     * and pivot index only used in some algorithms witch is blue.
     *
     * all other rects will be drawn white
     *
     * Parameters:  std::vector<rectangle *> &rects, int compareIndex, int swapIndex, int pivotIndex, SDL_Renderer *&renderer
     * */
    static bool visualize(std::vector<rectangle *> &rects, int compareIndex, int swapIndex, int pivotIndex, SDL_Renderer *&renderer)
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
            else if (pivotIndex == i)
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
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

    /*
     * returns to the frame from which an algorithm was called
     * needs to be m_done once m_done sorting and returning to complete render
     *
     * takes in a pointer reference to current renderer s_instance
     *
     * Parameters: SDL_Render*& renderer
     */
    static void releaseFrameVisualize(SDL_Renderer *&renderer)
    {
        SDL_RenderClear(renderer);


        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    /*
     * complete render of a frame
     * Will mainly occur on main menu
     *
     * takes in a pointer reference to current renderer s_instance
     *
     * Parameters: SDL_Render*& renderer
     * */
    static void completeRender(SDL_Renderer *&renderer)
    {
        SDL_RenderClear(renderer);

        ObjectRender::imguiRender(renderer, false);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
    }

    /*
     * Renders imgui and calls for current s_instance of the algoithm to render if not already
     *
     * takes in a pointer reference to current renderer s_instance and
     * a bool to check if the function is being called from within a algorithm already
     *
     * Parameters: SDL_Renderer *& renderer , bool inbeaded
     * */
    static void imguiRender(SDL_Renderer *&renderer, bool inBeaded)
    {
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        if (s_currentAlgo)
        {
            if (!inBeaded)
            {
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

    //disallow construction and destruction of class
    ObjectRender() = delete;
    ~ObjectRender() = delete;

private:
    static algo::algorithms *s_currentAlgo;  //keeps track of selected algorithm, default is algorithms_menu
    static algo::algorithms_menu *s_algoMenu;//pointer to the starting menu
};
#endif//SORTING_ALGORITHM_VISUALIZED_OBJECTRENDER_H
