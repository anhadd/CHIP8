#include "../include/GUI.h"



GUI::GUI(const int height, const int width, const int scale) {
    // Constructor
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width*scale, height*scale, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, width, height);
    SDL_RenderSetScale(renderer, scale, scale);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);
}


GUI::~GUI() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
