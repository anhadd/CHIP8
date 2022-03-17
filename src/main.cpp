#include <iostream>
#include "../include/chip8.h"
#include "../include/input.h"
#include "../include/GUI.h"

#include <SDL2/SDL.h>


using namespace std;



// DONE: ADDED 9 AND 0 TO DECREASE / INCREASE SPEED
// DONE: SDL2 DOESNT WORK YET -> THE COMPILER FLAGS ARE WRONG OR SOMETHING?
// DONE: FIXED BREAKOUT, APPARENTLY THE ROM WAS BROKEN (?)
// DONE: check 8xy5 and 8xy6? Just try to pass the test_opcode rom. <- WAS WITH SIGNEDNESS AND SHIFTING
int main(int argc, char *argv[])
{
    CHIP8 chip8;
    
    //set up SDL
    const int height = 32, width = 64, scale = 10;
    GUI gui(height, width, scale);
    
    bool quit = false;
    int FPS = 60;

    SDL_ShowWindow(gui.window);
    cout << "Window Opened!" << endl;

    if (chip8.loadRom(argv[1]) != 0) {
        cout << "Error: Could not open ROM.";
        return 0;
    }

    cout << "Rom Loaded!" << endl;

    while (!quit) {
        quit = handleInput(quit, gui.sdlevent, chip8, FPS);
        SDL_Delay(1000/FPS);

        chip8.executeCycle();
        if (chip8.drawFlag) {
            SDL_RenderClear(gui.renderer);
            SDL_SetRenderDrawColor(gui.renderer, 255, 255, 255, 255);
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    if (chip8.display[i][j] == 1) {
                        SDL_RenderDrawPoint(gui.renderer, i, j);
                    }
                }
            }
            SDL_SetRenderDrawColor(gui.renderer, 0, 0, 0, 255);
            SDL_RenderPresent(gui.renderer);
            chip8.drawFlag = false;
        }
    }

    cout << "Finished!\n";
    return 0;
}
