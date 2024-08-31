#include "Projectile.h"
#include "World.h"

#include <cmath>
#include <iostream>

#include "Brick/Brick.h"
#include "IDestructible.h"

class DynamicObject;
using namespace std;

Projectile::Projectile(const int speed, const Direction direction): DynamicObject(OBJECT_SIZE) {
    this->speed = speed;

    addChildPoint(spawnSocket);
    initializeCollider();
    rotateToDirection(direction);

    setTexture(textures.at(direction));
}

const sf::Vector2i *Projectile::getSpawnSocket() const {
    return spawnSocket;
}

void Projectile::onCollision(const Map *map, const sf::Vector2i *position) {
    DynamicObject::onCollision(map, position);

    for (const sf::Vector2i *point : getCollider()->getDimensionalPoints()) {
        const int worldX = point->x + position->x;
        const int worldY = point->y + position->y;

        sf::Vector2i cellCoords = map->getCellCoordsOfPosition(sf::Vector2i(worldX, worldY));
        Object *obstacle = map->getObjectByCellCoords(cellCoords);
        const auto destructible = dynamic_cast<Brick*>(obstacle);

        if (destructible != nullptr) {
            destructible->destruct(sf::Vector2i(worldX, worldY));
        }
    }
}

void Projectile::update(World *world, Map *map, const float deltaTime) {
    sf::Vector2i position = getPosition();
    const sf::Vector2i nextPosition =
        position + getDirectionAxes(getDirection()) * static_cast<int>(floor(static_cast<float>(speed) * deltaTime));

    if (getCollider()->hasCollision(map, &nextPosition)) {
        const auto it = find(world->getProjectiles().begin(), world->getProjectiles().end(), this);
        world->getProjectiles().erase(it);
        // delete this;
    }
    else {
        *position = nextPosition;
    }
}

void Projectile::initializeCollider() {
    const auto collider = new Collider(getBase(), 16, 16);
    collider->initializeDimensionalPoints(OBJECT_SIZE);
    setCollider(collider);

    for (sf::Vector2i *point : getCollider()->getDimensionalPoints()) {
        addChildPoint(point);
    }
}
