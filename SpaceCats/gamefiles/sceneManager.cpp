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
bool inputNeeded = false;

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
                if(needInput)
                {
                    input = dialogue.SelectOption();
                }
                currentText = runScript(input, runs, &needInput);
                dialogue.CreateText(currentText);
            }
            if(needInput)
            {
                if(dialogue.getSelectorPosY()>= 545 && e.key.keysym.sym == SDLK_UP)
                {
                    dialogue.MoveInput(-20);
                }
                else if(dialogue.getSelectorPosY() <= 545 && e.key.keysym.sym == SDLK_DOWN)
                {
                    dialogue.MoveInput(20);
                }
            }
        }          
    }
    
    SDL_RenderClear(screenRenderer);
    setCurrentBackground(currentBackground);
    //printf("dialogue should've shown here");
    dialogue.ShowScreen();
    //printf("hereeee");
    dialogue.ShowText();
    
    if(needInput)
    {
        dialogue.ShowInput();
    }

    SDL_RenderPresent(screenRenderer);
    //cin.get();
    return true;

}