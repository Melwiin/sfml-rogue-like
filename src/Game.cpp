#include "Game.hpp"

#include "SplashScreenState.hpp"
#include "TestGameState.hpp"

Game::Game(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    m_data->stateManager.pushState(StateRef(new TestGameState(m_data)));

    this->run();
}

void Game::run()
{
    sf::Clock clock;
    float deltaTime;

    while (m_data->window.isOpen())
    {
        sf::Event event;
        while (m_data->window.pollEvent(event))
            if (sf::Event::Closed == event.type) m_data->window.close();
        
        m_data->stateManager.processStateChanges();

        m_data->stateManager.processStateChanges();

        deltaTime = clock.restart().asSeconds();

        m_data->stateManager.getActiveState()->handleEvents();
        m_data->stateManager.getActiveState()->update(deltaTime);
        m_data->stateManager.getActiveState()->render();
    }
}