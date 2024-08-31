#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include <iostream>
#include <unordered_map>
#include <Graphics/Sprite.hpp>

#include "Object.h"
#include "../../Game/TileLocation.h"

template<typename T>
class CompositeObject : public Object {
public:
    explicit CompositeObject(const std::vector<TileLocation> &tileLocations): Object(OBJECT_SIZE) {
        initTiles(tileLocations);
        initCollider();
    }

    ~CompositeObject() override {
        for (const auto &[cell, tile] : tiles) {
            delete tile;
        }
    }

    void render(sf::RenderWindow &window) const override {
        for (const auto &[cell, tile] : tiles) {
            try {
                sf::Sprite sprite(tile->getTexture());
                sprite.setPosition(cell.x * TILE_SIZE + getPosition().x, cell.y * TILE_SIZE + getPosition().y);
                window.draw(sprite);
            } catch (const std::exception& exception) {
                std::cout << exception.what() << std::endl;
            }

        }
    }

private:
    static constexpr int OBJECT_SIZE = 64;
    static constexpr int TILE_SIZE = 32;

    std::unordered_map<sf::Vector2i, T*> tiles;

    static void trySetColliderPointCoordValue(int &leftTopCoord, int &rightBottomCoord, const int value) {
        if (leftTopCoord > value) {
            leftTopCoord = value;
        } else if (rightBottomCoord < value + 1) {
            rightBottomCoord = value + 1;
        }
    }

    void initTiles(const std::vector<TileLocation> &tileLocations) {
        for (const TileLocation &location : tileLocations) {
            switch (location) {
                case LEFT_TOP:
                    tiles.emplace(sf::Vector2i(0, 0), new T);
                    break;
                case LEFT_BOTTOM:
                    tiles.emplace(sf::Vector2i(0, 1), new T);
                    break;
                case RIGHT_TOP:
                    tiles.emplace(sf::Vector2i(1, 0), new T);
                    break;
                case RIGHT_BOTTOM:
                    tiles.emplace(sf::Vector2i(1, 1), new T);
                    break;
            }
        }
    }

    void initCollider() {
        const auto leftTop = new sf::Vector2i(tiles.begin()->first.x, tiles.begin()->first.y);
        const auto rightBottom = new sf::Vector2i(tiles.begin()->first.x + 1, tiles.begin()->first.y + 1);

        for (const auto &[cell, tile] : tiles) {
            trySetColliderPointCoordValue(leftTop->x, rightBottom->x, cell.x);
            trySetColliderPointCoordValue(leftTop->y, rightBottom->y, cell.y);
        }

        leftTop->x *= TILE_SIZE;
        leftTop->y *= TILE_SIZE;
        rightBottom->x *= TILE_SIZE;
        rightBottom->y *= TILE_SIZE;
        setCollider(new Collider(getBase(), leftTop, rightBottom));
    }
};

#endif //COMPOSITEOBJECT_H
