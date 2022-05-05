cmake_minimum_required(VERSION 3.21)
project(sorting_algorithm_visualized )

set(CMAKE_CXX_STANDARD 14)
add_library(imgui
        # Main Imgui files
        dependencies/imgui/imgui.cpp dependencies/imgui/imgui_draw.cpp
        dependencies/imgui/imgui_tables.cpp dependencies/imgui/imgui_widgets.cpp
        dependencies/imgui/imgui_demo.cpp
        # SDL2
        dependencies/imgui/imgui_impl_sdl.cpp
        dependencies/imgui/imgui_impl_sdlrenderer.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
if(UNIX)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${PROJECT_SOURCE_DIR}/dependencies)

if (WIN32)
    include_directories(${PROJECT_SOURCE_DIR}/dependencies/SDL2/include)
    LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/dependencies/SDL2/lib/x64)
endif ()


add_executable(sorting_algorithm_visualized  src/main.cpp src/renderWindow.cpp includes/renderWindow.h src/createRandomData.cpp
        includes/createRandomData.h src/rectangle.cpp includes/rectangle.h src/sortingAlgorimths.cpp includes/sortingAlgorimths.h)

target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2
        imgui)