#include "Tile.h"

Tile::Tile(sf::Texture *texture) {
    setTexture(texture);
}

Tile::~Tile() {
    delete texture;
}

const sf::Texture &Tile::getTexture() const {
    return *texture;
}

void Tile::setTexture(sf::Texture *texture) {
    this->texture = texture;
}
