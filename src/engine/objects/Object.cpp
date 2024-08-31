#include "Object.h"

#include <Graphics/Sprite.hpp>
#include <Graphics/Texture.hpp>

#include "../../Game/Map.h"

Object::Object(const int size) {
    this->size = size;
    position = new sf::Vector2i;
    collider = nullptr;
    texture = nullptr;
}

Object::~Object() {
    delete position;
    delete collider;
    delete texture;
}

const int & Object::getSize() const {
    return size;
}

sf::Texture &Object::getTexture() const {
    return *texture;
}

Collider *Object::getCollider() const {
    return collider;
}

sf::Vector2i &Object::getPosition() const {
    return *position;
}

void Object::setCollider(Collider *collider) {
    this->collider = collider;
}

void Object::setTexture(sf::Texture *textures) {
    this->texture = textures;
}

void Object::render(sf::RenderWindow &window) const {
    sf::Sprite sprite(*texture);
    sprite.setPosition(position->x, position->y);
    window.draw(sprite);
}

void Object::onCollision(const Map *map, const sf::Vector2i *collisionPosition) {
}

Object *Object::getBase() {
    return this;
}
