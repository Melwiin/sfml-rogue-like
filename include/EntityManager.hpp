#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

#include "Entity.hpp"


class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;

    int countByType(EntityEnumType type) {
        int count = 0;
        for (const auto& entity : entities) {
            if (entity->getType() == type) {
                count++;
            }
        }
        return count;
    }

public:
    template <typename EntityType, typename... Args>
    std::shared_ptr<EntityType> createEntity(EntityEnumType type, Args&&... args) {
        static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must be derived from Entity");

        std::shared_ptr<EntityType> entity = nullptr;
        entity = std::make_shared<EntityType>(std::forward<Args>(args)...);
        
        std::string typestring = "";
        switch (type) {
        case EntityEnumType::Player:
            typestring = "Player";
            break;
        case EntityEnumType::Enemy:
            typestring = "Enemy";
            break;
        case EntityEnumType::Projectile:
            typestring = "Projectile";
            break;
        default:
            typestring = "None";
            break;
        }
        std::string name = typestring + std::to_string(countByType(type));
        
        entity->setType(type);
        entity->setName(name);
        entities.push_back(entity);
        return entity;
    }

    std::shared_ptr<Entity> getByName(std::string name) {
        for (const auto& entity : entities) {
            if (entity->getName() == name) {
                return entity;
            }
        }
        return nullptr;
    }

    void updateEntities(float deltaTime) {
        for (const auto& entity : entities) {
            entity->update(deltaTime);
        }
    }

    void renderEntities(sf::RenderWindow& window) {
        for (const auto& entity : entities) {
            entity->render(window);
        }
    }

    void removeEntity(std::shared_ptr<Entity> entity) {
        auto it = std::find(entities.begin(), entities.end(), entity);
        if (it != entities.end()) {
            entities.erase(it);
        }
    }
};
