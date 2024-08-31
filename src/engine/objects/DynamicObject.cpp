#include "DynamicObject.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

DynamicObject::DynamicObject(const int size) : Object(size) {
    direction = UP;
    framesCounter = 0;
}

DynamicObject::~DynamicObject() {
    for (const sf::Vector2i *point : childPoints) {
        delete point;
    }
}

Direction DynamicObject::getDirection() const {
    return direction;
}

void DynamicObject::setFramesCounter(const int сount) {
    framesCounter = сount;
}

void DynamicObject::addChildPoint(sf::Vector2i *point) {
    childPoints.push_back(point);
}

void DynamicObject::move(const int pxPerFrames, const int updateFramesCount) {
    framesCounter++;

    if (framesCounter % updateFramesCount == 0) {
        framesCounter = 0;
    }

    if (framesCounter > pxPerFrames) {
        return;
    }

    sf::Vector2i &position = getPosition();
    const sf::Vector2i nextPosition = position + getDirectionAxes() * 2;
    position = nextPosition;
}

void DynamicObject::rotateToDirection(const Direction direction) {
    if (this->direction == direction) {
        return;
    }

    const int angle = directionAngles.at(direction) - directionAngles.at(this->direction);
    const float angleInRadians = angle * M_PI / 180;
    const int sin = std::sin(angleInRadians);
    const int cos = std::cos(angleInRadians);
    const int halfSize = getSize() / 2;

    for (sf::Vector2i *point : childPoints) {
        const int xRelativeToOrigin = point->x - halfSize;
        const int yRelativeToOrigin = point->y - halfSize;

        point->x = xRelativeToOrigin * cos + yRelativeToOrigin * sin;
        point->y = yRelativeToOrigin * cos - xRelativeToOrigin * sin;

        point->x += halfSize;
        point->y += halfSize;
    }

    getCollider()->updateOrientation();
    this->direction = direction;
}

const sf::Vector2i &DynamicObject::getDirectionAxes() const {
    return directionAxes.at(direction);
}
