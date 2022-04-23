cmake_minimum_required(VERSION 3.21)
project(sorting_algorithm_visualized )

set(CMAKE_CXX_STANDARD 14)



include_directories(${PROJECT_SOURCE_DIR}/dependencies/SDL2/include)
include_directories(${PROJECT_SOURCE_DIR}/includes)
if(WIN32)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/dependencies/SDL2/lib/x64)
endif()
add_executable(sorting_algorithm_visualized  src/main.cpp src/renderWindow.cpp includes/renderWindow.h src/createRandomData.cpp includes/createRandomData.h src/rectangle.cpp includes/rectangle.h src/animateMovement.cpp includes/animateMovement.h)

target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2)