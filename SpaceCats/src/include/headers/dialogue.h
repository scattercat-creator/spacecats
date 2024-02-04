#pragma once
#include <headers/textures.h>
#include <SDL2/SDL.h>

class Dialogue
{
private:
    int scene;
    Texture screen;
    SDL_Rect destination;
    Texture text;
    
    
public:
    Dialogue();
    ~Dialogue();
    void CreateScreen();
    void ShowText();
    void ShowOptions();
    enum scenes
    {  
        SCENEONE
    };

};