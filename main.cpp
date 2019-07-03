#include <iostream>
#include <SDL2/SDL.h>

int main(int argv, char **args) {
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow(
            "SDL2 Test",
            SDL_WINDOWPOS_UNDEFINED,           
            SDL_WINDOWPOS_UNDEFINED,           
            640,                               
            480,                               
            SDL_WINDOW_OPENGL                  
    );
    
    if (!window) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}