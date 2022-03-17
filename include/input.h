#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "chip8.h"


bool handleInput(bool quit, SDL_Event sdlevent, CHIP8 &chip8, int &FPS);


#endif
