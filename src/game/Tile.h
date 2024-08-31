#ifndef TILE_H
#define TILE_H

#include <Graphics/Texture.hpp>

class Tile {
public:
    explicit Tile(sf::Texture *texture);
    ~Tile();

    const sf::Texture &getTexture() const;

    void setTexture(sf::Texture *texture);

private:
    sf::Texture *texture;
};

#endif //TILE_H
