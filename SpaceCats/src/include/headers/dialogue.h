#pragma once
#include <headers/textures.h>
#include <SDL2/SDL.h>

class Dialogue
{
private:
    Texture screen;
    Texture text;
    
    
public:
    Dialogue();
    ~Dialogue();
    void CreateScreen();
    void ShowText();
    void ShowOptions();
    void ShowScreen();
    enum scenes
    {  
        SCENEONE
    };

};