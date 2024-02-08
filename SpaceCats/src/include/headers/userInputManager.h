#pragma once
#include <SDL2/SDL.h>


class InputManager
{
private:
    bool spacePressed;
public:
    InputManager();
    bool eventCheck(SDL_Event e);
    bool waitforInput();
};