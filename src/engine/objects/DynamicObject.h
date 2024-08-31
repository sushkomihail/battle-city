#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "../Direction.h"
#include "Object.h"

class World;

class DynamicObject : public Object {
public:
    explicit DynamicObject(int size);
    ~DynamicObject() override;

    Direction getDirection() const;

    void setFramesCounter(int сount);

    void addChildPoint(sf::Vector2i *point);
    void move(int pxPerFrames, int updateFramesCount);
    void rotateToDirection(Direction direction);

    virtual void update(World *world, Map *map, float deltaTime) = 0;

private:
    inline static std::unordered_map<Direction, sf::Vector2i> directionAxes {
        {UP, {0, -1}}, {DOWN, {0, 1}}, {LEFT, {-1, 0}}, {RIGHT, {1, 0}}
    };
    inline static std::unordered_map<Direction, int> directionAngles {
        {UP, 0}, {DOWN, 180}, {LEFT, 90}, {RIGHT, -90}
    };

    std::vector<sf::Vector2i*> childPoints;
    Direction direction;
    int framesCounter;

    const sf::Vector2i &getDirectionAxes() const;
};

#endif
