#pragma once

bool init();

void exitGameLoop();

SDL_Surface* loadSurface(std::string path);

bool loadImages();

bool mainMenu ();

extern SDL_Window *window;