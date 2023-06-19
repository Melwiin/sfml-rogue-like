#pragma once

#include "State.hpp"
#include "Game.hpp"

class MainMenuState : public State {
public:
    MainMenuState(GameDataRef data);

    void init();

    void handleEvents();
    void update(float dt);
    void render();
private:
    GameDataRef m_data;
};