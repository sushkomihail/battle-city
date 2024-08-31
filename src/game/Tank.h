#ifndef TANK_H
#define TANK_H

#include "../Engine/Objects/DynamicObject.h"
#include "TankView.h"
#include "Input.h"

class Tank final : public DynamicObject {
public:
    Tank(TankType type, TankColor color, Input *input);

    void update(World *world, Map *map, float deltaTime) override;

private:
    static constexpr int OBJECT_SIZE = 64;

    TankView *view;
    Input *input;

    int pxPerFrames = 3;
    int frames = 4;

    sf::Vector2i localProjectileSocket;
    int projectileSpeed = 300;
    int maxProjectilesInWorldCount = 1;

    void move(const Map *map, float deltaTime);
    void shoot(World *world) const;
};

#endif
