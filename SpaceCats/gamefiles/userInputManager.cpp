#include <SDL2/SDL.h>
#include <headers/functioninits.h>
#include <headers/userInputManager.h>

InputManager::InputManager()
{
    spacePressed = false;
}

bool InputManager::eventCheck(SDL_Event e)
{
    while (SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_QUIT)
        {
            exitGameLoop();
            return false;
        }
        if(e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_SPACE)
            {
                spacePressed = true;
            }
        }          
    }
    return true;
}


