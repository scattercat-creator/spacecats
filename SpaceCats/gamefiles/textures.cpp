#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/textures.h>

Texture::Texture()
{
    gTexture = NULL;
    gRect.x = 0;
    gRect.y = 0;
    gRect.w = 800;
    gRect.h = 600;
}

Texture::~Texture()
{
    free();
}
    
void Texture::free()
{
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;
}

bool Texture::loadTexture(std::string path, SDL_Renderer *rend)
{
    SDL_Texture *tempTexture = NULL;    
    SDL_Surface* tempSurf = IMG_Load(path.c_str());
    if(tempSurf == NULL)
    {
        printf("texture didn't load: ", IMG_GetError());
    }
    tempTexture = SDL_CreateTextureFromSurface(rend, tempSurf);
    if (tempTexture == NULL)
    {
        printf("texture couldn't load");
    }
    gTexture = tempTexture;
    SDL_FreeSurface(tempSurf);
}

bool Texture::setBlendMode(SDL_BlendMode mode)
{
    SDL_SetTextureBlendMode(gTexture, mode);
}

bool Texture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(gTexture, alpha);
}

SDL_Texture * Texture::getTexture()
{
    return gTexture;
}

SDL_Rect Texture::getRect()
{
    return gRect;
}

void Texture::setRect(int x, int y)
{
    gRect.x = x;
    gRect.y = y;
}
