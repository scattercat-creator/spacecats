#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/functioninits.h>
#include <headers/dialogue.h>
#include <SDL2/SDL_ttf.h>


bool sceneOne(SDL_Event e) 
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
bool sceneTwo(SDL_Event e)
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
                   
            }
        }
                    
    }
    SDL_RenderClear(screenRenderer);
    setCurrentBackground(currentBackground);
    dialogue.ShowScreen();
    dialogue.ShowText();
    SDL_RenderPresent(screenRenderer);
    return true;

}