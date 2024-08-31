#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../Engine/Objects/DynamicObject.h"
#include "../Engine/Direction.h"
#include "../Utils/ResourcesLoader.h"

class Projectile final : public DynamicObject {
public:
    Projectile(int speed, Direction direction);

    const sf::Vector2i *getSpawnSocket() const;

    void onCollision(const Map *map, const sf::Vector2i *position) override;
    void update(World *world, Map *map, float deltaTime) override;

private:
    static constexpr int OBJECT_SIZE = 16;
    static constexpr int COLLIDER_WIDTH = 12;
    static constexpr int COLLIDER_HEIGHT = 16;
    inline static const std::string SPRITE_SHEET = "res/SpriteSheets/Projectile.png";

    inline static std::unordered_map<Direction, sf::Texture*> textures {
            {UP, ResourcesLoader::loadTexture(SPRITE_SHEET, 0, 0, OBJECT_SIZE, OBJECT_SIZE)},
            {DOWN, ResourcesLoader::loadTexture(SPRITE_SHEET, 32, 0, OBJECT_SIZE, OBJECT_SIZE)},
            {LEFT, ResourcesLoader::loadTexture(SPRITE_SHEET, 16, 0, OBJECT_SIZE, OBJECT_SIZE)},
            {RIGHT, ResourcesLoader::loadTexture(SPRITE_SHEET, 48, 0, OBJECT_SIZE, OBJECT_SIZE)},
        };

    sf::Vector2i *spawnSocket = new sf::Vector2i(OBJECT_SIZE / 2, OBJECT_SIZE);
    int speed;

    void initializeCollider();
};

#endif
