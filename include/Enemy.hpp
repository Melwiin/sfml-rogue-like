#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Enemy : public Entity {
private:
    int hp; // Health Points
    sf::RectangleShape hpBar; // HP Bar

public:
    Enemy(float x, float y)
        : hp(120)
    {
        shape.setSize(sf::Vector2f(40.0f, 40.0f));
        shape.setPosition(x, y);
        
        // HP Bar setup
        hpBar.setSize(sf::Vector2f(40.0f, 5.0f));
        hpBar.setPosition(x, y - 10.0f);
        hpBar.setFillColor(sf::Color::Red);
    }

    void update(float deltaTime) override {
        // Update logic for enemy
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(shape);
        window.draw(hpBar);
    }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0)
            hp = 0;
        
        float hpRatio = static_cast<float>(hp) / 120;
        sf::Vector2f hpBarSize(shape.getSize().x * hpRatio, hpBar.getSize().y);
        hpBar.setSize(hpBarSize);
    }
};
