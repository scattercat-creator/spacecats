#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/functioninits.h>

int main(int argc, char* argv[])
{
    if (!init())
    {
        printf("failed to initialize!");
    }
    else
    {
        if (!loadImages())
        {
            printf("failed to load images");
        }
        else{
            SDL_Event e;
            bool quit = false;
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if(e.type == SDL_QUIT)
                    {
                        exitGameLoop();
                    }
                }
                mainMenu();
                SDL_UpdateWindowSurface(window);

            }
            
        }
            
    }
    
    return 0;
}
