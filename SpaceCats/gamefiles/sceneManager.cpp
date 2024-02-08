#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/functioninits.h>
#include <headers/dialogue.h>
#include <SDL2/SDL_ttf.h>
#include <headers/userInputManager.h>
#include <headers/reader.h>


InputManager manager;
bool needInput = false;
int input = 1;
int run = -1;
int* runs = &run;
SDL_Event e;
bool spacePressed = false;
std::string currentText = "Press space to continue.";

bool sceneOne() 
{
    while (SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_QUIT)
        {
            exitGameLoop();
            return false;
        }
        if(e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_SPACE)
            {
                fadeTo(gameP);
                currentScene = 2;
                return false;     
            }
        }
                    
    }
    SDL_RenderClear(screenRenderer);
    setCurrentBackground(0);
    SDL_RenderPresent(screenRenderer);
    return true;
    

}

bool sceneTwo()
{
    while (SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_QUIT)
        {
            exitGameLoop();
            return false;
        }
        if(e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_SPACE)
            {
                currentText = runScript(input, runs, &needInput);
                dialogue.CreateText(currentText);
            }
        }          
    }
    
    SDL_RenderClear(screenRenderer);
    setCurrentBackground(currentBackground);
    //printf("dialogue should've shown here");
    dialogue.ShowScreen();
    //printf("hereeee");
    dialogue.ShowText();
    
    // if(needInput)
    // {
    //     cin >> input;
    // }

    SDL_RenderPresent(screenRenderer);
    //cin.get();
    return true;

}