#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/functioninits.h>
#include <headers/dialogue.h>
#include <headers/manager.h>
#include <headers/reader.h>
#include <headers/textures.h>


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
        else
        {
            currentBackground = mainS;
            
            //dialogue.CreateScreen();
            while (sceneOne()){};
            initReader();
            while(currentScene == 2 && sceneTwo()){};
            
        }
            
    }
    
    return 0;
}
