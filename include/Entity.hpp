#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class EntityEnumType {
    Player,
    Enemy,
    Projectile,
    None
};

class Entity {
protected:
    sf::RectangleShape shape;
    std::string name;
    EntityEnumType type;
public:
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;
    const std::string & getName() const {
         return this->name;
    }
    void setName(const std::string & name) {
        this->name = name;
    }

    const EntityEnumType & getType() const {
        return this->type;
    }

    void setType(const EntityEnumType & type) {
        this->type = type;
    }

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }
};