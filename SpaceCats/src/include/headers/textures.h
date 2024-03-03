#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

class Texture
{
private:
    SDL_Texture * gTexture;
    SDL_Rect gRect;
    int WIDTH;
    int HEIGHT;
    TTF_Font *font;
    Uint8 opacity;
public:
    Texture();
    ~Texture();
    void free();
    void loadTexture(std::string path, SDL_Renderer *rend);
    void setBlendMode(SDL_BlendMode mode);
    void setAlpha(Uint8 alpha);
    SDL_Texture *getTexture();
    SDL_Rect getRect();
    void setRect(int x, int y, int w, int h);
    void render(SDL_Renderer *rend, int x, int y);
    bool loadFont(std::string text, SDL_Color textColor, SDL_Renderer* rend);
    Uint8 getAlpha();
    void setFont(std::string path);

};