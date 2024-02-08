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
    void ShowText(std::string myText);
    int SelectOption();
    void ShowScreen();
    enum scenes
    {  
        SCENEONE
    };

};