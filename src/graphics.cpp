#include "graphics.hpp"
#include "game_instance.hpp"

Graphics::Graphics() : screen_height(480), screen_width(720)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Could not initialise" << std::endl;
        exit(EXIT_FAILURE);
    }
    w = SDL_CreateWindow("CSE Tactics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width * PIXEL_SIZE,
                         screen_height * PIXEL_SIZE, SDL_WINDOW_SHOWN);
    SDL_Delay(1000);
    if (w == nullptr)
    {
        std::cerr << "Could not create SDL_Window instance!" << std::endl;
        exit(EXIT_FAILURE);
    }
    r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    if (r == nullptr)
    {
        std::cerr << "Could not create SDL_Renderer instance!" << std::endl;
        SDL_DestroyWindow(w);
        exit(EXIT_FAILURE);
    }
    return;
}

Graphics::~Graphics()
{
}

void Graphics::drawtext(const std::string &str)
{
}

void Graphics::drawpx(uint16_t x, uint16_t y, const SDL_Color &c)
{
    SDL_Rect pixel_rect;
    x %= screen_width;
    y %= screen_height;
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);

    pixel_rect = {PIXEL_SIZE * x, PIXEL_SIZE * y, PIXEL_SIZE, PIXEL_SIZE};
    SDL_RenderFillRect(r, &pixel_rect);
    SDL_RenderPresent(r);
}

void Graphics::drawelement(Grid_Element &element)
{
}
