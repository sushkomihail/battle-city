#ifndef COLLIDER_H
#define COLLIDER_H

#include "../Game/Map.h"

class Map;
class Object;

class Collider {
public:
    Collider(Object *owner, int width, int height);
    Collider(Object *owner, sf::Vector2i *leftTop, sf::Vector2i *rightBottom);

    ~Collider();

    // ~Collider();

    Object *getOwner() const;
    int &getWidth();
    int &getHeight();
    sf::Vector2i *getLeftTop() const;
    sf::Vector2i *getRightBottom() const;
    std::vector<sf::Vector2i> &getDimensionalPoints();

    // math::Vector2& getWorldPosition();

    void initDimensionalPoints(int objectSize);
    void updateOrientation() const;
    bool isIntersectsWith(const Collider &collider) const;
    bool hasCollision(const Map &map) const;

private:
    Object *owner;
    int width;
    int height;
    sf::Vector2i *leftTop;
    sf::Vector2i *rightBottom;
    std::vector<sf::Vector2i> dimensionalPoints;

    // int getDistanceToObstacle(const Object *obstacle, MoveDirection direction) const;
};

#endif
