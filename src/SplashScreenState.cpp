#include "SplashScreenState.hpp"
#include "MainMenuState.hpp"

SplashScreenState::SplashScreenState(GameDataRef data) : m_data(data) { }

void SplashScreenState::init() {
   
}

void SplashScreenState::handleEvents() {
    sf::Event event;

    while (m_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            m_data->window.close();
        }
    }
}

void SplashScreenState::update(float dt) {
    m_elapsed += dt;

    if (m_elapsed > 8.0f) {
        m_data->stateManager.pushState(StateRef(new MainMenuState(m_data)), true);
    }
}

void SplashScreenState::render() {
    m_data->window.clear(sf::Color::Red);

    m_data->window.display();
}