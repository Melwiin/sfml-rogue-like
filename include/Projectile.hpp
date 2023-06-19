#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Projectile : public Entity
{
public:
    Projectile(const sf::Vector2f& position, const sf::Vector2f& direction, float speed)
        : direction(direction), speed(speed)
    {
        shape.setSize(sf::Vector2f(10, 10));
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(position);
    }

    void update(float deltaTime) override
    {
        sf::Vector2f movementAmount = direction * speed * deltaTime;
        shape.move(movementAmount);
    }

    void render(sf::RenderWindow& window) const override
    {
        window.draw(shape);
    }

private:
    sf::Vector2f direction;
    float speed;
};

