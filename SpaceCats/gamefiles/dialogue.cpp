#include "headers/dialogue.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <headers/textures.h>
#include <headers/functioninits.h>

Dialogue::Dialogue()
{
    
}

Dialogue::~Dialogue()
{
    printf("dialogue deleted");
}


void Dialogue::CreateScreen()
{
    screen.loadTexture("res/dialoguebox.png", screenRenderer);
    if(screen.getTexture() == NULL)
    {
        printf(SDL_GetError());
    }
    
}

void Dialogue::ShowScreen()
{
    screen.render(screenRenderer, 0, 500);
}

void Dialogue::ShowText()
{
    text.loadFont("testing testing", {255, 255, 255}, screenRenderer);
    // printf(TTF_GetError());
    // printf(SDL_GetError());
    if(screenRenderer == NULL)
    {
        printf("WHAT NOW HUHHHH");
    }
    text.render(screenRenderer, 10, 510);
}