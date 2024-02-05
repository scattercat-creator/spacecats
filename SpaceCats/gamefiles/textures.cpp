#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/textures.h>
#include <SDL2/SDL_ttf.h>

Texture::Texture()
{
    gTexture = NULL;
    HEIGHT = 0;
    WIDTH = 0;
    font = TTF_OpenFont("fonts/retganon.ttf", 24);
    opacity = 255;
    
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
    else
    {
        HEIGHT = tempSurf->h;
        WIDTH = tempSurf->w;
        
    }
    
    tempTexture = SDL_CreateTextureFromSurface(rend, tempSurf);
    if (tempTexture == NULL)
    {
        printf("texture couldn't load");
    }
    gTexture = tempTexture;
    SDL_FreeSurface(tempSurf);
    
}

bool Texture::loadFont(std::string text, SDL_Color textColor, SDL_Renderer*rend)
{
    free();
    bool success = true;
    font = TTF_OpenFont("fonts/retganon.ttf", 24);
    SDL_Surface * temp = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if(font == NULL)
    {
        printf("font doesn't exist");
    }
    if (temp == NULL)
    {
        printf( TTF_GetError(), SDL_GetError());
        success = false;
    }
    else
    {
        WIDTH = temp->w;
        HEIGHT = temp->h;
        gTexture = SDL_CreateTextureFromSurface(rend, temp);
        if (gTexture == NULL) 
        {
            printf("surface couldn't be created. Error: ", SDL_GetError());
            success = false;
        }
    }
    return success;

}

bool Texture::setBlendMode(SDL_BlendMode mode)
{
    SDL_SetTextureBlendMode(gTexture, mode);
}

bool Texture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(gTexture, alpha);
    opacity = alpha;
}

Uint8 Texture::getAlpha()
{
    return opacity;
}

SDL_Texture * Texture::getTexture()
{
    return gTexture;
}

SDL_Rect Texture::getRect()
{
    return gRect;
}

void Texture::setRect(int x, int y, int w, int h)
{
    gRect.x = x;
    gRect.y = y;
    gRect.w = w;
    gRect.h = h;
}

void Texture::render(SDL_Renderer *rend, int x, int y)
{
    SDL_Rect destination = {x, y, WIDTH, HEIGHT};
    SDL_RenderCopy(rend, gTexture, NULL, &destination);
}