#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"


struct GameData
{
    sf::View camera;
    sf::RenderWindow window;
    StateManager stateManager;
    AssetManager assetManager;
    InputManager inputManager;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
    Game(int width, int height, std::string title);

private:
    const float dt = 1.0f / 60.0f;
    sf::Clock m_clock;

    GameDataRef m_data = std::make_shared<GameData>();

    void run();
};

