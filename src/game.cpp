#include "game.hpp"

Game::Game() : shouldexit(false)
{
    // We have to guess where the asset folder is

    // This indicates that this is being run from a build folder in the source code folder
    if (std::filesystem::exists("../contrib/assets/assets.json"))
    {
        std::filesystem::current_path("../contrib/assets");
    }
    else
    {

        // Same as last, but not in a build folder
        if (std::filesystem::exists("./contrib/assets/assets.json"))
        {
            std::filesystem::current_path("./contrib/assets");
        }
        else
        {

            // Indicates the executable is with the build assets, like it would be in a windows build
            if (std::filesystem::exists("./assets.json"))
            {
                std::filesystem::current_path("./");
            }
            else
            {
                // Installed with a package manager in a unix system
                if (std::filesystem::exists("/usr/share/cse-tactics/assets.json"))
                {
                    std::filesystem::current_path("/usr/share/cse-tactics");
                }
                else
                {
                    // Couldn't find the assets
                    std::cerr << "Could not find a valid asset folder" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    // Open the asset file
    std::ifstream asset_file("assets.json", std::ios::binary);

    // String
    std::stringstream filestream;

    // Make sure it was actually opened
    if (!asset_file.is_open())
    {
        std::cerr << "Error opening asset file. Maybe the assets are not installed." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read out entire file
    filestream << asset_file.rdbuf();

    // Parse the file
    assets = nlohmann::json::parse(filestream.str());
    asset_file.close();
}

Game::~Game()
{
    SDL_Quit();
}
