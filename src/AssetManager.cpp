#include "AssetManager.hpp"

void AssetManager::loadTexture(const std::string& name, const std::string& fileName) {
    sf::Texture texture;

    if (texture.loadFromFile(fileName)) {
        m_textures[name] = texture;
    }
}

sf::Texture& AssetManager::getTexture(const std::string& name) {
    return m_textures.at(name);
}

void AssetManager::loadFont(const std::string& name, const std::string& fileName) {
    sf::Font font;

    if (font.loadFromFile(fileName)) {
        m_fonts[name] = font;
    }
}

sf::Font& AssetManager::getFont(const std::string& name) {
    return m_fonts.at(name);
}