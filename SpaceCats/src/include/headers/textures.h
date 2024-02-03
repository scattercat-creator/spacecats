#pragma onceS
#include <SDL2/SDL.h>
#include <iostream>

class Texture
{
private:
    SDL_Texture * gTexture;
    SDL_Rect gRect;
public:
    Texture();
    ~Texture();
    void free();
    bool loadTexture(std::string path, SDL_Renderer *rend);
    bool setBlendMode(SDL_BlendMode mode);
    bool setAlpha(Uint8 alpha);
    SDL_Texture *getTexture();
    SDL_Rect getRect();
    void setRect(int x, int y);
};