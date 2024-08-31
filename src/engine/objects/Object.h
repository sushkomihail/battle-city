#ifndef OBJECT_H
#define OBJECT_H

#include <Graphics/RenderWindow.hpp>

#include "../Collider.h"

class Collider;

class Object {
public:
    explicit Object(int size);
    virtual ~Object();

    const int &getSize() const;
    sf::Vector2i &getPosition() const;
    Collider *getCollider() const;
    sf::Texture &getTexture() const;

    void setCollider(Collider *collider);
    void setTexture(sf::Texture *textures);

    virtual void render(sf::RenderWindow &window) const;
    virtual void onCollision(const Map *map, const sf::Vector2i *collisionPosition);

protected:
    Object *getBase();

private:
    int size;
    sf::Vector2i *position;
    Collider *collider;
    sf::Texture *texture;
};

#endif
