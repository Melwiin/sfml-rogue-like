#include "TestGameState.hpp"

TestGameState::TestGameState(GameDataRef data) : m_data(data) {}

void TestGameState::init() {

    m_player = m_entityManager.createEntity<Player>(m_entityManager);

    m_data->camera.setSize(m_data->window.getSize().x, m_data->window.getSize().y);

    // Init background
    m_data->assetManager.loadTexture("background", "assets/prototype-texture.png");
    m_background.setTexture(m_data->assetManager.getTexture("background"));
    m_background.setTextureRect(sf::IntRect(0, 0, m_data->window.getSize().x, m_data->window.getSize().y));
    m_background.setPosition(0, 0);
}

void TestGameState::handleEvents() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // get position of mouse relative to window and view
        const sf::Vector2f mousePosition = m_data->window.mapPixelToCoords(sf::Mouse::getPosition(m_data->window), m_data->camera);
        m_enemies.push_back(m_entityManager.createEntity<Enemy>(mousePosition.x, mousePosition.y));
    }
}

void TestGameState::update(float dt) {
    m_entityManager.updateEntities(dt);
    sf::Vector2f targetPosition = m_player->getPosition();

    float transitionSpeed = 5.0f;
    sf::Vector2f positionDifference = targetPosition - m_data->camera.getCenter();
    sf::Vector2f interpolatedPosition = m_data->camera.getCenter() + (positionDifference * dt * transitionSpeed);

    m_data->camera.setCenter(interpolatedPosition);
}

void TestGameState::render() {

    m_data->window.setView(m_data->camera);
    m_data->window.clear();

    m_data->window.draw(m_background);
    
    m_entityManager.renderEntities(m_data->window);

    m_data->window.display();
}