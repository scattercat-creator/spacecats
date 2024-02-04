#pragma once
#include <headers/textures.h>
bool init();

void exitGameLoop();


bool loadImages();

extern SDL_Renderer* screenRenderer;
extern int currentBackground;


bool fadeTo(bool running, Uint32 startTime, Uint8 opacity, int index);

void setCurrentBackground(int index);

enum textures {
    mainS,
    blackS,
    gameP,
    total
};