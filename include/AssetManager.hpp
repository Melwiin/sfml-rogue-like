#pragma once

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
    AssetManager() { }
    ~AssetManager() { }

    void loadTexture(const std::string& name, const std::string& fileName);
    sf::Texture& getTexture(const std::string& name);

    void loadFont(const std::string& name, const std::string& fileName);
    sf::Font& getFont(const std::string& name);

private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
};
