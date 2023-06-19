#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Entity.hpp"

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;

public:
    template <typename EntityType, typename... Args>
    std::shared_ptr<EntityType> createEntity(Args&&... args) {
        static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must be derived from Entity");

        auto entity = std::make_shared<EntityType>(std::forward<Args>(args)...);
        entities.push_back(entity);
        return entity;
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
