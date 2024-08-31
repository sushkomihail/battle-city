#include "Tank.h"
#include "World.h"
#include "Projectile.h"

using namespace std;

Tank::Tank(const TankType type, const TankColor color, Input *input): DynamicObject({OBJECT_SIZE}) {
    view = new TankView(type, color, this);
    this->input = input;

    const auto collider = new Collider(getBase(), 52, 64);
    collider->initDimensionalPoints(OBJECT_SIZE);
    setCollider(collider);
    addChildPoint(collider->getLeftTop());
    addChildPoint(collider->getRightBottom());

    localProjectileSocket = sf::Vector2i(OBJECT_SIZE / 2, 16);
    addChildPoint(&localProjectileSocket);

    for (sf::Vector2i &point : getCollider()->getDimensionalPoints()) {
        addChildPoint(&point);
    }
}

void Tank::update(World *world, Map *map, const float deltaTime) {
    move(map, deltaTime);

    if (input->canShoot()) {
        shoot(world);
    }

    // for (Projectile *projectile : world->getProjectiles()) {
    //     projectile->update(world, map, deltaTime);
    // }
}

void Tank::move(const Map *map, const float deltaTime) {
    const sf::Vector2i *axes = input->getMovementAxes();

    if (axes->x != 0) {
        rotateToDirection(axes->x > 0 ? RIGHT : LEFT);
    }
    else if (axes->y != 0) {
        rotateToDirection(axes->y > 0 ? DOWN : UP);
    }
    else {
        setFramesCounter(0);
        return;
    }

    // sf::Vector2i &position = getPosition();
    // const sf::Vector2i newPosition = position + *axes * 2;


    if (!getCollider()->hasCollision(*map)) {
        DynamicObject::move(pxPerFrames, frames);
    }

    view->setTexture(axes);
}

void Tank::shoot(World *world) const {
    // if (world->getProjectiles().size() < maxProjectilesInWorldCount) {
    //     const auto projectile = new Projectile(projectileSpeed, getDirection());
    //
    //     sf::Vector2i worldProjectileSocket(
    //         localProjectileSocket.x + getPosition().x,
    //         localProjectileSocket.y + getPosition().y
    //         );
    //     worldProjectileSocket -= *projectile->getSpawnSocket();
    //
    //     projectile->getPosition().x += worldProjectileSocket.x;
    //     projectile->getPosition().y += worldProjectileSocket.y;
    //
    //     world->getProjectiles().push_back(projectile);
    // }
}

