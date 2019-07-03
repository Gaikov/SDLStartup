#include <iostream>
#include <SDL2/SDL.h>

int main(int argv, char** args) {
    std::cout << "Hello from SDL!" << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    return 0;
}