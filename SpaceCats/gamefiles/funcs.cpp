#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/textures.h>
#include <headers/dialogue.h>
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

// dialogue
Dialogue dialogue;
int currentScene = 1;

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
                if(TTF_Init() == -1)
                {
                    printf("ttf didn't load. Error: ", TTF_GetError());
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
    dialogue.CreateScreen();

    return true;
    
}

void setCurrentBackground(int index)
{
    backgrounds[index].render(screenRenderer, 0, 0);
    
} 


void fadeTo(int gScene)
{
    
    int starttime = SDL_GetTicks();
    int currentTime = 0;
    int temp = 0;
    while(true)
    {
        currentTime = (SDL_GetTicks() - starttime) / 10;
        if(backgrounds[blackS].getAlpha() == 255)
        {
            break;
        }
        else if(currentTime > temp + 20)
        {
            backgrounds[blackS].setAlpha(backgrounds[blackS].getAlpha() + 51);
            temp += 20;
            SDL_RenderClear(screenRenderer);
            SDL_RenderCopy(screenRenderer, backgrounds[currentBackground].getTexture(), NULL, NULL);
            SDL_RenderCopy(screenRenderer, backgrounds[blackS].getTexture(), NULL, NULL);
            SDL_RenderPresent(screenRenderer);
        }
    }
    currentBackground = gScene;
    while(true)
    {
        currentTime = (SDL_GetTicks() - starttime) / 10;
        if (backgrounds[blackS].getAlpha() == 0)
        {
            break;
        }
        else if(currentTime > temp + 20)
        {
            backgrounds[blackS].setAlpha(backgrounds[blackS].getAlpha() - 51);
            temp += 20;
            SDL_RenderClear(screenRenderer);
            SDL_RenderCopy(screenRenderer, backgrounds[currentBackground].getTexture(), NULL, NULL);
            SDL_RenderCopy(screenRenderer, backgrounds[blackS].getTexture(), NULL, NULL);
            SDL_RenderPresent(screenRenderer);
        }
    }
}