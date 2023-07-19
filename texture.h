#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

class Texture {
public:
    Texture(SDL_Renderer* rend)
    {
        texture = NULL;
        width = 0;
        height = 0;
        renderer = rend;
    }

    ~Texture()
    {
        free();
    }

    void free()
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }

    void loadFromFile(char* path)
    {
        free();

        SDL_Surface* surface = IMG_Load(path);
        if (surface == NULL) {
            std::cout << "Image " << path << " not found";
        }
        width = surface->w;
        height = surface->h;
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == NULL) {
            std::cout << SDL_GetError() << "\n";
        }

        SDL_FreeSurface(surface);
    }

    void render(int x, int y, SDL_Rect* src_rect = NULL)
    {
        SDL_Rect dst_rect = { x, y, width, height };
        if (src_rect != NULL) {
            dst_rect.w = src_rect->w;
            dst_rect.h = src_rect->h;
        }

        if (SDL_RenderCopy(renderer, texture, src_rect, &dst_rect) != 0) {
            std::cout << SDL_GetError() << "\n";
        }
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    SDL_Texture* getTexture()
    {
        return texture;
    }

private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Renderer* renderer;
};

#endif
