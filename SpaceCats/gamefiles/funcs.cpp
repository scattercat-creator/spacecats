#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window *window = NULL;
const int WIDTH = 800, HEIGHT = 600;
SDL_Surface *screenSurface = NULL;
SDL_Surface *mainScreen = NULL;
SDL_Rect mainScreenScale;
SDL_Surface *newGame = NULL; 
SDL_Rect newGameRect;

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
            int imageFlag = IMG_INIT_PNG;
            if (!IMG_Init(imageFlag) & imageFlag)
            {
                printf("sdl_image error: ", IMG_GetError());
                success = false;
            }
            else
            {
                screenSurface = SDL_GetWindowSurface(window);
            }
        }
    }
    return success;
}

void exitGameLoop()
{
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
    SDL_Surface *ogsurf = IMG_Load(path.c_str());
    SDL_Surface *optimizeprime;
    if (ogsurf == NULL)
    {
        printf("surface couldn't load. error: ", IMG_GetError());
    }
    else 
    {
        optimizeprime = SDL_ConvertSurface(ogsurf, screenSurface -> format, 0);
        SDL_FreeSurface(ogsurf);
    }
    return optimizeprime;
}

bool loadImages()
{
    bool success = true;
    mainScreen = loadSurface("res/introscreen.png");
    if(mainScreen == NULL)
    {
        printf("mainscreen didn't load. error: ", IMG_GetError());
        success = false;
    }
    newGame = loadSurface("res/newGameButton.png");
    if (newGame == NULL)
    {
        printf("newGame button didn't load. error: ", IMG_GetError());
        success = false;
    }
    return success;
}

bool mainMenu ()
{
    mainScreenScale.x = 0;
    mainScreenScale.y = 0;
    mainScreenScale.w = WIDTH;
    mainScreenScale.h = HEIGHT;
    newGameRect.y = 500;
    newGameRect.x = 80;
    newGameRect.w = 200;
    newGameRect.h = 75;
    SDL_BlitScaled(mainScreen, NULL, screenSurface, &mainScreenScale);
    SDL_BlitScaled(newGame, NULL, screenSurface, &newGameRect);
}