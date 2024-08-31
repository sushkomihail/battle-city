#include "Collider.h"

#include <iostream>

#include "Objects/Object.h"
#include "../Game/Brick/Brick.h"
#include "Objects/DynamicObject.h"

Collider::Collider(Object *owner, const int width, const int height): leftTop(nullptr), rightBottom(nullptr) {
    this->owner = owner;
    this->width = width;
    this->height = height;
}

Collider::Collider(Object *owner, sf::Vector2i *leftTop, sf::Vector2i *rightBottom): width(0), height(0) {
    this->owner = owner;
    this->leftTop = leftTop;
    this->rightBottom = rightBottom;
}

Collider::~Collider() {
    delete owner;
}

Object *Collider::getOwner() const {
    return owner;
}

int &Collider::getWidth() {
    return width;
}

int &Collider::getHeight() {
    return height;
}

sf::Vector2i *Collider::getLeftTop() const {
    return leftTop;
}

sf::Vector2i *Collider::getRightBottom() const {
    return rightBottom;
}

// std::pair<int, int> Collider::getWorldPosition() {
//     const auto &[xLocal, yLocal] = localPosition;
//     const math::Vector2 *position = object->getPosition();
//     return {xLocal + position->x, yLocal + position->y};
// }

std::vector<sf::Vector2i> &Collider::getDimensionalPoints() {
    return dimensionalPoints;
}

void Collider::initDimensionalPoints(const int objectSize) {
    const int leftTopX = (objectSize - width) / 2;
    const int leftTopY = (objectSize - height) / 2;

    leftTop = new sf::Vector2i(leftTopX, leftTopY);
    rightBottom = new sf::Vector2i(leftTopX + width, leftTopY + height);

    dimensionalPoints.push_back(sf::Vector2i(leftTopX, leftTopY));
    dimensionalPoints.push_back(sf::Vector2i(leftTopX + width, leftTopY));
}

void Collider::updateOrientation() const {
    const int minX = std::min(leftTop->x, rightBottom->x);
    const int maxX = std::max(leftTop->x, rightBottom->x);
    const int minY = std::min(leftTop->y, rightBottom->y);
    const int maxY = std::max(leftTop->y, rightBottom->y);
    *leftTop = sf::Vector2i(minX, minY);
    *rightBottom = sf::Vector2i(maxX, maxY);
}

bool Collider::isIntersectsWith(const Collider &collider) const {
    const sf::Vector2i worldleftTop = *leftTop + owner->getPosition();
    const sf::Vector2i worldRigthBottom = *rightBottom + owner->getPosition();

    const sf::Vector2i otherWorldLeftTop = *collider.getLeftTop() + collider.getOwner()->getPosition();
    const sf::Vector2i otherWorldRightBottom = *collider.getRightBottom() + collider.getOwner()->getPosition();

    return
        worldleftTop.x <= otherWorldRightBottom.x &&
        worldRigthBottom.x >= otherWorldLeftTop.x &&
        worldleftTop.y <= otherWorldRightBottom.y &&
        worldRigthBottom.y >= otherWorldLeftTop.y;
}

bool Collider::hasCollision(const Map &map) const {
    const sf::Vector2i worldLeftTop = *leftTop + owner->getPosition();
    const sf::Vector2i worldRightBottom = *rightBottom + owner->getPosition();

    // if (worldLeftTop.x <= 0 || worldRightBottom.x >= Map::WIDTH || worldLeftTop.y <= 0 || worldRightBottom.y >= Map::HEIGHT) {
    //     return true;
    // }

    const sf::Vector2i leftTopCell = map.getCellOfPosition(worldLeftTop);
    const sf::Vector2i rightBottomCell = map.getCellOfPosition(worldRightBottom);

    auto condition = [&] (const sf::Vector2i &objectPosition) {
        const auto dynamicObject = dynamic_cast<DynamicObject*>(owner);

        if (dynamicObject == nullptr) {
            throw std::runtime_error("Collider's owner is not of type 'DynamicObject'!");
        }

        switch (dynamicObject->getDirection()) {
            case UP:
                return objectPosition.y < owner->getPosition().y;
            case DOWN:
                return objectPosition.y > owner->getPosition().y;
            case LEFT:
                return objectPosition.x < owner->getPosition().x;
            case RIGHT:
                return objectPosition.x > owner->getPosition().x;
            default:
                return false;
        }
    };
    const std::vector<Object*> objectsInArea = map.getObjectsInArea(leftTopCell, rightBottomCell, condition);
    // std::cout << objectsInArea.size() << std::endl;

    for (const Object *object : objectsInArea) {
        if (object->getCollider() != nullptr) {
            if (isIntersectsWith(*object->getCollider())) {
                return true;
            }
        }
    }

    return false;
}
