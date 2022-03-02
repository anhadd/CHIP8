#include <iostream>
#include "include/chip8.h"

#include <SDL2/SDL.h>


using namespace std;


bool handleInput(bool quit, SDL_Event sdlevent, CHIP8 &chip8);


// DONE: SDL2 DOESNT WORK YET -> THE COMPILER FLAGS ARE WRONG OR SOMETHING?
// DONE: CONTINUE WITH USER INPUT!
// TODO: check 8xy5 and 8xy6? Just try to pass the test_opcode rom.
int main(int argc, char *argv[])
{
    CHIP8 chip8;
    bool quit = false;

    //set up SDL
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Event sdlevent;
    const int height = 32, width = 64;
    const int scale = 10;
    const int FPS = 180;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width*scale, height*scale,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, width, height);
    SDL_RenderSetScale(renderer, scale, scale);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);

    SDL_ShowWindow(window);
    cout << "New Window Created!" << endl;

    chip8.loadRom(argv[1]);
    cout << "Rom Loaded!" << endl;

    while (!quit) {
        quit = handleInput(quit, sdlevent, chip8);
        SDL_Delay(1000/FPS);

        chip8.executeCycle();
        if (chip8.drawFlag) {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    if (chip8.display[i][j] == 1) {
                        SDL_RenderDrawPoint(renderer, i, j);
                    }
                }
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderPresent(renderer);
            chip8.drawFlag = false;
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    cout << "Finished!\n";
    return 0;
}


bool handleInput(bool quit, SDL_Event sdlevent, CHIP8 &chip8) {
    while (SDL_PollEvent(&sdlevent)){
        if (sdlevent.type == SDL_QUIT){
            quit = true;
        }
        else if (sdlevent.type == SDL_KEYDOWN){
            switch (sdlevent.key.keysym.sym) {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                case SDLK_x:
                    chip8.keys[0] = 1;
                    break;
                case SDLK_1:
                    chip8.keys[1] = 1;
                    break;
                case SDLK_2:
                    chip8.keys[2] = 1;
                    break;
                case SDLK_3:
                    chip8.keys[3] = 1;
                    break;
                case SDLK_q:
                    chip8.keys[4] = 1;
                    break;
                case SDLK_w:
                    chip8.keys[5] = 1;
                    break;
                case SDLK_e:
                    chip8.keys[6] = 1;
                    break;
                case SDLK_a:
                    chip8.keys[7] = 1;
                    break;
                case SDLK_s:
                    chip8.keys[8] = 1;
                    break;
                case SDLK_d:
                    chip8.keys[9] = 1;
                    break;
                case SDLK_z:
                    chip8.keys[10] = 1;
                    break;
                case SDLK_c:
                    chip8.keys[11] = 1;
                    break;
                case SDLK_4:
                    chip8.keys[12] = 1;
                    break;
                case SDLK_r:
                    chip8.keys[13] = 1;
                    break;
                case SDLK_f:
                    chip8.keys[14] = 1;
                    break;
                case SDLK_v:
                    chip8.keys[15] = 1;
                    break;
            }
        }
        else if (sdlevent.type == SDL_KEYUP){
            switch (sdlevent.key.keysym.sym) {
                case SDLK_x:
                    chip8.keys[0] = 0;
                    break;
                case SDLK_1:
                    chip8.keys[1] = 0;
                    break;
                case SDLK_2:
                    chip8.keys[2] = 0;
                    break;
                case SDLK_3:
                    chip8.keys[3] = 0;
                    break;
                case SDLK_q:
                    chip8.keys[4] = 0;
                    break;
                case SDLK_w:
                    chip8.keys[5] = 0;
                    break;
                case SDLK_e:
                    chip8.keys[6] = 0;
                    break;
                case SDLK_a:
                    chip8.keys[7] = 0;
                    break;
                case SDLK_s:
                    chip8.keys[8] = 0;
                    break;
                case SDLK_d:
                    chip8.keys[9] = 0;
                    break;
                case SDLK_z:
                    chip8.keys[10] = 0;
                    break;
                case SDLK_c:
                    chip8.keys[11] = 0;
                    break;
                case SDLK_4:
                    chip8.keys[12] = 0;
                    break;
                case SDLK_r:
                    chip8.keys[13] = 0;
                    break;
                case SDLK_f:
                    chip8.keys[14] = 0;
                    break;
                case SDLK_v:
                    chip8.keys[15] = 0;
                    break;
            }
        }
    }

    return quit;
}
