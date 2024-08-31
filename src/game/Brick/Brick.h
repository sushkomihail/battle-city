#ifndef BRICK_H
#define BRICK_H

#include "../../Engine/Objects/CompositeObject.h"
#include "BrickTile.h"
#include "../IDestructible.h"
#include "../../Utils/ResourcesLoader.h"

class Brick final : public CompositeObject<BrickTile>, IDestructible {
public:
    Brick(const std::vector<TileLocation> &tileLocations);

    // void onCollision(const Map *map, const sf::Vector2i *collisionPosition) override;
    void destruct(const sf::Vector2i &contactPosition) override;
    bool isDestructedAtPosition(const sf::Vector2i *position) override;
};

#endif
