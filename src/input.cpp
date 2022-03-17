#include "../include/input.h"


bool handleInput(bool quit, SDL_Event sdlevent, CHIP8 &chip8, int &FPS) {
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
                case SDLK_9:
                    if (FPS > 10) {
                        FPS -= 10;
                    }
                    break;
                case SDLK_0:
                    FPS += 10;
                    break;
            }
        }
    }

    return quit;
}
