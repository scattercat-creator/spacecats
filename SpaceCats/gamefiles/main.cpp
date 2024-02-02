#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/functioninits.h>

bool fading = false;
Uint8 fadeopacity = 0;
bool fadingout = false;

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
                        quit = true;
                        exitGameLoop();
                    }
                    else if(e.type == SDL_KEYDOWN)
                    {
                        if (e.key.keysym.sym == SDLK_SPACE)
                        {
                            fading = true;
                            fadingout = true;
                        }
                    }
                    
                }
                SDL_RenderClear(screenRenderer);
                mainMenu();
                if(fading)
                {
                    
                    fading = fadeToBlack(fading, fadeopacity);
                    fadeopacity += 1;
                }
                if(!fading && fadingout)
                {
                    fadingout = fadeToBlack(fadingout, fadeopacity);
                    fadeopacity -= 1;
                }
                
                SDL_RenderPresent(screenRenderer);

            }
            
        }
            
    }
    
    return 0;
}
