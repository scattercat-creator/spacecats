#include "headers/dialogue.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <headers/textures.h>
#include <headers/functioninits.h>

Dialogue::Dialogue()
{
    scene = SCENEONE;
    screen.loadTexture("res/dialoguebox.png", screenRenderer);
    if(screen.getTexture() == NULL)
    {
        printf(SDL_GetError());
    }
    
    
}

Dialogue::~Dialogue()
{
    printf("dialogue deleted");
}

void Dialogue::CreateScreen()
{
    screen.render(screenRenderer, 0, 500);
    
}

void Dialogue::ShowText()
{
    text.loadFont("testing testing", {255, 255, 255}, screenRenderer);
    text.render(screenRenderer, 10, 510);
}