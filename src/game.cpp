#include "game.hpp"

Game::Game() : shouldexit(false)
{
    assets = nlohmann::json::parse(R"({"happy": true, "pi": 3.141})");
}

Game::~Game()
{
    SDL_Quit();
}
