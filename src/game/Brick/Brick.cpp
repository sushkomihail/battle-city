#include "Brick.h"
#include "../Projectile.h"

Brick::Brick(const std::vector<TileLocation> &tileLocations) : CompositeObject(tileLocations) {
}

void Brick::destruct(const sf::Vector2i &contactPosition) {
    // const sf::Vector2i contactLocalPosition(contactPosition.x - getPosition()->x, contactPosition.y - getPosition()->y);
    // const int cellX = contactLocalPosition.x / 16;
    // const int cellY = contactLocalPosition.y / 16;
    // stateSum -= state[cellY][cellX];
    // state[cellY][cellX] = 0;
    // setTexture(texture.at(stateSum));
}

bool Brick::isDestructedAtPosition(const sf::Vector2i *position) {
    // const sf::Vector2i localPosition(position->x - getPosition()->x, position->y - getPosition()->y);
    // const int cellX = localPosition.x / 16;
    // const int cellY = localPosition.y / 16;
    // return state[cellY][cellX] == 0;
    return false;
}
