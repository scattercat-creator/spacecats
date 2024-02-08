#include "headers/dialogue.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <headers/textures.h>
#include <headers/functioninits.h>
#include <vector>

std::string optionsList[] = {"default", "default", "default"};
int currentLine = 0;

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
    arrow.loadTexture("res/selection arrow.png", screenRenderer);
    if(arrow.getTexture() == NULL)
    {
        printf("arrow couldn't load");
    }
    
}

void Dialogue::ShowScreen()
{
    screen.render(screenRenderer, 0, 500);
}

void Dialogue::ShowText(std::string myText)
{
    text.loadFont(myText, {255, 255, 255}, screenRenderer);
    text.render(screenRenderer, 10, 510);
}

int Dialogue::SelectOption()
{
    return 2;
}