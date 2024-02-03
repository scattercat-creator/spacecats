#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/functioninits.h>

bool fading = false;
Uint8 fadeopacity = 0;
Uint32 starting;



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
            currentBackground = mainS;
            SDL_Event e;
            bool quit = false;
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if(e.type == SDL_QUIT)
                    {
                        quit = true;
                        exitGameLoop();
                    }
                    else if(e.type == SDL_KEYDOWN)
                    {
                        if (e.key.keysym.sym == SDLK_SPACE)
                        {
                            fading = true;
                            starting = SDL_GetTicks();
                        }
                    }
                    
                }
                SDL_RenderClear(screenRenderer);
                
                setCurrentTexture(currentBackground);
                fading = fadeTo(fading, starting, fadeopacity, mainS);
                SDL_RenderPresent(screenRenderer);

            }
            
        }
            
    }
    
    return 0;
}
