#pragma once

#include "State.hpp"
#include "Game.hpp"

class SplashScreenState : public State {
public:
    SplashScreenState(GameDataRef data);

    void init();

    void handleEvents();
    void update(float dt);
    void render();
private:
    GameDataRef m_data;

    float m_elapsed;
};