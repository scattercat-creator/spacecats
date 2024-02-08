#pragma once
#include <headers/textures.h>
#include <SDL2/SDL.h>
#include <vector>

class Dialogue
{
private:
    Texture screen;
    Texture text;
    Texture arrow;
    
    
public:
    Dialogue();
    ~Dialogue();
    void CreateScreen();
    void ShowText();
    int SelectOption();
    void ShowScreen();
    void CreateText(std::string myText);

    enum scenes
    {  
        SCENEONE
    };

};