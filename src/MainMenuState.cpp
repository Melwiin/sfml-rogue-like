#include "MainMenuState.hpp"

MainMenuState::MainMenuState(GameDataRef data) : m_data(data) { }

void MainMenuState::init() {
   
}

void MainMenuState::handleEvents() {
    sf::Event event;

    while (m_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            m_data->window.close();
        }
    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::render() {
    m_data->window.clear(sf::Color::Green);

    m_data->window.display();
}