#include "game.hpp"

Game::Game() : screen_height(32), screen_width(64)
{
    for (int x = 0; x < 400; x++)
    {
        elements[x] = new Grid_Element();
    }
    w = SDL_CreateWindow("CSE Tactics",
                         SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED,
                         screen_width * PIXEL_SIZE,
                         screen_height * PIXEL_SIZE,
                         SDL_WINDOW_SHOWN);
    SDL_Delay(1000);
    if (w == nullptr)
    {
        std::cerr << "Could not create SDL_Window instance!";
        return;
    }
    r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    if (r == nullptr)
    {
        std::cerr << "Could not create SDL_Renderer instance!";
        SDL_DestroyWindow(w);
        return;
    }
    return;
}

void Game::drawpx(uint16_t x, uint16_t y, SDL_Color &c)
{
    x %= screen_width;
    y %= screen_height;
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);

    SDL_Rect pixel_rect = {
        PIXEL_SIZE * x,
        PIXEL_SIZE * y,
        PIXEL_SIZE,
        PIXEL_SIZE};
    SDL_RenderFillRect(r, &pixel_rect);
}

Game::~Game()
{
    for (int x = 0; x < 400; x++)
    {
        delete elements[x];
    }
}
