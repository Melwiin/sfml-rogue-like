#pragma once

#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "EntityManager.hpp"

class TestGameState : public State {
public:
    TestGameState(GameDataRef data);

    void init();

    void handleEvents();
    void update(float dt);
    void render();
private:
    GameDataRef m_data;
    EntityManager m_entityManager;

    std::shared_ptr<Player> m_player;

    sf::Sprite m_background;

    std::vector<std::shared_ptr<Entity>> m_enemies;
};