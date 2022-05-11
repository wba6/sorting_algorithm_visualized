cmake_minimum_required(VERSION 3.21)
project(sorting_algorithm_visualized )

set(CMAKE_CXX_STANDARD 14)
add_library(imgui
        # Main Imgui files
        src/vender/imgui/imgui.cpp src/vender/imgui/imgui_draw.cpp
        src/vender/imgui/imgui_tables.cpp src/vender/imgui/imgui_widgets.cpp
        src/vender/imgui/imgui_demo.cpp
        # SDL2
        src/vender/imgui/imgui_impl_sdl.cpp
        src/vender/imgui/imgui_impl_sdlrenderer.cpp )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
if(UNIX)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${PROJECT_SOURCE_DIR}/src/vender)

if (WIN32)
    include_directories(src/vender/SDL2/include)
    LINK_DIRECTORIES(src/vender/SDL2/lib/x64)
endif ()


add_executable(sorting_algorithm_visualized  src/main.cpp src/renderWindow.cpp src/renderWindow.h src/algorithems/insertionSort.cpp
        src/algorithems/insertionSort.h src/rectangle.cpp src/rectangle.h src/sortingAlgorimths.cpp src/sortingAlgorimths.h
        src/algorithems/algorithms.cpp src/algorithems/algorithms.h src/algorithems/quickSort.cpp src/algorithems/quickSort.h src/ObjectRender.h src/ObjectRender.cpp src/EventHandler.h src/EventHandler.cpp)

target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2
        imgui)