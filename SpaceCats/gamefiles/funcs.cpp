#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/textures.h>
// #include "headers/functioninits.h"

// Creates Window
SDL_Window *window = NULL;
const int WIDTH = 800, HEIGHT = 600;

// Creates Renderer
SDL_Renderer *screenRenderer = NULL;

// Textures
Texture mainScreen;
Texture blackScreen;
Texture gamePlayer;
Texture backgrounds[] = {mainScreen, blackScreen, gamePlayer};
// textures enum
enum textures {
    mainS,
    blackS,
    gameP,
    total
};

int currentBackground = 0;


bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("error initializing SDL", SDL_GetError());
        success = false;
    }
    else {
        window = SDL_CreateWindow("Space Cats", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            printf("error creating window: ", SDL_GetError());
            success = false;
        }
        else
        {
            screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (screenRenderer == NULL)
            {
                printf("error: ", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(screenRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imageFlag = IMG_INIT_PNG;
                if (!IMG_Init(imageFlag) & imageFlag)
                {
                    printf("sdl_image error: ", IMG_GetError());
                    success = false;
                }
                
            }
        }
        
    }
    return success;
}

void exitGameLoop()
{ 
    SDL_DestroyRenderer(screenRenderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

bool loadImages()
{
    backgrounds[mainS].loadTexture("res/introscreen.png", screenRenderer);
    if(backgrounds[mainS].getTexture() == NULL)
    {
        printf("main screen couldn't load");
    }
    // set up black screen
    backgrounds[blackS].loadTexture("res/black.png", screenRenderer);
    backgrounds[blackS].setBlendMode(SDL_BLENDMODE_BLEND);
    backgrounds[blackS].setAlpha(0);
    // set up game screen
    backgrounds[gameP].loadTexture("res/gamePlayer.png", screenRenderer);

    return true;
    
}

void setCurrentTexture(int index)
{
    SDL_RenderCopy(screenRenderer, backgrounds[index].getTexture(), NULL, NULL);
    
} 

bool fadeTo(bool running, Uint32 startTime, Uint8 opacity, int index)
{
    
    bool success = false;
    if (running)
    {
        //printf("complete");
        success = true;
        Uint32 time = (SDL_GetTicks() - startTime) / 10;
        setCurrentTexture(blackS);
        if(time > 140)
        {
            backgrounds[blackS].setAlpha(0);
            success = false;
            printf("hello");
            
        }
        else if(time > 120)
        {
            backgrounds[blackS].setAlpha(63);
        }
        else if(time > 100)
        {
            backgrounds[blackS].setAlpha(127);
        }
       else if(time > 80)
        {
            backgrounds[blackS].setAlpha(191);
        }
        else if(time > 60)
        {
            backgrounds[blackS].setAlpha(255);
            currentBackground = gameP;
        }
        else if(time > 40)
        {
            backgrounds[blackS].setAlpha(191);
            
        }
        else if(time > 20)
        {
            backgrounds[blackS].setAlpha(127);
            
        }
        else 
        {
            backgrounds[blackS].setAlpha(63);
           
        }
    }
    return success;
} 