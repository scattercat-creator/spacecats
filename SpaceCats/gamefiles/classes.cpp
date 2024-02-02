#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Texture
{
    SDL_Texture * gTexture = NULL;
    
    Texture()
    {
        gTexture = NULL;
    }

    ~Texture()
    {
        free();
    }
    
    void free()
    {
        SDL_DestroyTexture(gTexture);
        gTexture = NULL;
    }

    bool loadTexture(std::string path, SDL_Renderer *rend)
    {
        SDL_Texture *tempTexture = NULL;
        bool success = true;
        SDL_Surface* tempSurf = IMG_Load(path.c_str());
        if(tempSurf == NULL)
        {
            success = false;
            printf("texture didn't load: ", IMG_GetError());
        }
        tempTexture = SDL_CreateTextureFromSurface(rend, tempSurf);
        if (tempTexture == NULL)
        {
            success = false;
            printf("texture couldn't load");
        }
    }
};
