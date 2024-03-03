#pragma once
#include <headers/textures.h>
#include <SDL2/SDL.h>
#include <vector>

class Dialogue
{
private:
    Texture screen;
    Texture text;
    Texture heart;
    int inputY = 545;
    
    
public:
    Dialogue();
    ~Dialogue();
    void CreateScreen();
    void ShowText();
    int SelectOption();
    void ShowScreen();
    void ShowInput();
    void CreateText(std::string myText);
    int getSelectorPosY();
    void MoveInput(int x);

    enum scenes
    {  
        SCENEONE
    };

};