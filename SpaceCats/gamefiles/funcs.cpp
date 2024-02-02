#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sstream>

SDL_Window *window = NULL;
const int WIDTH = 800, HEIGHT = 600;
SDL_Renderer *screenRenderer = NULL;
SDL_Texture *mainScreen = NULL;
SDL_Texture *blackScreen = NULL;


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

    SDL_DestroyTexture(mainScreen);
    SDL_DestroyTexture(blackScreen);
    SDL_DestroyRenderer(screenRenderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
    SDL_Surface *ogsurf = IMG_Load(path.c_str());
    SDL_Texture *myTexture = NULL;
    if (ogsurf == NULL)
    {
        printf("surface couldn't load. error: ", IMG_GetError());
    }
    else 
    {
        myTexture = SDL_CreateTextureFromSurface(screenRenderer, ogsurf);
        SDL_FreeSurface(ogsurf);
    }
    return myTexture;
}

bool loadImages()
{
    bool success = true;
    mainScreen = loadTexture("res/introfinal.png");
    if(mainScreen == NULL)
    {
        printf("mainscreen didn't load. error: ", IMG_GetError());
        success = false;
    }
    blackScreen = loadTexture("res/black.png");
    if (blackScreen == NULL)
    {
        printf("blackScreen didn't load. error: ", SDL_GetError());
        success = false;
    }
    SDL_SetTextureBlendMode(blackScreen, SDL_BLENDMODE_BLEND);
   SDL_SetTextureAlphaMod(blackScreen, 0);
   // SDL_SetTextureAlphaMod(blackScreen, 255);
    return success;
    
}

bool fadeToBlack(bool running, Uint8 opacity)
{
    
    bool keepRunning = false;
    if (running)
    {
        if (opacity < 255)
        {
            Uint8 temp = opacity + 1;
            SDL_SetTextureAlphaMod(blackScreen, temp);
            keepRunning = true;
            
        }
    }
    
    return keepRunning;
}

bool fadeOutBlack(bool running, Uint8 opacity)
{
    
    bool keepRunning = false;
    if (running)
    {
        if (opacity > 0)
        {
            Uint8 temp = opacity - 1;
            SDL_SetTextureAlphaMod(blackScreen, temp);
            keepRunning = true;
            
        }
    }
    
    return keepRunning;
}

bool mainMenu ()
{
  //  SDL_SetTextureBlendMode(blackScreen, SDL_BLENDMODE_BLEND);
    SDL_RenderCopy(screenRenderer, mainScreen, NULL, NULL);
      //  SDL_SetTextureAlphaMod(blackScreen, 255);

    SDL_RenderCopy(screenRenderer, blackScreen, NULL, NULL);
    
}