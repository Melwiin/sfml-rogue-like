#pragma once

#include <cmath>

#include "Entity.hpp"
#include "EntityManager.hpp"
#include "Projectile.hpp"

static bool spacebarPressed = false; // Static variable to track spacebar state

class Player : public Entity
{
public:
    Player(EntityManager* entityManager)
        : entityManager(entityManager)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(sf::Vector2f(100, 100));
    }

    void update(float deltaTime) override
    {
        // Movement speed of the player
        float movementSpeed = 400.0f;

        // Get the current keyboard state
        bool isMoveUpKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool isMoveDownKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool isMoveLeftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        bool isMoveRightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

        // Calculate the movement direction based on the keyboard state
        sf::Vector2f movementDirection;
        if (isMoveUpKeyPressed)
            movementDirection.y -= 1.0f;
        if (isMoveDownKeyPressed)
            movementDirection.y += 1.0f;
        if (isMoveLeftKeyPressed)
            movementDirection.x -= 1.0f;
        if (isMoveRightKeyPressed)
            movementDirection.x += 1.0f;

        // Normalize the movement direction if needed
        if (movementDirection != sf::Vector2f(0.0f, 0.0f))
            movementDirection = movementDirection / std::sqrt(movementDirection.x * movementDirection.x + movementDirection.y * movementDirection.y);

        // Calculate the movement amount based on the movement direction and speed
        sf::Vector2f movementAmount = movementDirection * movementSpeed * deltaTime;
        shape.move(movementAmount);

        if (!spacebarPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            spacebarPressed = true; // Spacebar pressed, set the flag
            sf::Vector2f projectilePosition = shape.getPosition() - sf::Vector2f(20, 20);
            sf::Vector2f projectileDirection(0.0f, -1.0f);
            float projectileSpeed = 500.0f; 

            auto entity = entityManager->createEntity<Projectile>(projectilePosition, projectileDirection, projectileSpeed);
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            spacebarPressed = false; // Spacebar released, reset the flag
        }
    }

    void render(sf::RenderWindow &window) const override
    {
        window.draw(shape);
    }

private:
    EntityManager* entityManager;
};