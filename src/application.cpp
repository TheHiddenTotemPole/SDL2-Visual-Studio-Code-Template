#include "iostream"
#include "../SDL2/include/SDL2/SDL.h"

#define GAME_RESOLUTION_WIDTH 960
#define GAME_RESOLUTION_HEIGHT 540

int main (int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window) {
        printf("SDL was NOT able to initialize a window for the application. [%s]", SDL_GetError());
        exit(1);
    }

    SDL_Event window_event;

    while (true) {
        if (SDL_PollEvent(&window_event)) {
            if (SDL_QUIT == window_event.type) {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}