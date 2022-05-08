//
// Created by william on 5/5/22.
//

#ifndef SORTING_ALGORITHM_VISUALIZED_ALGORITHMS_H
#define SORTING_ALGORITHM_VISUALIZED_ALGORITHMS_H
#include "iostream"
#include <SDL_render.h>
#include <functional>
#include <vector>
namespace algo
{

    class algorithms {
    public:
        algorithms() {}
        virtual ~algorithms() {}

        virtual void OnUpdate(float deltaTime){};
        virtual void OnRender(SDL_Renderer *&rend){};
        virtual void generateRandNum(){};
        virtual void OnImGuiRender(){};
    };

    class algorithms_menu : public algorithms {
    public:
        explicit algorithms_menu(algorithms *&currentAgloPointer);
        virtual ~algorithms_menu() = default;

        void OnImGuiRender() override;
        template<typename t>
        void RegisterAlgorithm(const std::string &name)
        {
            std::cout << "Registering algorithms " << name << std::endl;
            m_Algorithms.push_back(std::make_pair(name, []() { return new t(); }));
        }

    private:
        algorithms *&m_CurrentAlgo;
        std::vector<std::pair<std::string, std::function<algorithms *()>>> m_Algorithms;
    };

}// namespace algo

#endif//SORTING_ALGORITHM_VISUALIZED_ALGORITHMS_H
