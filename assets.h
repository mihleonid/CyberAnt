#pragma once
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#define getload(FI) SDL_Surface* get##FI(){return FI;} void load##FI(){FI=SDL_LoadBMP("./assets/"#FI".bmp");}

class Assets {
private:
    SDL_Surface* field;
    SDL_Surface* base;
    SDL_Surface* iron;
    SDL_Surface* ironmine;

    SDL_Texture* fieldtex;
    TTF_Font* font;
public:
    Assets(SDL_Renderer* ren);
    ~Assets();
    SDL_Surface* getNode(std::string str);

    getload(field);
    getload(base);
    getload(iron);
    getload(ironmine);

    SDL_Texture* getFieldTex();
    SDL_Texture* makeText(SDL_Renderer* ren, const char* c);

    SDL_Texture* tex(SDL_Surface* s, SDL_Renderer* ren, int lvl);
    SDL_Texture* rtex(SDL_Surface* s, SDL_Renderer* ren, int contain);
protected:
    
    void pixelset(int x, int y, Uint32 color, SDL_Surface* surface);
    Uint32 pixelget(int x, int y, SDL_Surface* surface);
};

