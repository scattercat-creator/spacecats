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
    heart.loadTexture("res/heart.png", screenRenderer);
    if(heart.getTexture() == NULL)
    {
        printf("heart couldn't load");
    }
    text.setFont("fonts/retganon.ttf");
    
}

void Dialogue::ShowScreen()
{
    screen.render(screenRenderer, 0, 500);
}

void Dialogue::ShowText()
{
    text.render(screenRenderer, 10, 510);
    //printf("strange sdl error: ", SDL_GetError());
}

void Dialogue::ShowInput()
{
    heart.render(screenRenderer, 5, inputY);
}
int Dialogue::SelectOption()
{
    if(inputY == 565)
    {
        return 3;
    }
    else if(inputY == 545)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int Dialogue::getSelectorPosY()
{
    return inputY;
}
void Dialogue::MoveInput(int x)
{
    inputY += x;
}
void Dialogue::CreateText(std::string myText)
{
    text.loadFont(myText, {255, 255, 255}, screenRenderer);
}