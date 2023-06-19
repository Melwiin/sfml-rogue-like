#pragma once

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::RectangleShape shape;
public:
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }
};