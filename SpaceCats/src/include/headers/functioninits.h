#pragma once

bool init();

void exitGameLoop();

SDL_Texture* loadTexture(std::string path);

bool loadImages();

bool mainMenu ();

extern SDL_Renderer* screenRenderer;

bool fadeToBlack(bool running, Uint8 opacity);

bool fadeOutBlack(bool running, Uint8 opacity);
