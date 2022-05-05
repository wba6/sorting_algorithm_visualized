//
// Created by william on 5/5/22.
//

#include "algorithms.h"
#include "imgui/imgui.h"
namespace algo
{
    algorithms_menu::algorithms_menu(algorithms *&currentAgloPointer)
        : m_CurrentAlgo(currentAgloPointer)
    {
    }
    void algorithms_menu::OnImGuiRender()
    {
        for (const auto &algo: m_Algorithms)
        {
            if (ImGui::Button(algo.first.c_str()))
                m_CurrentAlgo = algo.second();
        }
    }
}// namespace algo