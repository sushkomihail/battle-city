#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Projectile.h"

class World {
public:
    std::vector<Projectile*>& getProjectiles();

private:
    std::vector<Projectile*> projectiles;
};

#endif
